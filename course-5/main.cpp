#include <iostream>

class Person
{
    int age;
public:
    int get_age() const { return age; }
    void set_age(int value) { age = value; }
};

class Person1
{
    int age_;
public:
    int get_age() const { return age_; }
    void set_age(int value) { age_ = value; }
//    __declspec(property(get = get_age, put = set_age)) int age;
};

class Person2
{
    int _age;
public:
    int age() const { return _age; }
    void age(int value) { _age = value; }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Person p1;
    p1.age_ = 20; // calls p.set_age(20)

    return 0;
}
