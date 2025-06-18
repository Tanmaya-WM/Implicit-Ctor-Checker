// test7.cpp
class MyClass {
public:
    MyClass() {}
    MyClass(const MyClass&) {}
};

int main() {
    MyClass obj = MyClass(); // Temporary object copy constructor
    return 0;
}

