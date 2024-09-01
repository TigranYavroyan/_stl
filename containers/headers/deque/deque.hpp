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
	using cont_pointer = const my_deque<value_type, allocator_type>*;
private:
	pointer left;
	pointer right;
	size_type left_size;
	size_type right_size;
	allocator_type allocator;

	class base_iterator {
			friend my_deque<value_type, Alloc>;
		public:
			bool operator== (const base_iterator& other) const;
			bool operator!= (const base_iterator& other) const;
		protected:
			explicit base_iterator (pointer _ptr, cont_pointer cont);
		protected:
			pointer ptr;
			cont_pointer container;

			bool _out_of_range (pointer ptr) const;
			bool _in_left (pointer ptr) const;
			bool _in_right (pointer ptr) const;
	};
public:
	class const_iterator : public base_iterator {
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
			explicit const_iterator(pointer _ptr, cont_pointer cont);
	};

	class iterator : public const_iterator {
			friend my_deque<value_type, Alloc>;
		public:
			iterator (const iterator& other);
			iterator (iterator&& other);

			const iterator& operator= (const base_iterator& other);
			const iterator& operator= (base_iterator&& other);

			reference operator* ();
			pointer operator-> ();
		protected:
			explicit iterator (pointer _ptr, cont_pointer cont);
	};
public:
	const_iterator cbegin() const;
	const_iterator cend() const;
	iterator begin() const;
	iterator end() const;
public:
	my_deque ();
	my_deque (size_type count, const_reference value);
	~my_deque () noexcept;
public:
	void clear () noexcept;
};

#include "deque_header.hpp"

#endif // DEQUE_HPP