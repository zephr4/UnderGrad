#ifndef test_h
#define test_h

#include <string>

struct Link {
    // Provide your code here...
	std::string name; 
	Link* next;
};

struct Queue {
    // Provide your code here...
	Link* first;
	Link* last;
	
	Queue() {
		first = NULL;
		last = NULL;
	}
	
	void push (std::string nam) {
		if (first == NULL){ //&& last == NULL) { // here
			Link* newLink = new Link;
			newLink -> name = nam;
			newLink -> next = NULL;
			first = newLink;
			last = newLink;
		} else {
			Link* newLink = new Link;
			newLink -> name = nam;
			newLink -> next = NULL;
			last -> next = newLink;
			last = newLink;
		}
	}
	std::string pop () {
		if (first != NULL){
			std::string temp = first -> name;
			Link* newTemp = first;
			first = first -> next;
			delete newTemp;
			return temp;
		}
	}
	
	bool isEmpty () {
		if (first == NULL)//{
			return true; 
		//} else {
		return false;
		//}
	}
	};

#endif