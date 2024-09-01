#ifndef CTORS_HPP
#define CTORS_HPP

template <typename T, typename Alloc>
my_deque<T, Alloc>::my_deque () = default;

template <typename T, typename Alloc>
my_deque<T, Alloc>::my_deque (size_type count, const_reference value) {
	left_size = count / 2;
	right_size = count - left_size;
	left = allocator.allocate(left_size);
	right = allocator.allocate(right_size);

	iterator it_begin = begin();
	iterator it_end = end();

	while (it_begin != it_end) { // doesn't work
		*it_begin = value;
		++it_begin;
	}
}

#endif // CTORS_HPP