#pragma once
#include <stdexcept>

struct CNode {
	char *data;
	CNode* next;
};

class stack {
	CNode *element;

public:
	stack() {
		element = 0;
	}

	bool push(char *x) {
		CNode *node = new CNode;
		int len = 0;
		for (; x[len] != 0; len++) {}
		node->data = new char[strlen(x) + 1];
		for (int i = 0; x[i] != 0; i++) {
			node->data[i] = x[i];
		}
		node->data[len] = '\0';
		if (element != 0) {
			node->next = element;
			element = node;
		}
		else if (element == 0) {
			node->next = 0;
			element = node;
		}
		return true;
	}

	char* top() {
		if (element != 0) {
			return element->data;
		}
		else if (element == 0) {
			throw std::logic_error("stack is empty");
		}
	}

	char* look_down() {
		CNode *first = element;
		while (first->next != 0) {
			first = first->next;
		}
		if (first != 0) {
			return first->data;
		}
		else if (first == 0) {
			throw std::logic_error("stack is empty");
		}
	}

	bool pop_down() {
		CNode *first = element;
		CNode *second = 0;
		while (first->next != 0) {
			second = first;
			first = first->next;
		}
		if (second != 0) {
			second->next = 0;
			delete[] first->data;
			delete first;
			return true;
		}
		else {
			if ((first->next == 0) && (first != 0)) {
				delete[] first->data;
				delete first;
				element = 0;
			}
		}
		return false;
	}

	bool pop() {
		if (element != 0) {
			CNode* box = element;
			element = element->next;
			delete box;
			return true;
		}
		return false;
	}

	bool see() {
		if (element != 0) {
			return true;
		}
		return false;
	}


	~stack() {
		CNode *box;
		if (element != 0) {
			while (this->see()) {
				this->pop();
			}
			delete element;
		}
	}
};