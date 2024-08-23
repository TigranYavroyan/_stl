#include <iostream>
#include <type_traits>
#include <ratio>

constexpr std::intmax_t num = 1000000000000000000000000;
constexpr std::intmax_t d = 1;

using yotta = std::ratio<num, d>;

template<typename X, typename Y>
using add = typename std::ratio_add<X, Y>::type;

template<typename X, typename Y>
using div = typename std::ratio_divide<X, Y>::type;

template<typename X, typename Y>
using mul = typename std::ratio_multiply<X, Y>::type;

template<typename X, typename Y>
using sub = typename std::ratio_subtract<X, Y>::type;

#define add(x, y) std::ratio_add<x, y>
#define div(x, y) std::ratio_divide<x, y>
#define mul(x, y) std::ratio_multiply<x, y>
#define sub(x, y) std::ratio_subtract<x, y>


using zero = std::ratio<0, 1>;
using one = std::ratio<1, 1>;
using two = std::ratio<2, 1>;
using three = std::ratio<3, 1>;
using four = std::ratio<4, 1>;
using seven = std::ratio<7, 1>;

template <int N>
struct Xn {
    yotta val = (sub(sub(mul(seven, Xn<N - 1>::val), mul(two, Xn<N - 2>::val)), add(mul(three, Xn<N - 3>::val), four)));
};

template <>
struct Xn<0> {
    zero val;
};

template <>
struct Xn<1> {
    one val;
};

template <>
struct Xn<2> {
    two val;
};

int main () {
    // std::cout << Xn<17>::val << std::endl;
    // std::cout << Xn<50>::val << std::endl;
    // std::cout << Xn<3500>::val << std::endl; // using flag -ftemplate-depth=3500
}