#ifndef IS_SAME_HPP
#define IS_SAME_HPP

template <typename T, typename U>
struct is_same : false_type {};

template <typename T>
struct is_same<T, T> : true_type {};

template <typename T, typename U>
static constexpr bool is_same_v = is_same<T, U>::value;

template <typename T, typename U, typename... Ts>
struct is_same_all : bool_const<is_same_v<T, U> && is_same_all<U, Ts...>::value> {};

template <typename T, typename U>
struct is_same_all<T, U> : bool_const<is_same_v<T, U>> {};

template <typename T, typename U, typename... Ts>
static constexpr bool is_same_all_v = is_same_all<T, U, Ts...>::value;

#endif // IS_SAME_HPP