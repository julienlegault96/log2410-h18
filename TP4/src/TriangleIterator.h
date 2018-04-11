///////////////////////////////////////////////////////////
//  TriangleIterator.h
//  Implementation of the Class TriangleIterator
//  Created on:      12-mars-2018 22:00:28
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_F0C16EB1_B2AA_4071_9F1C_4CC9F4A39647__INCLUDED_)
#define EA_F0C16EB1_B2AA_4071_9F1C_4CC9F4A39647__INCLUDED_

#include <iterator>

#include "Triangle.h"


typedef std::vector<Triangle> TriangleContainer;

// Definition d'un iterateur sur des Objet3D constants
template <typename IterTy> class
TriangleIterator_impl : public std::iterator<std::random_access_iterator_tag, size_t>
{

public:
	TriangleIterator_impl<IterTy>(IterTy& it) : m_iter(it) {};
	TriangleIterator_impl<IterTy>(const TriangleIterator_impl<IterTy>& mdd) : m_iter(mdd.m_iter) {};

	operator IterTy() const { return m_iter; };
	const TriangleIterator_impl<IterTy>& operator++() { return ++m_iter; }
	TriangleIterator_impl<IterTy> operator++(int) { return m_iter++; }
	const TriangleIterator_impl<IterTy>& operator--() { return --m_iter; }
	TriangleIterator_impl<IterTy> operator--(int) { return m_iter--; }
	bool operator==(const TriangleIterator_impl<IterTy>& rhs) const { return m_iter == rhs.m_iter; }
	bool operator!=(const TriangleIterator_impl<IterTy>& rhs) const { return !(m_iter == rhs.m_iter); }
	const Triangle& operator*() const { return *m_iter; }
	const Triangle* operator->() const { return &*m_iter; }
	const TriangleIterator_impl<IterTy>& operator+=(size_t s) { return m_iter + s; }
	const TriangleIterator_impl<IterTy>& operator-=(size_t s) { return m_iter - s; }
	const Triangle& operator[](size_t idx) const { return m_iter[idx]; }

#if 0
	friend TriangleIterator_impl<IterTy> operator+(const TriangleIterator_impl<IterTy>&, size_t);
	friend iterator operator+(size_t, const iterator&);
	friend TriangleIterator_impl<IterTy> operator-(const TriangleIterator_impl<IterTy>&, size_t);
	friend difference_type operator-(TriangleIterator_impl<IterTy>, TriangleIterator_impl<IterTy>);
	friend void swap(TriangleIterator_impl<IterTy>& lhs, TriangleIterator_impl<IterTy>& rhs);
	friend bool operator==(const TriangleIterator_impl<IterTy>&, const TriangleIterator_impl<IterTy>&);
	friend bool operator!=(const TriangleIterator_impl<IterTy>&, const TriangleIterator_impl<IterTy>&);
	friend bool operator<(const TriangleIterator_impl<IterTy>&, const TriangleIterator_impl<IterTy>&);
	friend bool operator>(const TriangleIterator_impl<IterTy>&, const TriangleIterator_impl<IterTy>&);
	friend bool operator<=(const TriangleIterator_impl<IterTy>&, const TriangleIterator_impl<IterTy>&);
	friend bool operator>=(const TriangleIterator_impl<IterTy>&, const TriangleIterator_impl<IterTy>&);
#endif

private:
	IterTy m_iter;
};


// Definition d'un iterateur sur des Objet3D non-constants
template <typename IterTy> class
TriangleIterator_base : public std::iterator<std::random_access_iterator_tag, size_t>
{

public:
	TriangleIterator_base<IterTy>(TriangleContainer::iterator& it) : m_iter(it) {};
	TriangleIterator_base<IterTy>(const TriangleIterator_base<IterTy>& mdd) : m_iter(mdd.m_iter) {};

	operator TriangleContainer::iterator() const { return m_iter; };
	const TriangleIterator_base<IterTy>& operator++() { return ++m_iter; }
	TriangleIterator_base<IterTy> operator++(int) { return m_iter++; }
	const TriangleIterator_base<IterTy>& operator--() { return --m_iter; }
	TriangleIterator_base<IterTy> operator--(int) { return m_iter--; }
	bool operator==(const TriangleIterator_base<IterTy>& rhs) const { return m_iter == rhs.m_iter; }
	bool operator!=(const TriangleIterator_base<IterTy>& rhs) const { return !(m_iter == rhs.m_iter); }
	Triangle& operator*() { return *m_iter; }
	Triangle* operator->() { return &*m_iter; }
	const TriangleIterator_base<IterTy>& operator+=(size_t s) { return m_iter + s; }
	const TriangleIterator_base<IterTy>& operator-=(size_t s) { return m_iter - s; }
	const Triangle& operator[](size_t idx) const { return m_iter[idx]; }
	Triangle& operator[](size_t idx) { return m_iter[idx]; }

#if 0
	friend TriangleIterator operator+(const TriangleIterator&, size_t);
	friend iterator operator+(size_t, const iterator&);
	friend TriangleIterator operator-(const TriangleIterator&, size_t);
	friend difference_type operator-(TriangleIterator, TriangleIterator);
	friend void swap(TriangleIterator& lhs, TriangleIterator& rhs);
	friend bool operator==(const TriangleIterator&, const TriangleIterator&);
	friend bool operator!=(const TriangleIterator&, const TriangleIterator&);
	friend bool operator<(const TriangleIterator&, const TriangleIterator&);
	friend bool operator>(const TriangleIterator&, const TriangleIterator&);
	friend bool operator<=(const TriangleIterator&, const TriangleIterator&);
	friend bool operator>=(const TriangleIterator&, const TriangleIterator&);
#endif

private:
	IterTy m_iter;
};

typedef TriangleIterator_base<TriangleContainer::iterator> TriangleIterator;


typedef std::vector<Triangle> TriangleContainer;


#endif // !defined(EA_F0C16EB1_B2AA_4071_9F1C_4CC9F4A39647__INCLUDED_)
