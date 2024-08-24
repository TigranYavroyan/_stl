#ifndef IS_POLYMORPHIC_HPP
#define IS_POLYMORPHIC_HPP

template <typename T>
concept polymorphic = requires (T ob) {
    dynamic_cast<void*>(&ob);
};

template <typename T>
struct is_polymorphic : false_type {};

template <polymorphic T>
struct is_polymorphic<T> : true_type {};


template <typename T>
static constexpr bool is_polymorphic_v = is_polymorphic<T>::value;

#endif // IS_POLYMORPHIC_HPP