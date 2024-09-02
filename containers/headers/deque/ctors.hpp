#ifndef CTORS_HPP
#define CTORS_HPP

template <typename T, typename Alloc>
void my_deque<T, Alloc>::_init (size_type count) {
	left_size = count / 2;
	right_size = count - left_size;
	left = allocator.allocate(left_size);
	right = allocator.allocate(right_size);
}

template <typename T, typename Alloc>
my_deque<T, Alloc>::my_deque () : 
	left{nullptr},
	left_size{0},
	right{nullptr},
	right_size{0}
{}

template <typename T, typename Alloc>
my_deque<T, Alloc>::my_deque (size_type count, const_reference value) {
	_init(count);

	std::for_each(begin(), end(), [&value](T& curr){curr = value;});
}

template <typename T, typename Alloc>
my_deque<T, Alloc>::my_deque (const std::initializer_list<T>& list) {
	_init(list.size());

	iterator it = begin();

	for (auto& val : list) {
		*it = val;
		++it;
	}
}

template <typename T, typename Alloc>
my_deque<T, Alloc>::my_deque (const my_deque<T, Alloc>& other) :
	left_size{other.left_size},
	right_size{other.right_size}
{
	left = allocator.allocate(left_size);
	right = allocator.allocate(right_size);

	// std::copy(other.cbegin(), other.cend(), std::back_inserter(*this)); // now it is not supported

	const_iterator other_begin = other.cbegin();
	const_iterator other_end = other.cend();
	iterator this_begin = begin();
	while (other_begin != other_end) {
		*this_begin = *other_begin;
		++this_begin;
		++other_begin;
	}
}

template <typename T, typename Alloc>
my_deque<T, Alloc>::my_deque (my_deque<T, Alloc>&& other) : 
	left_size{other.left_size},
	right_size{other.right_size},
	left{other.left},
	right{other.right}
{
	other.left = nullptr;
	other.right = nullptr;
	other.left_size = 0;
	other.right_size = 0;
}

#endif // CTORS_HPP