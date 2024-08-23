#ifndef CONDITIONAL_HPP
#define CONDITIONAL_HPP

template <bool N, typename T, typename U>
struct conditional { using type = T; };

template <typename T, typename U>
struct conditional<false, T, U> { using type = U; };

template <bool N, typename T, typename U>
using conditional_t = typename conditional<N, T, U>::type;

#endif // CONDITIONAL_HPP