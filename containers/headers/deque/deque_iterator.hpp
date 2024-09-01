#ifndef DEQUE_ITERATOR_HPP
#define DEQUE_ITERATOR_HPP

template <typename T, typename Alloc>
my_deque<T, Alloc>::iterator my_deque<T, Alloc>::begin() const {
    return iterator(left + (left_size - 1), this);
}

template <typename T, typename Alloc>
my_deque<T, Alloc>::iterator my_deque<T, Alloc>::end() const {
    return iterator(right + right_size, this);
}

template <typename T, typename Alloc>
my_deque<T, Alloc>::const_iterator my_deque<T, Alloc>::cbegin() const {
    return const_iterator(left + (left_size - 1), this);
}

template <typename T, typename Alloc>
my_deque<T, Alloc>::const_iterator my_deque<T, Alloc>::cend() const {
    return const_iterator(right + right_size, this);
}


#endif // DEQUE_ITERATOR_HPP