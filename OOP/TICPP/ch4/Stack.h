// nested struct in a linked list

#ifndef STACK_H
#define STACK_H

struct Stack{
	struct Link{
		void *data;
		Link *next;
		void initialize(void* dat, Link* next);

	}*head;
	void initialize();
	void push(void* dat);
	void* peek();
	void* pop();
	void cleanup();
}

#endif