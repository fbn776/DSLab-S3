#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
	int data[MAX_SIZE];
	int front, rear;
} Deque;

void initializeDeque(Deque *dq) {
	dq->front = -1;
	dq->rear = -1;
}

int isFull(Deque *dq) {
	return ((dq->front == 0 && dq->rear == MAX_SIZE - 1) || (dq->front == dq->rear + 1));
}

int isEmpty(Deque *dq) {
	return (dq->front == -1);
}

void insertFront(Deque *dq, int element) {
	if (isFull(dq)) {
		printf("Deque is full, cannot insert at front.\n");
		return;
	}

	if (isEmpty(dq)) {
		dq->front = 0;
		dq->rear = 0;
	} else if (dq->front == 0) {
		dq->front = MAX_SIZE - 1;
	} else {
		dq->front--;
	}

	dq->data[dq->front] = element;
}

void insertRear(Deque *dq, int element) {
	if (isFull(dq)) {
		printf("Deque is full, cannot insert at rear.\n");
		return;
	}

	if (isEmpty(dq)) {
		dq->front = 0;
		dq->rear = 0;
	} else if (dq->rear == MAX_SIZE - 1) {
		dq->rear = 0;
	} else {
		dq->rear++;
	}

	dq->data[dq->rear] = element;
}

int deleteFront(Deque *dq) {
	if (isEmpty(dq)) {
		printf("Deque is empty, cannot delete from front.\n");
		return -1;
	}

	int removedElement = dq->data[dq->front];

	if (dq->front == dq->rear) {
		dq->front = -1;
		dq->rear = -1;
	} else {
		if (dq->front == MAX_SIZE - 1) {
			dq->front = 0;
		} else {
			dq->front++;
		}
	}

	return removedElement;
}

int deleteRear(Deque *dq) {
	if (isEmpty(dq)) {
		printf("Deque is empty, cannot delete from rear.\n");
		return -1;
	}

	int removedElement = dq->data[dq->rear];

	if (dq->front == dq->rear) {
		dq->front = -1;
		dq->rear = -1;
	} else {
		if (dq->rear == 0) {
			dq->rear = MAX_SIZE - 1;
		} else {
			dq->rear--;
		}
	}
	return removedElement;
}

void displayDeque(Deque *dq) {
	if (isEmpty(dq)) {
		printf("Deque is empty.\n");
		return;
	}

	printf("Deque elements: ");
	int i = dq->front;
	do {
		printf("%d ", dq->data[i]);
		i = (i + 1) % MAX_SIZE;
	} while (i != (dq->rear + 1) % MAX_SIZE);
	printf("\n");
}

int main() {
	Deque deque;
	char choice, cnt = 'Y';
	int item;
	initializeDeque(&deque);

	printf("===Choices===\n1 - Insert front\n2 - Insert rear\n3 - Delete front\n4 - Delete rear\n5 - Display\n6 - Exit\n");

	while (cnt == 'Y') {
		printf("Enter choice: ");
		scanf(" %d", &choice);
		switch (choice) {
			case 1:
				printf("Enter item: ");
				scanf(" %d", &item);
				insertFront(&deque, item);
				break;
			case 2:
				printf("Enter item: ");
				scanf(" %d", &item);
				insertRear(&deque, item);
				break;
			case 3:
				printf("%d\n", deleteFront(&deque));
				break;
			case 4:
				printf("%d\n", deleteRear(&deque));
				break;
			case 5:
				displayDeque(&deque);
				break;
			default:
				cnt = 'N';
		}
	}
}