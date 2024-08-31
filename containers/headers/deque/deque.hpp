#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <vector>

template <typename T, typename Alloc = std::allocator<T>>
class my_deque {
public:
	using value_type = T;
	using allocator_type = Alloc;
	using size_type = std::size_t;
	using reference = T&;
	using const_reference = const T&;
	using pointer = T*;
	using const_pointer = const T*;
public:
	my_deque ();
	my_deque (size_type count, const_reference value);
	~my_deque () noexcept;
public:
	void clear () noexcept;
private:
	pointer left;
	pointer right;
	size_type left_size;
	size_type right_size;
	Alloc allocator;

	class base_iterator { // can add pointer to this
			friend my_deque<value_type, Alloc>;
		public:
			bool operator== (const base_iterator& other) const;
			bool operator!= (const base_iterator& other) const;
		protected:
			explicit base_iterator (const_pointer _ptr, const my_deque<value_type, Alloc>* const cont); // why explicit ?
		protected:
			pointer ptr;
			my_deque<value_type, Alloc>* container;
	};

	class const_iterator : base_iterator {
			friend my_deque<value_type, Alloc>;
		public:
			const_iterator (const const_iterator& other);
			const_iterator (const_iterator&& other);

			const const_iterator& operator= (const base_iterator& other);
			const const_iterator& operator= (base_iterator&& other);
			const_reference operator* () const;
			const_pointer operator-> () const;

			const const_iterator& operator++ ();
			const const_iterator operator++ (value_type);
			const const_iterator& operator-- ();
			const const_iterator operator-- (value_type);
		protected:
			explicit const_iterator(const_pointer _ptr, const my_deque<value_type, Alloc>* const cont);
	};

	class iterator : const_iterator {
			friend my_deque<value_type, Alloc>;
		public:
			iterator (const iterator& other);
			iterator (iterator&& other);

			const iterator& operator= (const base_iterator& other);
			const iterator& operator= (base_iterator&& other);

			reference operator* ();
			pointer operator-> ();
		protected:
			explicit iterator (const_pointer _ptr, const my_deque<value_type, Alloc>* const cont);
	};
};

#include "deque_header.hpp"

#endif // DEQUE_HPP