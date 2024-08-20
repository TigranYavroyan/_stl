#include <header.hpp>
//------------------------------------------- task 1 -----------------------------------------------------
// template <int N>
// struct Xn {
//     static constexpr unsigned long long val = (7 * Xn<N - 1>::val - 2 * Xn<N - 2>::val - 3 * Xn<N - 3>::val + 4);
// };

// template <>
// struct Xn<0> {
//     static constexpr unsigned long long val = 0;
// };

// template <>
// struct Xn<1> {
//     static constexpr unsigned long long val = 1;
// };

// template <>
// struct Xn<2> {
//     static constexpr unsigned long long val = 2;
// };

// int main () {
//     std::cout << Xn<17>::val << std::endl;
//     std::cout << Xn<50>::val << std::endl;
//     std::cout << Xn<3500>::val << std::endl; // using flag -ftemplate-depth=3500
// }
//------------------------------------------- task 1 -----------------------------------------------------
//------------------------------------------- task 2 -----------------------------------------------------
// class A {};

// class B {};

// class C {};

// class chlp {};

// class D : public A, public chlp {};

// template <typename T>
// typename std::enable_if<!(std::is_base_of<A, T>::value && std::is_base_of<B, T>::value) &&
// !(std::is_base_of<A, T>::value && std::is_base_of<C, T>::value) &&
// !(std::is_base_of<C, T>::value && std::is_base_of<B, T>::value), void>::type 
// foo (T obj) {
//     std::cout << typeid(obj).name() << std::endl;
// }

// template <typename T>
// requires (!(std::is_base_of<A, T>::value && std::is_base_of<B, T>::value) &&
// !(std::is_base_of<A, T>::value && std::is_base_of<C, T>::value) &&
// !(std::is_base_of<C, T>::value && std::is_base_of<B, T>::value))
// void foo (T obj) {
//     std::cout << "ek sti" << std::endl;
// }

// template <typename T>
// concept once_based = (!(std::is_same<T, A>::value || std::is_same<T, B>::value || std::is_same<T, C>::value) &&
// (std::is_base_of<C, T>::value && !(std::is_base_of<A, T>::value && std::is_base_of<B, T>::value)) ||
// (std::is_base_of<B, T>::value && !(std::is_base_of<A, T>::value && std::is_base_of<C, T>::value)) ||
// (std::is_base_of<A, T>::value && !(std::is_base_of<C, T>::value && std::is_base_of<B, T>::value)));

// template <once_based T>
// void foo (T obj) {
//     std::cout << typeid(obj).name() << std::endl;
// }

// int main () {
//     A obj;
//     B obj2;
//     C obj3;
//     D obj4;

//     foo (obj4);
// }
//------------------------------------------- task 2 -----------------------------------------------------
//------------------------------------------- task 3 ----------------------------------------------------

class Base {
public:
    virtual void foo () {}
    virtual ~Base() = default;
};

class Derived {};


template <typename T>
constexpr bool is_polymorphic_impl(T* ptr) {
    return dynamic_cast<void*>(ptr) != nullptr;
}

template <typename T>
constexpr bool is_polymorphic() {
    T* ptr = nullptr;

    return is_polymorphic_impl(ptr);
}

int main () {
    std::cout << is_polymorphic<Base>() << std::endl;
}


