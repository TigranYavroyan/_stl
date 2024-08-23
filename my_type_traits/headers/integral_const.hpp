#ifndef INTEGRAL_CONST_HPP
#define INTEGRAL_CONST_HPP

template <typename T, T val>
struct integral_const {
    using type = T;
    static constexpr T value = val;
    
    operator T() {
        return value;
    }
    T operator ()() {
        return value;
    }
};

#endif // INTEGRAL_CONST_HPP