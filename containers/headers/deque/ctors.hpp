#ifndef CTORS_HPP
#define CTORS_HPP

template <typename T, typename Alloc>
void my_deque<T, Alloc>::_init (size_type count) {
	left_size = count / 2;
	right_size = count - left_size;
	_alloc(&left, left_size);
	_alloc(&right, right_size);
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
	left{nullptr},
	left_size{0},
	right{nullptr},
	right_size{0}
{
	std::copy(other.cbegin(), other.cend(), std::back_inserter(*this));
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