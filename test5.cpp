// test5.cpp
class MyClass {
public:
    MyClass() {}
};

struct Container {
    MyClass member; // Uses default constructor
};

int main() {
    Container c; // Implicit constructor call for member
    return 0;
}

