#ifndef INSERTION_HPP
#define INSERTION_HPP

template <typename T, typename Alloc>
void my_deque<T, Alloc>::_add_to_front (pointer* ptr, size_type& size, value_type& val) {
    pointer tmp;
    size_type new_size = size + 1;

    new_size = size + 1;
    _alloc(&tmp, new_size);
    tmp[0] = val;
    for (int j = 0, i = 1; j < size; ++i, ++j) {
        tmp[i] = (*ptr)[j];
    }

    _dealloc(ptr, size);
    *ptr = tmp;
    size = new_size;
}

template <typename T, typename Alloc>
void my_deque<T, Alloc>::_push (pointer* ptr, size_type& size, const_reference val) {
    if (size == 0) {
        ++size;
        _alloc(ptr, size);
        *ptr[0] = val;
    }
    else {
        pointer tmp;
        size_type new_size = size + 1;
        _alloc(&tmp, new_size);

        for (int i = 0; i < size; ++i) {
            tmp[i] = (*ptr)[i];
        }
        tmp[size] = val; // std::construct_at;
        _dealloc(ptr, size);

        *ptr = tmp;
        size = new_size;
    }
}

template <typename T, typename Alloc>
void my_deque<T, Alloc>::push_back (const_reference val) {
    _push(&right, right_size, val);
    _balance();
}

template <typename T, typename Alloc>
void my_deque<T, Alloc>::push_front (const_reference val) {
    _push(&left, left_size, val);
    _balance();
}

#endif // INSERTION_HPP