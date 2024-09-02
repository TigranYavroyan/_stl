#ifndef INSERTION_HPP
#define INSERTION_HPP

template <typename T, typename Alloc>
void my_deque<T, Alloc>::push_back (const T& val) {
    int bf = _is_balanced();
    if (bf == 0) {
        
    }
}

template <typename T, typename Alloc>
void my_deque<T, Alloc>::push_front (const T& val) {
    
}

#endif // INSERTION_HPP