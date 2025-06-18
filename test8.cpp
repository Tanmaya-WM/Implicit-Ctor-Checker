// test8.cpp
class MyClass {
public:
    MyClass() {}
    MyClass(MyClass&&) {}
};

MyClass make() {
    return MyClass(); // Move constructor may be used
}

int main() {
    MyClass obj = make(); // May trigger move or copy constructor
    return 0;
}

