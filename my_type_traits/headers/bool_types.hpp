#ifndef BOOL_TYPES_HPP
#define BOOL_TYPES_HPP

template <bool val>
using bool_const = integral_const<bool, val>;

template <bool val>
static constexpr bool bool_const_v = bool_const<val>::value;

using true_type = integral_const<bool, true>;
using false_type = integral_const<bool, false>;

#endif // BOOL_TYPES_HPP