#include <iostream>
#include <string>
using namespace std;

template <typename T, size_t N>
class Dynamic_Array {
    T* data;
    size_t size, capacity;
    
    void allocate_memory() { // O(n)
        capacity *= 2;
        T* temp = new T[capacity];
        
        for (size_t i {0}; i < size; i++)
            temp[i] = data[i];
            
        delete [] data;
        data = temp;
    }
public:
    Dynamic_Array() : size {0}, capacity {N} {
        data = new T[capacity];
    }
    
    Dynamic_Array(const T (&a)[N]) : size {N}, capacity {N} {
        data = new T[capacity];
        
        for (size_t i {0}; i < capacity; i++)
            data[i] = a[i];
    }
    
    void fill(const T& x) { // O(n)
        size = capacity;
        
        for (size_t i {0}; i < capacity; i++)
            data[i] = x;
    }
    
    void display() const { // O(n)
        for (size_t i {0}; i < size; i++)
            cout << data[i] << ' ';
        cout << endl;
    }
    
    void push(const T& v) { // O(1), sometimes O(1)
        if (size == capacity)
            allocate_memory();
            
        data[size++] = v;
    }
    
    void insert(const T& value, const size_t& index) { // O(n)
        if (size + 1 > capacity)
            allocate_memory();
            
        for (size_t i {++size}; i > index; i--) {
            data[i] = data[i - 1];
        }
        
        data[index] = value;
    }
    
    void remove(const size_t& index) {  // O(n)
        for (size_t i {index}; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        --size;
    }
    
    T pop() {
        return data[size--];
    }
    
    T& operator [](const size_t& index) {
        return data[index];
    }
    
    size_t get_size() const { return size; }
    size_t get_capacity() const { return capacity; }
    
    ~Dynamic_Array() {
        delete [] data;
    }
};

int main() {
    Dynamic_Array<int, 3> a { {1, 2, 3} };
    
    a.display();
    a.push(100);
    a.display();
    a.remove(0);
    a.display();
    
    return 0;
}