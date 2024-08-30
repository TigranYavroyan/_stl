#ifndef MY_ALLOCATOR_HPP
#define MY_ALLOCATOR_HPP

template <typename T>
class Stack_alloc {
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using size_type = size_t;
public:
    Stack_alloc ();
    Stack_alloc (const Stack_alloc& other);
    ~Stack_alloc ();
public:
    T* allocate (size_type n);
    void deallocate (pointer p, size_type n);
private:
    static const size_type size = 100;
    value_type stack[size];
    pointer top;

    bool _out_of_range (pointer ptr) const;
};

template <typename T>
Stack_alloc<T>::Stack_alloc () : top{stack} {};

template <typename T>
Stack_alloc<T>::Stack_alloc (const Stack_alloc& other) {
    for (int i = 0; i < size; ++i) {
        stack[i] = other.stack[i];
    }
    top = stack;
}

template <typename T>
Stack_alloc<T>::~Stack_alloc () = default;

template <typename T>
T* Stack_alloc<T>::allocate (size_type n) {
    T* old_top = top;

    top += n;

    if (_out_of_range(top))
        throw std::out_of_range("No more memory");

    return old_top;
}

template <typename T>
void Stack_alloc<T>::deallocate (pointer p, size_type n) {
    top -= n;

    if (_out_of_range(top))
        throw std::out_of_range("Segmentation fault");
}

template <typename T>
bool Stack_alloc<T>::_out_of_range (pointer ptr) const {
    return (ptr < stack || ptr > stack + size);
}

#endif // MY_ALLOCATOR_HPP