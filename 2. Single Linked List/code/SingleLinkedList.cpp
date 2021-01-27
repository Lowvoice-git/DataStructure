#include <iostream>

class Node {
public:
	int value;
	Node* next;

	Node(int value) : value(value), next(nullptr) {}
};

class List {
private:
	Node* head;
	int __size__;
public:
	List() : head(nullptr), __size__(0) {}

	bool empty();
	int size();
	void push_back(int value);
	void pop_back();
	void insert(int index, int value);
	void erase(int index);
};

bool List::empty() {
	return (head == nullptr) ? true : false;
}

int List::size() {
	return __size__;
}

void List::push_back(int value) {
	if (!empty()) {
		for (Node* pNode = head;; pNode = pNode->next) {
			if (pNode->next == nullptr) {
				pNode->next = new Node(value);
				break;
			}
		}
	}
	else {
		head = new Node(value);
	}
	__size__++;
}

void List::pop_back() {
	switch (size()) {
	case 1:
		delete head;
		head = NULL;
		__size__--;
		break;
	default:
		for (Node* pNode = head;; pNode = pNode->next) {
			if (pNode->next->next == NULL) {
				pNode->next = NULL;
				break;
			}
		}

		__size__--;
		break;
	}
}

void List::insert(int index, int value) {
	Node* newNode = new Node(value);

	if (index == 0) {
		newNode->next = head;
		head = newNode;
		__size__++;
	}
	else if (size() - 1 >= index) {
		for (Node* pNode = head;; pNode = pNode->next, index--) {
			if (!(index - 1)) {
				newNode->next = pNode->next;
				pNode->next = newNode;
				break;
			}
		}

		__size__++;
	}
	else if (size() == index) {
		push_back(value);
	}
}

void List::erase(int index) {
	if (!empty()) {
		Node* temp = nullptr;

		if (index == 0) {
			temp = head->next;
			delete head;
			head = temp;
			__size__--;
		}
		else if (size() - 1 > index) {
			for (Node* pNode = head;; pNode = pNode->next, index--) {
				if (!(index - 1)) {
					temp = pNode->next->next;
					delete pNode->next;
					pNode->next = temp;
					break;
				}
			}

			__size__--;
		}
		else if (size() - 1 == index) {
			pop_back();
		}
	}
}

int main() {
	List list = List();

	list.push_back(0);
	list.pop_back();

	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);

	list.pop_back();
	list.pop_back();

	list.insert(0, -1);
	list.erase(0);

	list.insert(6, 6);
	list.erase(6);

	list.insert(2, 200);
	list.erase(2);
}