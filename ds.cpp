#include <iostream>
#include <vector>

#pragma region Dynamic Array
int main() {

}

class DA {
public:
	DA(int size)
		:
		size(size),
		pArray(new int[size])

	{}
	DA(const DA& src) {
		*this = src;

	}
	DA& operator=(const DA& src) {
		delete pArray;
		pArray = nullptr;
		pArray = new int[src.size];
		size = src.size;
		for (int i = 0; i < size; i++) {
			(*this)[i] = src[i];
		}
		return *this;

	}
	~DA() {
		delete[] pArray;
		pArray = nullptr;
	}
	int& operator[](int index) {
		return pArray[index];
	}
	const int& operator[](int index) const {
		return pArray[index];
	}
private:
	int size = 0;
	int* pArray = nullptr;
};
#pragma endregion

#pragma region Linked-List
//Single
class node {
public:
	int value;
	node* next;
};

/*

double

class node {
public:
	int value;
	node* next;
	node* prev;
};

node* head;
node* tail;

node* nodey_boy = new node();
nodey_boy->value = value_input;
nodey_boy->next = NULL;
nodey_boy->prev = NULL;
head = nodey_boy;
tail = nodey_boy;

	insert a node at the end
	------------------------
	node* node_new = new node();
	node_new->value = value_input;
	node_new->next = NULL;
	node_new->prev = tail;
	tail->next= node;
	tail = node;

	//double link traversal

	void printForward(node* head_input){
	node* traveller = head_input;
	while(traveller != nullptr){
	std::cout << traveller->value << '\n';
	traveller = traveller->next;

	void printBackArds(node* tail_input){
	node* traveller = tail_input;
	while(traveller != nullptr){
	std::cout << traveller->value << '\n';
	traveller = traveller->prev;



*/


//************************************************
node* head = new node();
node* sec = new node();				//!!! VERY IMPORTANT THAT THESE ARE DELETED AT THE END OF THE PROGRAM !!!!!
node* tri = new node();
//*******************************************************
 

//head->value = 1; this is what inits value
//head->next = sec; this inits the pointer to the next node
//tri->next = NULL; if there is not a node after current node
//for a double link you would also init the tail


void printlist(node* n) {
	while (n != NULL) {
		std::cout << n->value << '\n';
		n = n->next;
	}
}
void insert_at_front(node** head_input,int value_input) 
{
	//creates a new node
	node* node_new = new node();
	node_new->value = value_input;
	//inserts at the front
	node_new->next = *head_input;
	//assigns the new node to the head
	*head_input = node_new;
}
void insert_at_end(node** head_input, int value_input) {
	//creates a new node
	node* node_new = new node();
	node_new->value = value_input;
	node_new->next = NULL;
	//if list is empty, new node is assigned as the head
	if (*head_input == NULL) 
	{
		*head_input = node_new;
		return;
	}
	//find the last node
	node* last = *head_input;
	while (last->next != NULL) {
		last = last->next;
	}
	//insert node at the end
	last->next = node_new;

}
void insert_at_location(node* prev_node, int value_input) {
	//checks if previous node is null
	if (prev_node == NULL) {
		std::cout << "Error" << '\n';
	}
	//creates a new node
	node* node_new = new node();
	node_new->value = value_input;
	//inserts at the front
	*node_new->next = *prev_node->next;
	prev_node->next = node_new;
}
#pragma endregion

#pragma region Stack
//this uses the STL implementation of Stack

/*
void printStackElements(stack<int> stack) {
	while (!stack.empty()) {
		std::cout << stack.top() << endl;
		stack.pop();
	}
}

int main()
{	//empty, size, push, pop, top
	stack<int>numbersStack;
	numbersStack.push(1);
	numbersStack.push(2);
	numbersStack.push(3);
	numbersStack.pop();

	printStackElements(numbersStack);

	if (numbersStack.empty())
		std::cout << "Stack is empty" << endl;
	else
		std::cout << "Stack is not empty" << endl;
	std::cout << "Stack size is " << numbersStack.size() << endl;

	system("pause>0");
}
*/

// these are 2 different ways of making a stack ds. One is using an array, the other is using linked lists

/*
// this version uses Arrays

#define MAX 1000 

class Stack {
	int top;

public:
	int a[MAX]; // Maximum size of Stack 

	Stack() { top = -1; }
	bool push(int x);
	int pop();
	int peek();
	bool isEmpty();
};

bool Stack::push(int x)
{
	if (top >= (MAX - 1)) {
		std::cout << "Stack Overflow";
		return false;
	}
	else {
		a[++top] = x;
		std::cout << x << " pushed into stack\n";
		return true;
	}
}

int Stack::pop()
{
	if (top < 0) {
		std::cout << "Stack Underflow";
		return 0;
	}
	else {
		int x = a[top--];
		return x;
	}
}
int Stack::peek()
{
	if (top < 0) {
		std::cout << "Stack is Empty";
		return 0;
	}
	else {
		int x = a[top];
		return x;
	}
}

bool Stack::isEmpty()
{
	return (top < 0);
}

// Driver program to test above functions 
int main()
{
	class Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	std::cout << s.pop() << " Popped from stack\n";

	//print top element of stack after popping 
	std::cout << "Top element is : " << s.peek() << endl;

	//print all elements in stack : 
	std::cout << "Elements present in stack : ";
	while (!s.isEmpty())
	{
		// print top element in stack 
		std::cout << s.peek() << " ";
		// remove top element in stack 
		s.pop();
	}

	return 0;
}


//this one uses Linked lists

class StackNode {
public:
	int data;
	StackNode* next;
};

StackNode* newNode(int data)
{
	StackNode* stackNode = new StackNode();
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}

int isEmpty(StackNode* root)
{
	return !root;
}

void push(StackNode** root, int data)
{
	StackNode* stackNode = newNode(data);
	stackNode->next = *root;
	*root = stackNode;
	std::cout << data << " pushed to stack\n";
}

int pop(StackNode** root)
{
	if (isEmpty(*root))
		return INT_MIN;
	StackNode* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);

	return popped;
}

int peek(StackNode* root)
{
	if (isEmpty(root))
		return INT_MIN;
	return root->data;
}

// Driver code
int main()
{
	StackNode* root = NULL;

	push(&root, 10);
	push(&root, 20);
	push(&root, 30);

	std::cout << pop(&root) << " popped from stack\n";

	std::cout << "Top element is " << peek(root) << endl;

	std::cout <<"Elements present in stack : ";
	 //print all elements in stack :
	while(!isEmpty(root))
	{
		// print top element in stack
		std::cout << peek(root) <<" ";
		// remove top element in stack
		pop(&root);
	}

	return 0;
}


*/


#pragma endregion

#pragma region Queue
//------------------------------------------
//this uses the STL implementation of Queue
// -----------------------------------------
/*  void printQueue(queue<int> queue) {

while (!queue.empty())
{
	std::cout << queue.front() << "  ";
	queue.pop();
}
std::cout << endl;
}

int main()
{
	queue<int> myQueue;
	myQueue.push(1);
	myQueue.push(2);
	myQueue.push(3);

	std::cout << "Size is " << myQueue.size() << endl;
	std::cout << "First element is " << myQueue.front() << endl;
	std::cout << "Last element is " << myQueue.back() << endl;

	std::cout << "My queue: " << endl;
	printQueue(myQueue);

	system("pause>0");
}
*/

// ---------------------------------------------------------------------
// 
// these are 2 different ways of making a Queue ds. One is using an array, the other is using linked lists
// 
// ---------------------------------------------------------------------
// this version uses Arrays
// ---------------------------------------------------------------------
// 
// class Queue {
/* public:
	int front, rear, size;
	unsigned cap;
	int* arr;
};

// Function to create a queue of given capacity
// It initializes size of queue as 0
Queue* createQueue(unsigned cap)
{
	Queue* queue = new Queue();
	queue->cap = cap;
	queue->front = queue->size = 0;

	queue->rear = cap - 1;
	queue->arr = new int[(queue->cap * sizeof(int))];
	return queue;
}

---------------------------------------
// this version uses linked lists
---------------------------------------

struct QNode {
	int key;
	struct QNode* next;
};

// The queue, front stores the front node of LL and rear
// stores the last node of LL
struct Queue {
	struct QNode *front, *rear;
};

// A utility function to create a new linked list node.
struct QNode* newNode(int k)
{
	struct QNode* temp
		= (struct QNode*)malloc(sizeof(struct QNode));
	temp->key = k;
	temp->next = NULL;
	return temp;
}

// A utility function to create an empty queue
struct Queue* createQueue()
{
	struct Queue* q
		= (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
	return q;
}
*/
#pragma endregion

#pragma region Maps

//Unordered map
class hashmap {
public:
	hashmap() {
		for (int i = 0; i < Table_size; i++)
		{
			HM[i] = new hashObj;
			HM[i]->key = "empty";
			HM[i]->value = 0;
			HM[i]->next = nullptr;
		}
	};
	~hashmap() = default;
	int hash(std::string key) {
		return key.length() % Table_size;
	};
	int total_collisions(int index) {

		int count = 0;

		if (HM[index]->key == "name") {
			return count;
		}
		else {
			//count++;
			hashObj* ptr = HM[index];
			while (ptr->next != nullptr) {
				count++;
				ptr = ptr->next;
			}

		}
		return count;
	}
	void printmap() {
		int number;
		for (int i = 0; i < Table_size; i++) {
			number = total_collisions(i);
			std::cout << "------------------\n";
			std::cout << "index = " << i << '\n';
			std::cout << HM[i]->key << '\n';
			std::cout << HM[i]->value << '\n';
			std::cout << "# of collisions = " << number << '\n';
			std::cout << "------------------\n";


		}
	}
	void add(std::string key_in, int value_in) {
		int index = hash(key_in);

		if (HM[index]->key == "empty") {
			HM[index]->key = key_in;
			HM[index]->value = value_in;
		}
		else {
			hashObj* ptr = HM[index];
			hashObj* obj_new = new hashObj;
			obj_new->key = key_in;
			obj_new->value = value_in;
			obj_new->next = nullptr;
			while (ptr->next != nullptr) {
				ptr = ptr->next;
			}
			ptr->next = obj_new;
		}
	};
	void search(std::string search) {

		int i = hash(search);

		hashObj* ptr = HM[i];
		while (ptr->key != "empty") {
			if (ptr->key == search) {
				std::cout << search << " was found at Index : " << i << '\n';
				return;
			}
			else {
				ptr = ptr->next;
			}
		}
		std::cout << "Not found" << '\n';
	}
	void remove(std::string remove_key) {

		int index = hash(remove_key);
		hashObj* delptr;
		hashObj* ptr0;
		hashObj* ptr1;


		if (HM[index]->key == "empty" && HM[index]->value == 0) {
			std::cout << "cannot delete empty container" << '\n';
		}
		else if (HM[index]->key == remove_key && HM[index]->next == nullptr) {
			HM[index]->key = "empty";
			HM[index]->value = 0;

			std::cout << remove_key << "was removed" << '\n';
		}

		else if (HM[index]->key == remove_key) {
			delptr = HM[index];
			HM[index] = HM[index]->next;
			delete delptr;

			std::cout << remove_key << "was removed" << '\n';
		}
		else {
			ptr0 = HM[index]->next;
			ptr1 = HM[index];

			while (ptr0 != nullptr && ptr0->key != remove_key) {
				ptr1 = ptr0;
				ptr0 = ptr0->next;
			}
			if (ptr0 == nullptr) {
				std::cout << remove_key << " was not found\n";
			}
			else
			{
				delptr = ptr0;
				ptr0 = ptr0->next;
				ptr1->next = ptr0;

				delete delptr;

				std::cout << remove_key << " was removed" << '\n';
			}
		}
	}
private:
	static const int Table_size = 10;
	struct hashObj {
		std::string key;
		int value;
		hashObj* next;
	};
	hashObj* HM[Table_size];

};



#pragma endregion
