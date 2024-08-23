#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

template <typename T>
concept integral = requires (T ob, T* ptr, void f(T)) {
    ptr + ob;
    static_cast<char>(ob);
    f(0);
};

template <typename T>
struct is_integral : false_type {};

template <integral T>
struct is_integral<T> : true_type {};

template <typename T>
static constexpr bool is_integral_v = is_integral<T>::value;

#endif // IS_INTEGRAL_HPP