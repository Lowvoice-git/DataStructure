#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node {
	int value;
	struct _Node* next;
} Node;

typedef struct _List {
	Node* head;
	int __size__;

	bool(*empty)();
	int(*size)();
	void(*push_back)(int);
	void(*pop_back)();
	void(*insert)(int, int);
	void(*erase)(int);
	Node* (*reverse)(Node*);
} List;

List list;

Node* createNode(int value) {
	Node* newNode = (Node*)calloc(1, sizeof(Node));
	newNode->value = value;

	return newNode;
}

bool _empty() {
	return (list.head == NULL) ? true : false;
}

int _size() {
	return list.__size__;
}

void _push_back(int value) {
	Node* newNode = createNode(value);

	if (!list.empty()) {
		for (Node* pNode = list.head;; pNode = pNode->next) {
			if (pNode->next == list.head) {
				newNode->next = pNode->next;
				pNode->next = newNode;
				break;
			}
		}
	}
	else {
		list.head = newNode;
		list.head->next = list.head;
	}

	list.__size__++;
}

void _pop_back() {
	switch (list.size()) {
	case 1:
		free(list.head);
		list.head = NULL;
		list.__size__--;
		break;
	default:
		for (Node* pNode = list.head;; pNode = pNode->next) {
			if (pNode->next->next == list.head) {
				free(pNode->next);
				pNode->next = list.head;
				break;
			}
		}

		list.__size__--;
		break;
	}
}

void _insert(int index, int value) {
	Node* newNode = createNode(value);

	if (index == 0) {
		newNode->next = list.head;
		list.head = newNode;
		list.__size__++;
	}
	else if (list.size() - 1 >= index) {
		for (Node* pNode = list.head;; pNode = pNode->next, index--) {
			if (!(index - 1)) {
				newNode->next = pNode->next;
				pNode->next = newNode;
				break;
			}
		}

		list.__size__++;
	}
	else if (list.size() == index) {
		list.push_back(value);
	}
}

void _erase(int index) {
	if (!list.empty()) {
		Node* temp = NULL;

		if (index == 0) {
			temp = list.head->next;
			free(list.head);
			list.head = temp;
			list.__size__--;
		}
		else if (list.size() - 1 > index) {
			for (Node* pNode = list.head;; pNode = pNode->next, index--) {
				if (!(index - 1)) {
					temp = pNode->next->next;
					free(pNode->next);
					pNode->next = temp;
					break;
				}
			}

			list.__size__--;
		}
		else if (list.size() - 1 == index) {
			list.pop_back();
		}
	}
}

Node* _reverse(Node* pNode) {
	int value = pNode->value;

	if (pNode->next == list.head) {
		list.head->value = value;
		return list.head->next;
	}

	Node* temp = _reverse(pNode->next);
	temp->value = value;
	return temp->next;
}

List initializeList() {
	List newNode;

	newNode.head = NULL;
	newNode.__size__ = 0;
	newNode.empty = _empty;
	newNode.size = _size;
	newNode.push_back = _push_back;
	newNode.pop_back = _pop_back;
	newNode.insert = _insert;
	newNode.erase = _erase;
	newNode.reverse = _reverse;

	return newNode;
}

int main() {
	list = initializeList();

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

	list.reverse(list.head);
}