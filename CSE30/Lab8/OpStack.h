#ifndef OpStack_h
#define OpStack_h

// Define the Link struct below...

struct Link {
    long data;
    char op;
    Link* next;
};

// Now define the Stack struct. It should be a stack of Links...

struct Stack {
    Link* temp;
    Link* first;
    Link* last;
    Link* point;
    Link* old;
    
    Stack() {
        temp = NULL;
        first = NULL;
        last = NULL;
        point = NULL;
        old = NULL;
    }

    void push (long value, char letter) {
        temp = new Link;
        temp->op = letter;
        temp->data = value;

        if ( first == NULL) {
            first = temp;
            first->next = NULL;
        }
        else {
            old = first;
            first = temp;
            first->next = old;
        }
    }

    bool isEmpty() {
        bool bin = false;
        if(first == NULL) {
            bin = true;
        }
        return bin;
    }

    Link* pop() {
        point = first;
        first = first->next;
        return point;
    }
};

#endif

