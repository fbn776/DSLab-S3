#include <stdio.h>
#define SIZE 10
#define ERROR (-9999)

void Enqueue(int Q[], int *front, int *rear, int item) {
	if(*rear == SIZE - 1)
		printf("Queue is full\n");
	else {
		if(*front == -1)
			*front = 0;
		(*rear)++;
		Q[*rear] = item;
	}
}

int Dequeue(int Q[], int *front, int *rear) {
	if(*front == -1) {
		printf("Queue is empty");
		return ERROR;
	} else {
		return Q[(*front)++];
	}
}

void Display(int Q[], int front, int rear) {
	int i;

	if(front == -1)
		return;

	if(front == 0 && rear == 0) {
		printf("%d <-- front | rear\n", Q[0]);
		return;
	}
	for(i = front; i<=rear; i++) {
		if(i == front)
			printf("%d <-- front\n", Q[i]);
		else if(i == rear)
			printf("%d <-- rear\n", Q[i]);
		else
			printf("%d\n", Q[i]);
	}
}

int main() {
	int Q[SIZE], front = -1, rear = -1, choice, item;
	char cnt = 'Y';
	printf("===Choices===\n1 - Enqueue\n2 - Dequeue\n3 - Display\n4 - Exit\n");

	while(cnt == 'Y') {
		printf("Enter choice: ");
		scanf(" %d", &choice);
		switch(choice) {
			case 1:
				printf("Enter item: ");
				scanf(" %d", &item);
				Enqueue(Q, &front, &rear, item);
				break;
			case 2:
				printf("%d\n", Dequeue(Q, &front, &rear));
				break;
			case 3:
				Display(Q, front, rear);
				break;
			default:
				cnt = 'N';
		}
	}
}