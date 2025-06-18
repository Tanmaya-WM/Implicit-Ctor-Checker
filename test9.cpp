// test_simple.cpp
class MyClass {
public:
    MyClass() {}
    MyClass(const MyClass&) {}
};

void passByValue(MyClass x) {
    // Implicit copy constructor
}

int main() {
    MyClass a;         // Implicit default constructor
    MyClass b = a;     // Implicit copy constructor
    passByValue(a);    // Implicit copy constructor
    return 0;
}

