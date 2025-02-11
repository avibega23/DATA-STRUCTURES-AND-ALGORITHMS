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
Node* insertFirstHead(Node* head,int x)
{
	Node* newHead = new Node(x,head,nullptr);
	head->prev = newHead;
	head = newHead;
	return head;
}
Node* inserBeforeTail(Node* head,int x)
{
	
	Node* tail = head;
	while(tail->next!=nullptr)
	{
		tail = tail->next;
	}
	Node* back = tail->prev;
	Node* temp = new Node(x,tail,back);
	back->next = temp;
	tail->prev = temp;

	return head;
}

Node* insertAtK(Node* head,int k,int x)
{
	if(k == 1) insertFirstHead(head,x);
	else
	{
		Node* temp = head;
		int cnt = 0;
		while(temp->next!=nullptr)
		{
			
			temp = temp->next;
			cnt++;
			if(cnt == k) break;
		}
		Node* back = temp->prev;
		Node* newNode = new Node(x,temp,back);
		back->next = newNode;
		temp->prev = newNode;
	}
	return head;
}
int main()
{
	vector<int> arr = {1,2,3,4,5,6}; 

	Node* head = convertArrToDLL(arr);
	
	head = insertAtK(head,7,10); 	

	printDll(head);

	return 0;
}