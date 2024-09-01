#ifndef MEMORY_HPP
#define MEMORY_HPP

template <typename T, typename Alloc>
void my_deque<T, Alloc>::clear () noexcept {
	allocator.deallocate(right, right_size);
	allocator.deallocate(left, left_size);
	left = nullptr;
	right = nullptr;
	left_size = 0;
	right_size = 0;
}

#endif // MEMORY_HPP