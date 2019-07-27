#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

template<class T>
class Queue
{
    public:
        Queue();
        ~Queue();
		Queue(const Queue& q);

		bool isEmpty();
		T& front();
		T& back();
        void push(T data);
        void pop();
		int size() const;
		void clear();

		Queue& operator =(const Queue &q);
    private:
        struct Node{
            T data;
            Node *next;
        };

        Node *frontPtr;
        Node *backPtr;
        int count;

};

template<class T>
Queue<T>::Queue(): frontPtr(NULL), backPtr(NULL), count(0)
{
}

template<class T>
Queue<T>::~Queue()
{
	while(!isEmpty()) pop();
}

template<class T>
void Queue<T>::clear()
{
	while(!isEmpty()) pop();
}

template<class T>
Queue<T>::Queue(const Queue & q) : frontPtr(NULL), backPtr(NULL), count(0)
{
	Node *it = q.frontPtr;
	while(it != NULL)
	{
		push(it->data);
		it = it->next;
	}
}

template<class T>
Queue<T>& Queue<T>::operator = (const Queue & q)
{
	clear();
	Node *it = q.frontPtr;
	while(it != NULL)
	{
		push(it->data);
		it = it->next;
	}
	return *this;
}

template<class T>
bool Queue<T>::isEmpty(){
    return(count == 0);
}

template<class T>
T& Queue<T>::front(){
    return frontPtr->data;
}

template<class T>
T& Queue<T>::back(){
    return backPtr->data;
}

template<class T>
int Queue<T>::size() const {
    return count;
}

template<class T>
void Queue<T>::push(T data){
    Node *newOne = new Node;
    newOne->data = data;
    newOne->next = NULL;
    if(isEmpty()){
        frontPtr = newOne;
    }
        else{
            backPtr->next = newOne;
        }
        backPtr = newOne;
        count++;
}

template<class T>
void Queue<T>::pop(){
    if(isEmpty()){
       std::cout << "Queue Error : Nothing inside" << std::endl; exit(0);
    }
        else{
            Node *temp = frontPtr;
            if(frontPtr == backPtr){
                frontPtr = NULL;
                backPtr = NULL;
            }
            else{
                frontPtr = frontPtr->next;
            }
            delete temp;
            count--;
        }
	}

#endif // QUEUE_H 