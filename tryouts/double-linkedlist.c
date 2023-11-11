#include <stdio.h>
#include <stdlib.h>

struct Dnode {
	int data;
	struct Dnode *left;
	struct Dnode *right;
};

typedef struct Dnode Dnode;

Dnode *newNode() {
	return (Dnode *) malloc(sizeof(Dnode));
}

void insertAtStart(Dnode *header, int data) {
	Dnode *node = newNode();

	node->left = header;
	node->right = header->right;

	node->data = data;
	node->right->left = node;
}

void display(Dnode *header) {
	int i = 0;
	Dnode *ptr = header;
	while (ptr->right != NULL) {
		printf("<-- [  | %d |  ] -->", ptr->data);

		i++;
		ptr = ptr->right;
	}
}

int main() {
	int choice, data;
	Dnode *header = newNode();
	header->left = NULL;
	header->right = NULL;

	printf("Doubly linked list:\nChoices:\n1 - Insert at start\n2 - Insert at pos\n3 - Insert at end\n4 - Display\n5- stop\n");

	while(1) {
		printf("Enter choice: ");
		scanf(" %d", &choice);

		switch(choice) {
			case 1:
				printf("Enter value: ");
				scanf(" %d", &data);
				insertAtStart(header, data);
				break;
			case 2:
				printf("Enter value: ");
				scanf(" %d", &data);
				insertAtStart(header, data);
				break;
			case 4:
				display(header);
				break;
			default:
				return 0;
		}
	}

}

