#include<iostream>
#include<string>

#define USE_APPEND //uncomment after implementing append
#define USE_REMOVE // uncomment after implementing remove

/// </summary>

struct Node {
	int val;
	Node* next;

	Node(int val, Node* next) : val(val), next(next) {

	}
};

//prepend one node as head
Node* node_prepend(Node* list, const int val) {
	return new Node{ val, list };
}

//append a new node into the list
Node* node_append(Node* list, const int val) {
	Node* n = list;
	if (!n) {
		return new Node{ val, nullptr };
	}
	
	Node* new_node = new Node{ val, nullptr };
	new_node->val = val;
	new_node->next = nullptr;

	while (n->next != nullptr)
		n = n->next;

	n->next = new_node;

	return list;
}

//Insert node at ith position
Node* node_insert(Node* list, const int i, const int val) {
	if (!list) {
		return new Node{ val, nullptr };
	}
	Node* prev = nullptr;
	Node* n = list;
	for (int j = 0; j < i && n != nullptr; j++) {
		prev = n;
		n = n->next;
	}
	if (prev) {
		prev->next = new Node{ val, n };
		return list;
	}
	else {
		return node_prepend(list, val);
	}
}

//remove a node at i=th place
Node* node_remove(Node* list, const int i) {
	if (!list) {
		return list;
	}
	//if trying to delete the first node, change the head to be the next node
	if (i == 0) {
		Node* n = list->next;
		delete list; 
		return n;
	}
	Node* n = list;


	// find the node that comes before i-th node
	for (int j = 0; n != NULL && j < i - 1; j++) {
		n = n->next;

		//if the node to be deleted does not exist (greater than the number of nodes)
		if (n == NULL || n->next == NULL) {
			return list;
		}
	}
		

	// Node temp->next is the node to be deleted
	// Store pointer to the next of node to be deleted
	Node* next = n->next->next;
	n->next = next;


	return list;


	//for (int j = 0; j < i; j++) {
	//	if (j != i && n->next == nullptr) {
	//		return list;
	//	}

	//	if (j = i && n->next == nullptr) {
	//		prev->next = n->next;
	//		delete(n);
	//		return list;
	//	}
	//}

	//return list;


	/*for (int j = 1; j < i ; j++) {
		if (n != nullptr) {
			n = n->next;
		}

	}


	if (n != nullptr && n->next != nullptr) {
		Node* del = n->next;
		n->next - n->next->next;
		delete del;
	}*/
	
}

//release the linked list when done
void node_release(Node* list) {
	if (!list) {
		return;
	}
	for (Node* n = list; n != nullptr;) {
		Node* next = n->next;
		delete n;
		n = next;
	}
}

//iterarte and print all nodes
void node_print(Node* list, std::ostream& os) {
	if (!list) {
		os << "empty";
	}
	else {
		for (Node* n = list; n != nullptr; n = n->next) {
			os << n->val;
			if (n->next) {
				os << ", ";
			}
		}
	}
}

///////////////LIST/////////////////////////////////////////////////////
// List class that uses node class 
// to form the actual linked list structure
class List {
	Node* head;

public:
	List();
	List(const List& l);
	~List();
	List& operator=(const List& rhs);
	void prepend(const int x);
	void insert(const int i, const int x);
	void append(const int x);
	void remove(const int i);

private:
	// Students: Using a friend function here is not required.
	friend std::ostream& operator<<(std::ostream& os, const List& l);
	// Copy the list into this this one
	void copy_list(const List& l);
};
List::List() : head(nullptr) {}
List::List(const List& l) : head(nullptr) {
	copy_list(l);
}
List::~List() {
	node_release(head);
}
List& List::operator=(const List& rhs) {
	// Avoid self-assignment
	if (this == &rhs) {
		return *this;
	}
	node_release(head);
	head = nullptr;
	copy_list(rhs);
	return *this;
}
void List::prepend(const int x) {
	head = node_prepend(head, x);
}

#ifdef USE_APPEND  
void List::append(const int x) {                    // will be compiled once append is implemented and USE_APPEND defined
	head = node_append(head, x);
}
#endif

void List::insert(const int i, const int x) {
	head = node_insert(head, i, x);
}

#ifdef  USE_REMOVE
void List::remove(const int i) {                   // will be compiled once remove is implemented and USE_REMOVE defined
	head = node_remove(head, i);
}
#endif

void List::copy_list(const List& l) {
	if (l.head) {
		head = new Node(l.head->val, nullptr);
		Node* a = head;
		for (Node* n = l.head; n != nullptr; n = n->next, a = a->next) {
			a->val = n->val;
			if (n->next) {
				a->next = new Node(0, nullptr);
			}
			else {
				a->next = nullptr;
			}
		}
	}
}
std::ostream& operator<<(std::ostream& os, const List& l) {
	node_print(l.head, os);
	return os;
}

void test_function(const List& current) {
	std::cout << "---- Test Function ----\n";
	List* b = new List(current);
	std::cout << "current = " << current << "\n"
		<< "b = " << *b << "\n";
	b->prepend(15);
	b->prepend(60);
#ifdef USE_APPEND  
	b->append(2);                                  // to test your functions
#endif	
	std::cout << "current = " << current << "\n"
		<< "b = " << *b << "\n";
#ifdef USE_REMOVE  
	b->remove(1);
#endif                              // to test your functions
	std::cout << "current = " << current << "\n"
		<< "b = " << *b << "\n";
	List c;
#ifdef USE_APPEND  
	c.append(5);                                  // to test your functions
#endif                             
	c.prepend(2);
	std::cout << "current = " << current << "\n"
		<< "b = " << *b << "\n"
		<< "c = " << c << "\n";
	c = *b;
#ifdef USE_APPEND  
	b->append(100);
#endif                                 // to test your functions
	c.insert(1, 4);
	std::cout << "current = " << current << "\n"
		<< "b = " << *b << "\n"
		<< "c = " << c << "\n";
	delete b;
	std::cout << "current = " << current << "\n"
		<< "c = " << c << "\n";
	std::cout << "---- End Test Function ----\n";
}

int main() {
	int num_cases = 0;
	std::cin >> num_cases;
	for (int i = 0; i < num_cases; ++i) {
		std::cout << "Case " << i << ":\n";
		std::string cmd;
		List list;
		while (cmd != "end") {
			std::cin >> cmd;
			if (cmd == "prepend") {
				int val = 0;
				std::cin >> val;
				list.prepend(val);
			}
#ifdef USE_APPEND  
			else if (cmd == "append") {
				int val = 0;
				std::cin >> val;
				list.append(val);
			}
#endif
			else if (cmd == "insert") {
				int val = 0, index = 0;
				std::cin >> index >> val;
				list.insert(index, val);
			}
#ifdef USE_REMOVE  
			else if (cmd == "remove") {
				int index = 0;
				std::cin >> index;
				list.remove(index);
			}
#endif
			else if (cmd == "test") {
				test_function(list);
			}
			std::cout << list << "\n";
		}
	}
	return 0;
}