#ifndef ADD_CONST_HPP
#define ADD_CONST_HPP

template <typename T>
struct add_const { using type = const T; };

template <typename T>
using add_const_t = typename add_const<T>::type;
// we don't need check for T being const or not, compiler handles it
// the same for adding references 

#endif // ADD_CONST_HPP