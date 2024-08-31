#ifndef DTOR_HPP
#define DTOR_HPP

template <typename T, typename Alloc>
my_deque<T, Alloc>::~my_deque () noexcept {
	this->clear();
}

#endif // DTOR_HPP