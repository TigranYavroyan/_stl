#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

template <bool N, typename T = void>
struct enable_if {};

template <typename T>
struct enable_if<true, T> { using type = T; };

template <bool N, typename T>
using enable_if_t = typename enable_if<N, T>::type;

#endif // ENABLE_IF_HPP