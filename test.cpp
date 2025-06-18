class MyClass {
public:
    MyClass() {}
    MyClass(int) {}
    MyClass(const MyClass&) {}
};

int main() {
    MyClass obj1;       // Implicit default constructor
    MyClass obj2(42);   // Implicit parameterized constructor
    MyClass obj3 = obj1; // Implicit copy constructor
}

