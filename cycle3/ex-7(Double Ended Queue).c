#include <stdio.h>
#define SIZE 10
#define ERROR -99999


int isFull(int f, int r) {
	return ((f == 0) && (r == SIZE - 1)) || (f == (r + 1));
}

void insertFront(int Q[], int *f, int *r, int data) {
	if(isFull(*f, *r)) {
		printf("Queue full\n");
		return;
	}

	if(*f == -1) {
		*f = *r = 0;
	} else if(*f == 0) {
		*f = SIZE - 1;
	} else {
		(*f)--;
	}

	Q[*f] = data;
}

void deleteFront(int Q[], int *f, int *r) {
	if(*f == -1) {
		printf("Queue empty\n");
	} else {
		int item = Q[*f];
		*f = (*f + 1) % SIZE;
		if(*f == (*r + 1) % SIZE) {
			*f = *r = -1;
		}
		printf("Dequeued -> %d\n", item);
	}
}

void insertRear(int Q[], int *f, int *r, int data) {
	if(isFull(*f, *r)) {
		printf("Queue is full\n");
	} else {
		if(*f == -1)
			*f = *r = 0;
		*r = (*r + 1) % SIZE;
		Q[*r] = data;
	}
}

void deleteRear(int Q[], int *f, int *r) {
	if(*f == -1) {
		printf("Queue is empty\n");
	} else {
		int item = Q[*r];
		if(*r == *f) {
			*r = *f = -1;
		} else if(*r == 0 && *f > *r) {
			*r = SIZE - 1;
		} else {
			(*r)--;
		}

		printf("Dequeued -> %d\n", item);
	}
}

void display(int Q[], int f, int r) {
	int i;
	if(f == -1)
		printf("Queue is empty");
	else if(f > r) {
		for(i = f; i < SIZE; i++)
			printf("%d ", Q[i]);
		for(i = 0; i <= r; i++)
			printf("%d ", Q[i]);
	} else
		for(i = f; i <= r; i++)
			printf("%d ", Q[i]);

	printf("\n");
}

int main() {
	int Q[SIZE], f = -1, r = -1;
	int choice, item;

	printf("Choices\n1 - Insert front\n2 - Delete front\n3 - Insert rear\n4 - Delete rear\n5 - Display\n6 - Exit\n");

	while(1) {
		printf("> ");
		scanf(" %d", &choice);

		switch(choice) {
			case 1:
				printf("Insert front: ");
				scanf(" %d", &item);
				insertFront(Q, &f, &r, item);
			break;
			case 2:
				deleteFront(Q, &f, &r);
			break;
			case 3:
				printf("Insert rear: ");
				scanf(" %d", &item);
				insertRear(Q, &f, &r, item);
			break;
			case 4:
				deleteRear(Q, &f, &r);
			break;
			case 5:
				display(Q, f, r);
				break;
			default:
				return 0;
		}
	}
}

