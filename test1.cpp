// test1.cpp
class MyClass {
public:
    MyClass() {}
    MyClass(const MyClass&) {}
};

int main() {
    MyClass a;          // Implicit default constructor
    MyClass b = a;      // Implicit copy constructor
    return 0;
}

