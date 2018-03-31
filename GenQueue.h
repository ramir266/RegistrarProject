#include "DoublyLinkedList.h"
#include <iostream>

using namespace std; 

template <class T>
class GenQueue
{
	private: 
		DoublyLinkedList<T> *list;

	public: 
		GenQueue();
		~GenQueue();

		//Adds T* to the back of the queue. Same as pushBack()
		void enqueue(T* d);

		//Add T* to the back of the queue. Same as enqueue()
		void pushBack(T* d);

		//Removes and returns T* from the front of the queue. Same as popFront()
		T* dequeue();

		//Removes and returns T* from the front of the queue. Same as dequeue().
		T* popFront();

		//Returns, but does not remove a T* from the front of the queue
		T* peekHead();

		//Returns the amount of elements in the queue
		unsigned int getSize();

		//Returns true if queue is empty and false if NOT true
		bool isEmpty();
};

template <class T>
GenQueue<T>::GenQueue()
{
	list = new DoublyLinkedList<T>();
}

template <class T>
GenQueue<T>::~GenQueue()
{
	delete list;
}

template <class T>
void GenQueue<T>::enqueue(T* d)
{
	list->insertBack(d);
}

template <class T>
void GenQueue<T>::pushBack(T* d)
{
	list->insertBack(T* d);
}

template <class T>
T* GenQueue<T>::dequeue()
{
	return list->removeFront();
}

template <class T>
T* GenQueue<T>::popFront()
{
	return list->removeFront();
}

template <class T>
T* GenQueue<T>::peekHead()
{
	return list->peekHead();
}

template <class T>
unsigned int GenQueue<T>::getSize()
{
	return list->getSize();
}

template <class T>
bool GenQueue::isEmpty()
{
	return (list->getSize() == 0);
}
