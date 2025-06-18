// test2.cpp
class MyClass {
public:
    MyClass() {}
    MyClass(const MyClass&) {}
};

MyClass create() {
    MyClass temp;
    return temp; // May trigger copy or move constructor
}

int main() {
    MyClass obj = create(); // Implicit constructor
    return 0;
}

