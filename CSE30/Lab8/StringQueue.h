#ifndef Queue_h
#define Queue_h

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
	
	void push (std::string data) {
		if (first == NULL){
			Link* temp = new Link;
			temp->name = data;
			temp->next = NULL;
			first = temp;
			last = temp;
		} else {
			Link* temp = new Link;
			temp->name = data;
			temp->next = NULL;
			last->next = temp;
			last = temp;
		}
	}
	std::string pop () {
		if (first != NULL){
			std::string vari = first->name;
			Link* temp2 = first;
			first = first->next;
			delete temp2;
			return vari;
		}
	}
	
	std::string peek () {
		if (first != NULL){
			return first->next;
		}
	}

	bool isEmpty () {
		if (first == NULL)
			return true; 
		
		return false;
		
	}
};

#endif


