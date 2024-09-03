#ifndef ITERATORS_HPP
#define ITERATORS_HPP

// ------------------------------------------ helpers ----------------------------------------------------------------

template <typename T, typename Alloc>
bool my_deque<T, Alloc>::base_iterator::_in_left (pointer _ptr) const {
	return (_ptr > container->left && _ptr < (container->left + container->left_size));
}

template <typename T, typename Alloc>
bool my_deque<T, Alloc>::base_iterator::_in_right (pointer _ptr) const {
	return (_ptr > container->right && _ptr < (container->right + container->right_size));
}

template <typename T, typename Alloc>
bool my_deque<T, Alloc>::base_iterator::_left_border (pointer _ptr) const {
	return (_ptr == this->container->left || _ptr == this->container->left + this->container->left_size);
}

template <typename T, typename Alloc>
bool my_deque<T, Alloc>::base_iterator::_right_border (pointer _ptr) const {
	return (_ptr == this->container->right || _ptr == this->container->right + this->container->right_size);
}

template <typename T, typename Alloc>
bool my_deque<T, Alloc>::base_iterator::_out_of_range (pointer _ptr) const {
	return !this->_in_left(this->_ptr) && !this->_in_right(this->_ptr);
}

//-------------------------------------- base_iterator ----------------------------------------------------------------------

template <typename T, typename Alloc>
my_deque<T, Alloc>::base_iterator::base_iterator (pointer _ptr, cont_pointer cont) : ptr(_ptr), container(cont) {}

template <typename T, typename Alloc>
bool my_deque<T, Alloc>::base_iterator::operator== (const base_iterator& other) const {
	return (other.ptr == ptr && container == other.container);
}

template <typename T, typename Alloc>
bool my_deque<T, Alloc>::base_iterator::operator!= (const base_iterator& other) const {
	return !(other.ptr == ptr && container == other.container);
}

template <typename T, typename Alloc>
typename my_deque<T, Alloc>::difference_type my_deque<T, Alloc>::base_iterator::operator- (const base_iterator& other) const {
	bool in_left_this = _in_left(this->ptr) || _left_border(this->ptr);
	bool in_left_other = _in_left(other.ptr) || _left_border(other.ptr);
	bool in_right_this = _in_right(this->ptr) || _right_border(this->ptr);
	bool in_right_other = _in_right(other.ptr) || _right_border(other.ptr);

	difference_type val;
	if (in_left_this && in_left_other)
		val = other.ptr - this->ptr;
	else if (in_right_this && in_right_other)
		val = this->ptr - other.ptr;
	else if (in_left_this && in_right_other)
		val = this->ptr - this->container->left + other.ptr - other.container->right + 1;
	else {
		val = this->ptr - this->container->right + other.ptr - other.container->left + 1;
		// std::cout << "this is the val: " << val << '\n';
	}
	return val;
}

//-------------------------------------- const_iterator ----------------------------------------------------------------------

template <typename T, typename Alloc>
my_deque<T, Alloc>::const_iterator::const_iterator (pointer _ptr, cont_pointer cont) : base_iterator(_ptr, cont) {}

template <typename T, typename Alloc>
my_deque<T, Alloc>::const_iterator::const_iterator (const const_iterator& other) : base_iterator(other.ptr, other.container) {}

template <typename T, typename Alloc>
my_deque<T, Alloc>::const_iterator::const_iterator (const_iterator&& other) : base_iterator(other.ptr, other.container) {
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

template <typename T, typename Alloc>
const my_deque<T, Alloc>::const_iterator& my_deque<T, Alloc>::const_iterator::operator++ () {
	if (this->_in_left(this->ptr))
		--(this->ptr);
	else if (this->ptr == this->container->left)
		this->ptr = this->container->right;
	else 
		++(this->ptr);

	return *this;
}

template <typename T, typename Alloc>
const my_deque<T, Alloc>::const_iterator my_deque<T, Alloc>::const_iterator::operator++ (value_type) {
	const_iterator ret = *this;
	++(*this);
	return ret;
}

template <typename T, typename Alloc>
const my_deque<T, Alloc>::const_iterator& my_deque<T, Alloc>::const_iterator::operator-- () {
	if (this->_in_right(this->ptr))
		--(this->ptr);
	else if (this->ptr == this->container->right)
		this->ptr = this->container->left;
	else
		++(this->ptr);

	return *this;
}

template <typename T, typename Alloc>
const my_deque<T, Alloc>::const_iterator my_deque<T, Alloc>::const_iterator::operator-- (value_type) {
	const_iterator ret = *this;
	--(*this);
	return ret;
}

//-------------------------------------- iterator ----------------------------------------------------------------------

template <typename T, typename Alloc>
my_deque<T, Alloc>::iterator::iterator (pointer _ptr, cont_pointer cont) : const_iterator(_ptr, cont) {}

template <typename T, typename Alloc>
my_deque<T, Alloc>::iterator::iterator (const iterator& other) : const_iterator(other.ptr, other.container) {}

template <typename T, typename Alloc>
my_deque<T, Alloc>::iterator::iterator (iterator&& other) : const_iterator(other.ptr, other.container) {
	other.ptr = nullptr;
	other.container = nullptr;
}

template <typename T, typename Alloc>
const my_deque<T, Alloc>::iterator& my_deque<T, Alloc>::iterator::operator= (const base_iterator& other) { // why base_iterator
	*(static_cast<my_deque<T, Alloc>::const_iterator*>(this)) = other;
	return (*this);
}

template <typename T, typename Alloc>
const my_deque<T, Alloc>::iterator& my_deque<T, Alloc>::iterator::operator= (base_iterator&& other) { // why base_iterator
	*(static_cast<my_deque<T, Alloc>::const_iterator*>(this)) = other;
	return (*this);
}

template <typename T, typename Alloc>
typename my_deque<T, Alloc>::reference my_deque<T, Alloc>::iterator::operator* () {
	return const_cast<my_deque<T, Alloc>::reference>((static_cast<my_deque<T, Alloc>::const_iterator*>(this)->operator*()));
}

template <typename T, typename Alloc>
typename my_deque<T, Alloc>::pointer my_deque<T, Alloc>::iterator::operator-> () {
	return const_cast<my_deque<T, Alloc>::pointer>((static_cast<my_deque<T, Alloc>::const_iterator*>(this)->operator->()));
}

#endif // ITERATORS_HPP