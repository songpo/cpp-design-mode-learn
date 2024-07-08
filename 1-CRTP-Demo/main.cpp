#include <iostream>

template <typename Derived>
struct SomeBase {
    void foo() {
        for (auto& item : *static_cast<Derived*>(this)) {
            item.
        }
    }
};

struct MyClass : SomeBase<MyClass> {
    class iterator {
        // your iterator define here
    };

    iterator begin() const {};
    iterator end() const {};
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    return 0;
}
