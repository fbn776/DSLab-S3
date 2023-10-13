#include <stdio.h>

#define SIZE 4
#define ERROR (-9999)

void Enqueue(int Q[], int *front, int *rear, int item) {
	if (*front == ((*rear) + 1) % SIZE)
		printf("Queue is full\n");
	else {
		if (*front == -1)
			*front = 0;
		(*rear) = ((*rear) + 1) % SIZE;
		Q[*rear] = item;
	}
}

int Dequeue(int Q[], int *front, int *rear) {
	if (*front == -1) {
		printf("Queue is empty");
		return ERROR;
	} else {
		int item = Q[*front];
		*front = ((*front) + 1) % SIZE;

		if (*front == ((*rear) + 1) % SIZE)
			*front = (*rear) - 1;

		return item;
	}
}

void Display(int Q[], int front, int rear) {
	int i;

	if (front == -1)
		return;

	if (front > rear) {
		for (i = front; i < SIZE; i++)
			printf("%d\n", Q[i]);

		for (i = 0; i <= rear; i++)
			printf("%d\n", Q[i]);
	} else
		for(i = front; i <= rear; i++)
			printf("%d\n", Q[i]);
}

int main() {
	int Q[SIZE], front = -1, rear = -1, choice, item;
	char cnt = 'Y';
	printf("===Choices===\n1 - Enqueue\n2 - Dequeue\n3 - Display\n4 - Exit\n");

	while (cnt == 'Y') {
		printf("Enter choice: ");
		scanf(" %d", &choice);
		switch (choice) {
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