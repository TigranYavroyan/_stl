#ifndef IS_CLASS_HPP
#define IS_CLASS_HPP

template <typename T>
struct is_class : bool_const<__is_class(T)> {};

template <typename T>
static constexpr bool is_class_v = is_class<T>::value;

#endif // IS_CLASS_HPP