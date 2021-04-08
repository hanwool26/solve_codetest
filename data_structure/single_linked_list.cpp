#include <iostream>

using namespace std;

template<typename T>
struct Node
{
	public:
		T value;
		struct Node<T> *next = nullptr;
};

template <typename T>
class List{
	private:
		Node<T> *head;
		Node<T> *tail;
		int size = 0;
	public:
		List() : head(nullptr), tail(nullptr) {}
		~List() {}
		
		void AddNode(T _value)
		{
			Node<T> *node = new Node<T>;
			size++;
			node->value = _value;
			node->next = nullptr;
			
			if(head == nullptr)
			{
				head = node;
				tail = node;
			}
			else
			{
				tail->next = node;
				tail = tail->next;
			}
		}
		
		void RemoveNode(T _value)
		{
			Node<T> *ptr = head;
			Node<T> *tmp = ptr;
			
			while(ptr!=nullptr)
			{
				if(ptr->value == _value)
				{
					break;
				}
				else
				{
					tmp = ptr;
					ptr = ptr->next;
				}
			}
			if(ptr == nullptr) cout << "No member in node" << endl;
			else
			{
				size--;
				cout << "delete node : " << ptr->value << endl;
				tmp->next = ptr->next;
				delete ptr;
			}
		}
		
		void Show()
		{
			Node<T> *node = head;
			while(node != nullptr)
			{
				cout << node->value << "->";
				node = node->next;
			}
			cout << endl;
		}
		
		void DeleteList(){
			Node<T> *ptr = head;
			while(ptr!=nullptr)
			{
				head = ptr->next;
				delete ptr;
				ptr = head;
			}
			size = 0;
			cout << "list clear" << endl;
		}
		
		void RemoveTail()
		{
			Node<T> *ptr = head;
			Node<T> *tmp = new Node<T>;
			
			while(ptr->next!=nullptr){
				tmp = ptr;
				ptr = ptr->next;
			}
			
			size--;
			tail = tmp;
			tail->next = nullptr;
			delete ptr;
		}
		
		void RemoveHead()
		{
			Node<T> *ptr = head;
			Node<T> *tmp; 
			
			head = ptr->next;
			size--;
			delete ptr;
		}
		
		void AddHead(T _value)
		{
			Node<T> *node = new Node<T>;
			
			size++;
			node->next = head;
			node->value = _value;
			head = node; 
		}
		
		void AddPosition(int index, T _value)
		{
			if(size < index || 0 > index)
			{
				cout << "invalid value with index" << endl;
				return;
			}	
		
			Node<T> *ptr = head;
			Node<T> *tmp = ptr; 
			Node<T> *node = new Node<T>;
		
			for(int i=0; i<index; i++)
			{
				tmp = ptr;
				ptr = ptr->next;
			}
			tmp->next = node;
			node->value = _value;
			node->next = ptr;
			size++;
		}
		
		void SearchValue(T _value)
		{
			Node<T> *ptr = head;
			int index = 0;
			bool isFind = false;
			
			while(ptr != nullptr)
			{
				index++;
				if(ptr->value == _value)
				{
					cout << "value : " << _value << " index : " << index << endl;
					isFind = true;
					break;
				}
				ptr = ptr->next;
			}
			
			if(isFind == false)
			{
				cout << "no value in node" << endl;
			}
			
		}
		int Size()
		{
			return size;
		}	
};

int main(){
	List<int> l;
	l.AddNode(3);
	l.AddNode(6);
	l.AddNode(5);
	l.AddNode(1);
	l.AddNode(7);
	l.AddNode(4);
	l.Show();
	l.AddPosition(3,2);
	l.Show();
}
