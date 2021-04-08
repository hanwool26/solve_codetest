#include <iostream>

using namespace std;


template <typename T>
struct Node
{
	T data;
	struct Node<T> *next;
};

template <typename T>
class Queue
{
	private:
		int size;
		Node<T> *rear, *front;
		
	public:
		Queue() : size(0), rear(nullptr), front(nullptr) {}
		~Queue() {}
		
		void Enqueue(T value)
		{
			Node<T> *node = new Node<T>;
			node->data = value;
			node->next = nullptr;
			
			if(isEmpty()){
				rear = front = node;
			}
			else
			{
				rear->next = node;
				rear = node;
			}
			size++;
		}
		
		T Dequeue()
		{
			if(isEmpty())
			{
				cout << "No data return" << endl;
				return 0;
			}
			
			T temp = front->data;	// front data; 
			Node<T> *frontnode = front;
			front = front->next;
			size--;
			
			delete frontnode;
			return temp;
		}
		
		bool isEmpty()
		{
			if(size==0) return true;
			return false;
		}
		
		int Size() 
		{ 
			return size;
		}
		
		T Peek()
		{
			return front->data;
		}
		
		void Print()
		{
			if(isEmpty()) return;
			Node<T> *frontnode = front;
			for(int i=0; i<size; i++)
			{
				cout << front->data << " ";
				front = front->next;
			}
			
			front = frontnode;
			cout << endl;
		}
};

int main(void)
{
	Queue<int> q;
	q.Enqueue(1);
	q.Enqueue(4);
	q.Enqueue(6);
	q.Enqueue(7);

	q.Print();	
	cout << q.Peek() << endl;
	q.Dequeue();
	q.Print();
}
