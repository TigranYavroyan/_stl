#ifndef MEMORY_HPP
#define MEMORY_HPP

template <typename T, typename Alloc>
void my_deque<T, Alloc>::_alloc (pointer* ptr, size_type size) {
    if (ptr)
        *ptr = allocator.allocate(size);
}

template <typename T, typename Alloc>
void my_deque<T, Alloc>::_dealloc (pointer* ptr, size_type size) {
    if (ptr)
        allocator.deallocate(*ptr, size);
}


#endif // MEMORY_HPP