#ifndef REMOVE_REF_HPP
#define REMOVE_REF_HPP

template <typename T>
struct remove_ref { using type = T; };

template <typename T>
struct remove_ref<T&> { using type = T; };

template <typename T>
struct remove_ref<T&&> { using type = T; };

template <typename T>
using remove_ref_t = typename remove_ref<T>::type;

#endif // REMOVE_REF_HPP