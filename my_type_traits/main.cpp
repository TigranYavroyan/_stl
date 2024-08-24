#include <tt_header.hpp>

using namespace chlp;

class A { // integral type class
public:
    A () = default;
    A (int a) {}
    operator int() {
        return 67;
    }
};

class B {
public:
    B() = delete;
    B(const B&) = delete;
    
    B(const A&) {}
    virtual void foo () {}
};

int main () {
    B ob(0);
    std::cout << std::boolalpha << is_integral_v<A> << std::endl;
    std::cout << std::boolalpha << is_integral_v<float> << std::endl;
    // const volatile int a = 10;
    // chlp::add_const_t<decltype(a)> c = 20;
    // decltype(a) b = 15;
    // chlp::remove_cv_t<decltype(a)> b = 15;
    // b = 20;
    // c = 30;
    // std::cout << std::boolalpha << is_integral_v<int> << std::endl;
    // std::cout << std::boolalpha << is_rvalue_ref_v<int&> << std::endl;
    // std::cout << std::boolalpha << is_array_v<int> << std::endl;
    // std::cout << typeid(conditional_t<false, int, double>).name() << std::endl;
    std::cout << std::boolalpha << is_polymorphic_v<B> << std::endl;
    // std::cout << dynamic_cast<void*>(&ob) << std::endl;
}