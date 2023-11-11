#include <stdio.h>
#define MAX_SIZE 100

struct Deque {
	int arr[MAX_SIZE];
	int front;
	int rear;
};

// Initialize an empty deque
void initDeque(struct Deque* deque) {
	deque->front = -1;
	deque->rear = -1;
}

// Check if the deque is empty
int isEmpty(struct Deque* deque) {
	return (deque->front == -1);
}

// Check if the deque is full
int isFull(struct Deque* deque) {
	return (deque->front == 0 && deque->rear == MAX_SIZE - 1) || (deque->front == deque->rear + 1);
}

// Insert an element at the front of the deque
void insertFront(struct Deque* deque, int item) {
	if (isFull(deque)) {
		printf("Deque is full. Cannot insert more elements.\n");
		return;
	}

	if (deque->front == -1) {
		deque->front = deque->rear = 0;
	} else if (deque->front == 0) {
		deque->front = MAX_SIZE - 1;
	} else {
		deque->front--;
	}

	deque->arr[deque->front] = item;
}

// Insert an element at the rear of the deque
void insertRear(struct Deque* deque, int item) {
	if (isFull(deque)) {
		printf("Deque is full. Cannot insert more elements.\n");
		return;
	}

	if (deque->front == -1) {
		deque->front = deque->rear = 0;
	} else if (deque->rear == MAX_SIZE - 1) {
		deque->rear = 0;
	} else {
		deque->rear++;
	}

	deque->arr[deque->rear] = item;
}

// Delete an element from the front of the deque
void deleteFront(struct Deque* deque) {
	if (isEmpty(deque)) {
		printf("Deque is empty. Cannot delete from the front.\n");
		return;
	}

	if (deque->front == deque->rear) {
		deque->front = deque->rear = -1;
	} else if (deque->front == MAX_SIZE - 1) {
		deque->front = 0;
	} else {
		deque->front++;
	}
}

// Delete an element from the rear of the deque
void deleteRear(struct Deque* deque) {
	if (isEmpty(deque)) {
		printf("Deque is empty. Cannot delete from the rear.\n");
		return;
	}

	if (deque->front == deque->rear) {
		deque->front = deque->rear = -1;
	} else if (deque->rear == 0) {
		deque->rear = MAX_SIZE - 1;
	} else {
		deque->rear--;
	}
}

// Display the contents of the deque
void displayDeque(struct Deque* deque) {
	if (isEmpty(deque)) {
		printf("Deque is empty.\n");
		return;
	}

	printf("Deque Contents: ");
	int i = deque->front;
	do {
		printf("%d ", deque->arr[i]);
		i = (i + 1) % MAX_SIZE;
	} while (i != (deque->rear + 1) % MAX_SIZE);
	printf("\n");
}

int main() {
	struct Deque deque;
	initDeque(&deque);

	insertFront(&deque, 1);
	displayDeque(&deque);

	insertRear(&deque, 2);
	displayDeque(&deque);

	deleteFront(&deque);
	displayDeque(&deque);

	deleteRear(&deque);
	displayDeque(&deque);

	return 0;
}
