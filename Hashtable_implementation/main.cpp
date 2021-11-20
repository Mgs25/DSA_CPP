#include <iostream>
#include <functional>

using namespace std;

struct Bucket {
    int key;
    int value;
};

class Hash_Table {
    Bucket** data;
    size_t size;
public:
    Hash_Table(size_t s) : size { s } {
        data = new Bucket* [size];
        
        // allocate
        for (size_t i {0}; i < size; i++) {
            data[i] = new Bucket {-1, -1};
        }
        
    }
    
    size_t Hash(const int& x) const {
        return x % size;
    }
    
    void insert(const int& k, const int& v) {
        size_t pos { Hash(k) };
        delete data[pos];
        data[pos] = new Bucket {k, v};
    }
    
    Bucket* get(const int& k) const {
        size_t pos { Hash(k) };
        return data[pos];
    }
    
    void keys() const {
        for (size_t i {0}; i < size; i++) {
            const int k = data[i]->key;
            if (k != -1) {
                cout << k << endl;
            }
        }
    }
    
    void values() const {
        for (size_t i {0}; i < size; i++) {
            const int v = data[i]->value;
            if (v != -1) {
                cout << v << endl;
            }
        }
    }
    
    void display() const {
        for (size_t i {0}; i < size; i++) {
            if (data[i]->key != -1 && data[i]->value != -1) {
                cout << "{ " << data[i]->key << " : " << data[i]->value << " }" << endl;
            }
        }
    }
    
    ~Hash_Table() {
        for (size_t i {0}; i < size; i++) {
            delete data[i];
        }
        delete [] data;
    }
};

int main() {
    Hash_Table h {1001};
    
    for (int i {0}; i < 1000; i++) {
        h.insert(i + 1, (i + 1)  * 100);
    }
    
    h.display();
    
    return 0;
}