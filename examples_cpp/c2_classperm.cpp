#include <iostream>
using namespace std;

class AccessExample {
public:
    // Constructor
    AccessExample(int pubVar, int privVar, int protecVar)
        : publicVar(pubVar), privateVar(privVar), protectedVar(protecVar) {
            cout << "Constructor called, allocating memory" << endl;
        }

    int publicVar;
    
    void display_public() const {
        cout << "Public var: " << publicVar << endl;
    }

    void display_private() const {
        cout << "Private var: " << privateVar << endl;
    }

private:
    int privateVar;

protected:
    int protectedVar;
};

class AccessDerived : public AccessExample {
    public:
        // Constructor for derived class, passing values to the base class constructor
        AccessDerived(int pubVar, int privVar, int protecVar)
            : AccessExample(pubVar, privVar, protecVar) {
                cout << "Derived constructor called, allocating memory" << endl;
            }

        void display_protected() const {
            cout << "Protected var: " << protectedVar << endl;
        }
};

int main() {
    // Creating an object of AccessExample
    AccessExample obj1(0, 1, 2);
    obj1.display_public();  // Output: Public var: publ
    obj1.display_private(); // Output: Private var: priv

    // Creating an object of AccessDerived
    AccessDerived obj2(0, 1, 2);
    obj2.display_public();     // Output: Public var: publ_derived
    obj2.display_protected();  // Output: Protected var: protec_derived

    return 0;
}