#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define INF 0x3f3f3f3f
using namespace std;
//Node For Linked List
struct Node {
	int value;
	Node* next;
	Node() {
		value = -1;
		next = NULL;
	}
	Node(int v, Node* p) {
		value = v;
		next = p;
	}
	void setValue(int v) { value = v; }
	int getValue() { return value; }
	void setNext(Node* p) { next = p; }
	Node* getNext() { return next; }

	~Node() {}
};
Node* getTail(Node* head) {
	Node* tail = head;
	while (tail->next != NULL)
		tail = tail->next;
	return tail;
}
void addTail(Node* head, int value) {
	getTail(head)->next = new Node(value, NULL);
}
void printList(Node* head) {
	Node* p = head;
	while (p->next != NULL) {
		p = p->next;
		printf("%d ", p->value);
	}
	printf("\n");
}
//Stack implemented with Linked List
class Stack {
	Node* head;
public: 
	Stack();
	void push(int data); 
	bool pop(int &data); 
	void printStack() {
		printList(head);
	}
	~Stack();
};
Stack::Stack() {
	head = new Node();
}
void Stack::push(int data) {
	Node * n = new Node(data, head->getNext()); head->setNext(n);
} 
bool Stack::pop(int &data) {
	Node *n = head->getNext();
	if (n != NULL) {
		data = n->getValue(); 
		head->setNext(n->getNext()); 
		delete n; 
		return true;
	} 
	return false;
} 
Stack::~Stack() {
	Node *n = head->getNext();
	while (n != NULL) {
		head->setNext(n->getNext());
		delete n;
		n = head->getNext();
	}
}
//Stack implemented with Array
class StackArray {
public:
	StackArray();
	~StackArray() {}
	void push(int x);
	bool pop(int& x);
private:
	void realloc(int newCap);
	int* array;
	int size;
	int cap;
};
StackArray::StackArray() {
	cap = 100;
	array = new int[100];
}
void StackArray::push(int x) {
	if (size == cap)
		realloc(cap << 1);
	array[size++] = x;
}
void StackArray::realloc(int newCap) {
	if (newCap < size) return;    
	int *oldarray = array;
	array = new int[newCap]; 
	for (int i = 0; i<size; i++)       
		array[i] = oldarray[i];    
	cap = newCap;    
	delete[] oldarray;
}
bool StackArray::pop(int& x) {
	if (size == 0)
		return false;
	x = array[--size];
	if (size <= (cap >> 2))
		realloc(cap >> 1);
	return true;
}
//Binary Search
int bs(int arr[], int lo, int hi, int key) {
	if (lo > hi)
		return INF;//key value not found
	int mid = (lo + hi) >> 1;
	if (mid == key)
		return mid;
	if (arr[mid] > key)
		return bs(arr, lo, mid - 1, key);
	return bs(arr, mid + 1, hi, key);
}
int main() {
	
	return 0;
}