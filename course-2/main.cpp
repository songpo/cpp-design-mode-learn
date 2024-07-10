#include <iostream>

template <typename T> : struct Mixin : T{

};

int main() {
    std::cout << "Hello, World!" << std::endl;

    return 0;
}
