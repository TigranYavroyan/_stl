#ifndef BALANCING_HPP
#define BALANCING_HPP

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

}

template <typename T, typename Alloc>
void my_deque<T, Alloc>::_balance_right () {
    
}

#endif // BALANCING_HPP