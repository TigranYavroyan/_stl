#ifndef DELETION_HPP
#define DELETION_HPP

template <typename T, typename Alloc>
void my_deque<T, Alloc>::_remove_front (pointer* ptr, size_type& size) {
    pointer tmp;
    size_type new_size = size - 1;
    _alloc(&tmp, new_size);

    for (int j = 0, i = 1; i < size; ++i, ++j) {
        tmp[j] = (*ptr)[i];
    }

    _dealloc(ptr, size);
    *ptr = tmp;
    size = new_size;
}

template <typename T, typename Alloc>
void my_deque<T, Alloc>::_remove_back (pointer* ptr, size_type& size) {
    pointer tmp;
    size_type new_size = size - 1;

    _alloc(&tmp, new_size);

    for (int i = 0; i < new_size; ++i) {
        tmp[i] = (*ptr)[i];
    }

    _dealloc(ptr, size);
    *ptr = tmp;
    size = new_size;
}

template <typename T, typename Alloc>
void my_deque<T, Alloc>::clear () noexcept {
	_dealloc(&right, right_size);
	_dealloc(&left, left_size);
	left = nullptr;
	right = nullptr;
	left_size = 0;
	right_size = 0;
}

template <typename T, typename Alloc>
void my_deque<T, Alloc>::pop_back () {
    if (right_size == 0 && left_size == 0)
        return;
    else if (right_size == 0)
        _remove_front(&left, left_size);
    else
        _remove_back(&right, right_size);
}

template <typename T, typename Alloc>
void my_deque<T, Alloc>::pop_front () {
    if (right_size == 0 && left_size == 0)
        return;
    else if (left_size == 0)
        _remove_front(&right, right_size);
    else
        _remove_back(&left, left_size);
}

#endif // DELETION_HPP