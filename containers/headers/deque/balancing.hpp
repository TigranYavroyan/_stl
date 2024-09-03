#ifndef BALANCING_HPP
#define BALANCING_HPP

template <typename T, typename Alloc>
void my_deque<T, Alloc>::_balance () {
    int bf = _is_balanced();
    if (bf == -1)
        _balance_left();
    else if (bf == 1)
        _balance_right();
}

template <typename T, typename Alloc>
int my_deque<T, Alloc>::_is_balanced () const {
    const int offset = 2;

    if (left_size - right_size == offset)
        return (-1);
    else if (right_size - left_size == offset)
        return (1);
    else
        return (0);
}

template <typename T, typename Alloc>
void my_deque<T, Alloc>::_balance_left () {
    value_type target = left[0];

    _remove_front(&left, left_size);
    _add_to_front(&left, left_size, target);
    
}

template <typename T, typename Alloc>
void my_deque<T, Alloc>::_balance_right () {
    value_type target = right[0];

    _remove_front(&right, right_size);
    _add_to_front(&right, right_size, target);
}

#endif // BALANCING_HPP