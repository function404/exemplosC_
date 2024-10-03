#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* initialize(){
	return NULL;
};

struct Node* push(struct Node* top, int value){
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	if (newNode == NULL){
		printf("Memory allocation failure \n");
		printf("Cannot add more elements \n");
		return top;
	}
	newNode->data = value;
	newNode->next = top;
	return newNode;
};

int size(struct Node* top){
	int count = 0;
	struct Node* temp = top;
	while(temp !=NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

bool isEmpty(struct Node* top){
	return top == NULL;
}

int peek(struct Node* top){
	if (isEmpty(top)){
		printf("Empty stack! No elements to show");
		exit(EXIT_FAILURE);
	}
	return top->data;
}

int main(){
	struct Node* stack = initialize();
	int value, choice;
	
	while(1){
		printf("___---===MENU===---___: \n");
		printf("1 - Stack(Push): \n");
		printf("2 - Unstack(Pop): \n");
		printf("3 - See top(Peek): \n");
		printf("4 - See stack size: \n");
		printf("5 - Exit(Push): \n");
		printf("Choose an option: ");
		scanf("%d", &choice);
		
		switch (choice){
			case 1 :
				printf("Enter the value to stack");
				scanf("%d", &value);
				stack = push(stack, value);
				break;
			case 3 :
				if (!isEmpty(stack)){
					value = peek(stack);
					printf("Value at the top of the stack: %d \n", value);	
				} else {
					printf("Empty stack!");
				}
				break;
			case 4 :
				printf("Stack size: %d\n", size(stack));
				break;
			
		}
	}
}