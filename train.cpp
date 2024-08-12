#include <header.hpp>

void foo (const int& ob) {
    std::cout << "lvalue ref" << std::endl;
}

void foo (int&& ob) {
    std::cout << "rvalue ref" << std::endl;
}

void g (auto&& ob) {
    foo(std::forward<decltype(ob)>(ob));
}

template <typename T>
void f (T&& ob) {
    foo(std::forward<T>(ob));
}

int main () {
    int a = 5;
    g(a);
    g(5);
    // f(a);
    // f(5);
}