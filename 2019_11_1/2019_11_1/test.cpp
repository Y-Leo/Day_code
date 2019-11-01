//·´×ªÁ´±í
#include<iostream>
using namespace std;
#define NULL 0

struct Node
{
	char data;
	Node* next;
};


Node *create()
{
	Node* head = NULL;
	Node* rear = head;
	Node* p;
	char tmp;

	cout << "Please input positive integer or char '#' to stop" << endl;
	do{
		cin >> tmp;
		if (tmp != '#')
		{
			p = new Node;
			p->data = tmp;
			p->next = NULL;

			if (head == NULL)
			{
				head = p;
			}
			else
			{
				rear->next = p;
			}
			rear = p;
		}
	} while (tmp != '#');
	return head;
}

void print(Node* head)
{
	cout << "The current list is:" << endl;
	Node* p = head;
	if (head != NULL)
	{
		do{
			cout << p->data;
			//if (p->next)
			cout << "->";
			p = p->next;
		} while (p != NULL);
	}
	cout << "\r\n";
}

void reverse(Node* &head)
{
	if (head == NULL)
	{
		return;
	}

	Node* pre, *cur, *ne;
	pre = head;
	cur = head->next;
	while (cur)
	{
		ne = cur->next;
		cur->next = pre;
		pre = cur;
		cur = ne;
	}
	head->next = NULL;
	head = pre;
}

int main()
{
	Node* List = create();
	print(List);
	reverse(List);
	print(List);

	return 0;
}