#include <stdio.h>
#include <stdlib.h>

#define ERROR -999999

typedef struct node {
	int data;
	struct node *link;
} Node;

int getInput(char prompt[]) {
	int data;
	printf("%s", prompt);
	scanf(" %d", &data);
	return data;
}

void deletePrint(int data) {
	data == ERROR ? printf("Error, cannot be deleted\n") : printf("Delete data: %d\n", data);
}

Node *getNode(int data, Node *link) {
	Node *n = (Node *) malloc(sizeof(Node));
	n->data = data;
	n->link = link;
	return n;
}

void addFront(Node *header, int data) {
	Node *node = getNode(data, header->link);
	header->link = node;
}

void addRear(Node *header, int data) {
	Node *node = getNode(data, NULL);
	Node *ptr = header;

	while (ptr->link != NULL) {
		ptr = ptr->link;
	}

	ptr->link = node;
}

void addAt(Node *header, int at, int data) {
	Node *node = getNode(data, NULL);
	Node *ptr = header;

	while (ptr->data != at && ptr->link != NULL) {
		ptr = ptr->link;
	}

	node->link = ptr->link;
	ptr->link = node;
}

int deleteFront(Node *header) {
	int item;
	Node *temp = header->link;

	if (temp == NULL)
		return ERROR;

	item = temp->data;
	header->link = temp->link;

	free(temp);
	return item;
}

int deleteRear(Node *header) {
	int item;
	Node *ptr = header, *temp;

	if (ptr->link == NULL)
		return ERROR;

	while (ptr->link != NULL) {
		temp = ptr;
		ptr = ptr->link;
	}

	item = ptr->data;
	temp->link = NULL;
	free(ptr);
	return item;
}

int deleteAt(Node *header, int at) {
	int item;
	Node *ptr = header, *temp;

	if (ptr->link == NULL)
		return ERROR;

	while (ptr->data != at && ptr->link != NULL) {
		temp = ptr;
		ptr = ptr->link;
	}

	item = ptr->data;
	temp->link = ptr->link;
	free(ptr);
	return item;
}


void printLine(int len, char lineChar, char endsChar, int borderSpace, char borderChar) {
	int i;
	printf("%c", endsChar);
	for (i = 0; i < len; i++)
		printf("%c", ((i + 1) % borderSpace == 0) ? borderChar : lineChar);
	printf("%c\n", endsChar);
}


void display(Node *header) {
	Node *ptr = header;

	while (ptr != NULL) {
		//printf("%d ", ptr->data);
		printLine(17, '-', '+', 9, '+');
		printf("|%4d%4s|%4s%4s|\n", ptr->data, " ", " ", " ");
		printLine(17, '-', '+', 9, '+');

		printf("%15s\n", "|");
		printf("%15s\n", "|");
		printf("%15s\n", "|");

		ptr->link != NULL ? (printf("%16s\n", "---"), printf("%15s\n", "-")) : printf("");
		ptr = ptr->link;
	}
	printf("%18s\n", "-------");
	printf("%17s\n", "-----");
	printf("\n");
}

int main() {
	Node *header;
	int choice;
	char ch = 'y';
	header->data = 0;
	header->link = NULL;

	printf("Choices:\n\t1 - Insert front\n\t2 - Insert at\n\t3 - Insert rear\n\t4 - Delete front\n\t5 - Delete at\n\t6 - Delete rear\n\t7 - Display\n\t8 - Exit\n");
	while (ch == 'y') {
		printf("Enter choice: ");
		scanf(" %d", &choice);
		switch (choice) {
			case 1:
				addFront(header, getInput("Enter data: "));
				break;
			case 2:
				addAt(header, getInput("Enter key: "), getInput("Enter data: "));
				break;
			case 3:
				addRear(header, getInput("Enter data: "));
				break;
			case 4:
				deletePrint(deleteFront(header));
				break;
			case 5:
				deletePrint(deleteAt(header, getInput("Enter key: ")));
				break;
			case 6:
				deletePrint(deleteRear(header));
				break;
			case 7:
				display(header);
				break;
			default:
				ch = 'n';
				break;
		}
	}
}