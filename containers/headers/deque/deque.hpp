#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <vector>

template <typename T, typename Alloc = std::allocator<T>>
class my_deque {
public:
	using value_type = T;
	using difference_type = std::ptrdiff_t;
	using size_type = std::size_t;
	using allocator_type = Alloc;
	using allocator_traits = std::allocator_traits<Alloc>;
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
private:
	// balancing
	int _is_balanced () const; // checking is offset 2
	void _balance_left ();
	void _balance_right ();
	void _balance();

	// helpers
	void _init (size_type count);
	void _dealloc (pointer* ptr, size_type size);
	void _alloc (pointer* ptr, size_type size);
	void _push(pointer* ptr, size_type& size, const_reference val);
	void _remove_front (pointer* ptr, size_type& size);
	void _add_to_front (pointer* ptr, size_type& size, value_type& val);
	void _remove_back (pointer* ptr, size_type& size);
private:
	class base_iterator : public std::iterator<std::random_access_iterator_tag, T> { // for support STL algorithms
			friend my_deque<value_type, Alloc>;
		public:
			bool operator== (const base_iterator& other) const;
			bool operator!= (const base_iterator& other) const;
			difference_type operator- (const base_iterator& other) const;
		public:
			explicit base_iterator (pointer _ptr, cont_pointer cont);
		protected:
			pointer ptr;
			cont_pointer container;

			bool _out_of_range (pointer _ptr) const;
			bool _in_left (pointer _ptr) const;
			bool _in_right (pointer _ptr) const;
			bool _left_border (pointer _ptr) const;
			bool _right_border (pointer _ptr) const;
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
	my_deque (size_type count, const_reference value = T());
	my_deque (const std::initializer_list<T>& list);
	my_deque (const my_deque<T, Alloc>& other);
	my_deque (my_deque<T, Alloc>&& other);
	~my_deque () noexcept;
public:
	void clear () noexcept;
	void push_back (const_reference val);
	void push_front (const_reference val);
	void pop_back ();
	void pop_front ();
};

#include "deque_header.hpp"

#endif // DEQUE_HPP