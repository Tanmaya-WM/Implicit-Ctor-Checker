// test4.cpp
class MyClass {
public:
    MyClass() {}
    MyClass(const MyClass&) {}
};

void foo(MyClass m) {}

int main() {
    MyClass obj;
    foo(obj); // Implicit copy constructor
    return 0;
}

