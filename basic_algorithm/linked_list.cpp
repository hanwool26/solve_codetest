#include <iostream>
#include <string.h>

using namespace std;

typedef struct Word
{
	char Korean[100];
	char English[100];
	struct Word *Next;
}Word;

Word* AppendList(Word *p);
Word* InsertList(Word *p);
//void UpdateList(Word *p);
//Word* DeleteList(Word *p);
//void SearchList(Word* p);
int DisplayList(Word* p);
char MenuWord();

int main(void)
{
	Word* head = new Word; // c언어 형식의 동적 메모리 할당
	Word* tail = head;
	head->Next = NULL;
	while(1) 
	{
		switch (MenuWord())
		{
		case '1':
		tail = AppendList(tail);
		break;
		case '2':
		head = InsertList(head);
		break;
		/*
		case '3':
		UpdateList(head);
		break;
		case '4':
		head = DeleteList(head);
		break;
		case '5':
		SearchList(head);
		break;
		*/
		case '6':
		DisplayList(head);
		getchar(); break;
		case '0':
		return 0;
		default:
		cout << "Invalid" << endl;
		}	
	}
}

char MenuWord()
{
	char number;
	cout << "Menu" << endl;
	cin >> number;
	return number;
}

Word* AppendList(Word* p)
{
	cout << "input korean :";
	cin >> p->Korean;
	cout << "input English :";
	cin >> p->English;
	p->Next = new Word;
	p = p->Next;
	p->Next = NULL;
	return p;
}

int DisplayList(Word *p)
{
	int i=1;
	while(p->Next!=NULL)
	{
		cout << i++ << " " << p->Korean << " " << p->English << endl;
		p = p->Next;
	}
	return i-1;
}

Word* InsertList(Word* p)
{
	int pos, number;
	char Korean[100];
	char English[100];
	Word* item;
	Word* start = p;
	item = new Word;
	number = DisplayList(p);
	do{
		cout << "Select pos: " << endl;
		cin >> pos;
	}while(pos << 1 || pos>number);
	cout << "input Korean : ";
	cin >> Korean;
	strcpy(item->Korean, Korean);
	cout << "input English : ";
	cin >> English;
	strcpy(item->English, English);
		
	if(pos == 1)
	{
		item->Next = p;
		start = item;
	} else
	{
		int i;
		for(i=1; i<pos-1; i++)
		{
			p=p->Next;
		}
		item->Next = p->Next;
		p->Next = item;
	}
	return start;
}

