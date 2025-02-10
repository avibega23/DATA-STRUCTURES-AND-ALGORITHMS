#include <bits/stdc++.h>

using namespace std;

struct Node
{
	public:
		int data;
		Node* next;
		Node* prev;


		Node(int data1,Node* next1,Node* prev1)
		{
			data = data1;
			next = next1;
			prev = prev1;
		}
		Node(int data1)
		{
			data = data1;
			next = nullptr;
			prev = nullptr;
		}
};

Node* convertArrToDLL(vector<int>&arr)
{
	Node* head = new Node(arr[0],nullptr,nullptr);

	Node* back = head;

	for(int i = 1;i<arr.size();i++)
	{
		Node* temp = new Node(arr[i],nullptr,back);

		back->next = temp;
		back = back->next;
	}
	return head;
}

void printDll(Node* head)
{
	Node* temp = head;
	while(temp)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node* deleteHead(Node* head)
{
	if(head == NULL||head->next==NULL) return NULL;

	Node* temp = head;
	head = head->next;
	head->prev = nullptr;
	temp->next = nullptr;
	delete temp;
	return head;
}

Node* deleteTail(Node* head)
{
	if(head == NULL || head->next == NULL) return NULL;

	Node* temp = head;
	while(temp->next->next!=NULL)
	{
		temp = temp->next;
	}

	temp = temp->next;
	temp->prev->next = nullptr;
	temp->prev = nullptr;
	delete temp;
	return head;
}

int main()
{
	vector<int> arr = {}; 

	Node* head = convertArrToDLL(arr);
	
	head = deleteTail(head); 	

	printDll(head);

	return 0;
}