#ifndef IS_ARRAY_HPP
#define IS_ARRAY_HPP

template <typename T>
struct is_array : false_type {};

template <typename T>
struct is_array<T[]> : true_type {};

template <typename T, int N>
struct is_array<T[N]> : true_type {};

template <typename T>
static constexpr bool is_array_v = is_array<T>::value;

#endif // IS_ARRAY_HPP