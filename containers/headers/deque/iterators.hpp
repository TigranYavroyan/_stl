#ifndef ITERATORS_HPP
#define ITERATORS_HPP

template <typename T, typename Alloc>
my_deque<T, Alloc>::base_iterator::base_iterator (const_pointer _ptr, const my_deque<value_type, Alloc>* const cont) : ptr(_ptr), container(cont) {}

template <typename T, typename Alloc>
bool my_deque<T, Alloc>::base_iterator::operator== (const base_iterator& other) const {
	return (other.ptr == ptr && container == other.container);
}

template <typename T, typename Alloc>
bool my_deque<T, Alloc>::base_iterator::operator!= (const base_iterator& other) const {
	return !(other.ptr == ptr && container == other.container);
}




template <typename T, typename Alloc>
my_deque<T, Alloc>::const_iterator::const_iterator (const_pointer _ptr, const my_deque<value_type, Alloc>* const cont) : base_iterator(_ptr, cont) {}

template <typename T, typename Alloc>
my_deque<T, Alloc>::const_iterator::const_iterator (const const_iterator& other) : const_iterator(other.ptr, other.container) {}

template <typename T, typename Alloc>
my_deque<T, Alloc>::const_iterator::const_iterator (const_iterator&& other) : const_iterator(other.ptr, other.container) {
	other.ptr = nullptr;
	other.container = nullptr;
}

template <typename T, typename Alloc>
const typename my_deque<T, Alloc>::const_iterator& my_deque<T, Alloc>::const_iterator::operator= (const base_iterator& other) {
	this->ptr = other.ptr;
	this->container = other.container;
	return *this;
}

template <typename T, typename Alloc>
const typename my_deque<T, Alloc>::const_iterator& my_deque<T, Alloc>::const_iterator::operator= (base_iterator&& other) {
	if (this->ptr != other.ptr) {
		this->ptr = other.ptr;
		this->container = other.container;
		other.ptr = nullptr;
		other.container = nullptr;
	}
	return *this;
}

template <typename T, typename Alloc>
typename my_deque<T, Alloc>::const_pointer my_deque<T, Alloc>::const_iterator::operator-> () const {
	return this->ptr;
}

template <typename T, typename Alloc>
typename my_deque<T, Alloc>::const_reference my_deque<T, Alloc>::const_iterator::operator* () const {
	return *(this->ptr);
}



#endif // ITERATORS_HPP