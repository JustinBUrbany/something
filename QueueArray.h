#ifndef QUEARRAY_H
#define QUEARRAY_H
#include "Array.h"

template<typename T>
class QueueA
{
public:
	QueueA(int size);
	QueueA(QueueA & copy);
	~QueueA();
	QueueA & operator=(QueueA & rhs);
	int Size();
	bool isEmpty();
	bool isFull();
	void Engueue(T data);
	T Dequeue();
	T & Front();

private:
	int m_current_position;
	int m_max_size;
	int m_max_position;
	int m_current_size;
	Array<T> m_queue;

};


#endif

template<typename T>
inline QueueA<T>::QueueA(int size) : m_max_size(size), m_current_size(0), m_current_position(0), m_max_position(0)
{
	m_queue.setLength(size);
}

template<typename T>
inline QueueA<T>::QueueA(QueueA & copy)
{
	*this = copy;
	return *this;
}

template<typename T>
inline QueueA<T>::~QueueA()
{
	m_max_size = 0;
	m_queue.setLength(0);
}

template<typename T>
inline QueueA<T> & QueueA<T>::operator=(QueueA & rhs)
{
	m_max_size = rhs.m_max_size;
	m_queue = rhs.m_queue;
}

template<typename T>
inline int QueueA<T>::Size()
{
	return m_current_size;
}

template<typename T>
inline bool QueueA<T>::isEmpty()
{

	return m_current_size==0;
}

template<typename T>
inline bool QueueA<T>::isFull()
{
	return m_current_size == m_max_size;
}

template<typename T>
inline void QueueA<T>::Engueue(T data)
{
	if (isFull())
		throw Exception("Queue is full");
	
	if (m_max_position == m_max_size)
	{
		m_max_position = 0;
	}
	
	m_queue[m_queue.getStartIndex() + m_max_position++] = data;
	m_current_size++;

	//m_queue[m_queue.getStartIndex()+m_current_size + 1] = data;
	//m_current_size++;
}

template<typename T>
inline T QueueA<T>::Dequeue()
{
	if (isEmpty())
		throw Exception("Queue is empty");

	if (m_current_position == m_max_size)
	{
		m_current_position = 0;
	}

	T temp = m_queue[m_queue.getStartIndex() + m_current_position++];

	m_current_size--;

	return temp;
}

template<typename T>
inline T & QueueA<T>::Front()
{
	if (isEmpty())
		throw Exception("Queue is empty");
	return m_queue[m_queue.getStartIndex() + m_current_position]; 
}
