#include <stdio.h>
#define SIZE 10

typedef struct {
	int data;
	int prio;
} Item;

void Enqueue(Item Q[], int *size, Item item) {
	if(*size == SIZE)
		printf("Queue full\n");
	else {
		Q[(*size)++] = item;
	}
}

void Dequeue(Item Q[], int *size) {
	if(*size == 0) {
		printf("Queue empty\n");
	} else {
		int i, maxPrio = 0, maxAt = 0;
		Item item;
		for(i = 0; i < *size; i++) {
			if(Q[i].prio > maxPrio) {
				maxPrio = Q[i].prio;
				maxAt = i;
			}
		}

		item = Q[maxAt];

		// Shift the elements to left
		for(i = maxAt; i < *size - 1; i++) {
			Q[i] = Q[i+1];
		}
		(*size)--;

		printf("Data -> %d\nPrio -> %d\n", item.data, item.prio);
	}
}

void Display(Item Q[], int size) {
	int i;
	if(size == 0) {
		printf("Queue empty\n");
		return;
	}

	for(i = 0; i < size; i++)
		printf("Data -> %d\nPrio -> %d\n\n", Q[i].data, Q[i].prio);
}

int main() {
	Item Q[SIZE];
	int size = 0, choice;

	printf("Choices;\n1 - Enqueue\n2 - Dequeue\n3 - Display\n4 - Exit\n");
	while(1) {
		printf("> ");
		scanf(" %d", &choice);

		switch(choice) {
			case 1:
				Item item;
				printf("Enter data, priority: ");
				scanf(" %d %d", &(item.data), &(item.prio));
				Enqueue(Q, &size, item);
			break;
			case 2:
				Dequeue(Q, &size);
			break;
			case 3:
				Display(Q, size);
			break;
			default:
				return 0;
		}
	}
}
