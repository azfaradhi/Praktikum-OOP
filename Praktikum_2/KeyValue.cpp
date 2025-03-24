#include <iostream>
#include <math.h>
using namespace std;
template<class A, class B>
class KeyValue{
private:
    A key[10];
    B value[10];
    int nEff;
    const int maxSize = 10;

public:

    // ctor
    KeyValue(): nEff(0){}

    //dtor
    ~KeyValue(){}

    //method
    void set(A k, B v){
        if (nEff == 10){
            cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
            return;
        }
        for (int i=0; i< nEff; i++){
            if (this->key[i] == k){
                this->value[i] = v;
                return;
            }
        }
        this->key[nEff] = k;
        this->value[nEff] = v;
        nEff++;
    }

    void display(A k){
        for (int i=0; i< nEff; i++){
            if (this->key[i] == k){
                cout << this->value[i] << endl;
                return;
            }
        }
        cout << "Key tidak ditemukan!" << endl;
    }

};

template<class B>
class KeyValue<double,B>{
private:
    double key[10];
    B value[10];
    int nEff;
    const int maxSize = 10;

public:

    // ctor
    KeyValue(): nEff(0){}

    //dtor
    ~KeyValue(){}

    //method
    void set(double k, B v){
        if (nEff == 10){
            cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
            return;
        }
        for (int i=0; i< nEff; i++){
            if (abs(this->key[i]-k) < 0.01){
                this->value[i] = v;
                return;
            }
        }
        this->key[nEff] = k;
        this->value[nEff] = v;
        nEff++;
    }

    void display(double k){
        for (int i=0; i< nEff; i++){
            if (abs(this->key[i]-k) < 0.01){
                cout << this->value[i] << endl;
                return;
            }
        }
        cout << "Key tidak ditemukan!" << endl;
    }

};

// int main(){
// KeyValue<double, string> kv;
// kv.set(1.1, "Alice");
// kv.set(2.1, "Bob");
// kv.set(3.1, "Charlie");
// kv.display(1.1001); // Output: "Alice"
// kv.display(2); // Output: "Bob"
// kv.display(3); // Output: "Charlie"
// kv.set(3,"RADHI");
// kv.display(3);
// kv.display(4);
// }