#ifndef IS_REFERENCE_HPP
#define IS_REFERENCE_HPP

template <typename T>
struct is_lvalue_ref : false_type {};

template <typename T>
struct is_lvalue_ref<T&> : true_type {};

template <typename T>
static constexpr bool is_lvalue_ref_v = is_lvalue_ref<T>::value;



template <typename T>
struct is_rvalue_ref : false_type {};

template <typename T>
struct is_rvalue_ref<T&&> : true_type {};

template <typename T>
static constexpr bool is_rvalue_ref_v = is_rvalue_ref<T>::value;



template <typename T>
struct is_ref : false_type {};

template <typename T>
struct is_ref<T&> : true_type {};

template <typename T>
struct is_ref<T&&> : true_type {};

template <typename T>
static constexpr bool is_ref_v = is_ref<T>::value;

#endif // IS_REFERENCE_HPP