#include <stdio.h>

#define MAX_SIZE 100

/**More priority means higher priority number*/
typedef struct {
	int data;
	int priority;
} Item;

typedef struct {
	Item Queue[MAX_SIZE];
	int size;
} PQueue;

void Enqueue(PQueue *pq, Item item) {
	if (pq->size >= MAX_SIZE) {
		printf("Priority Queue is full, cannot enqueue.\n");
		return;
	}

	int index = pq->size;

	while (index > 0 && item.priority > pq->Queue[index - 1].priority) {
		pq->Queue[index] = pq->Queue[index - 1];
		index--;
	}

	pq->Queue[index] = item;
	pq->size++;
}

Item Dequeue(PQueue *pq) {
	Item i;
	if (pq->size <= 0) {
		printf("Priority Queue is empty, cannot dequeue.\n");
		i.priority = -1;
		return i;
	}

	i = pq->Queue[pq->size - 1];
	pq->size--;

	return i;
}


void Display(PQueue pq) {
	int i;
	for (i = 0; i < pq.size; i++)
		printf("Data: %d --- Priority: %d\n", pq.Queue[i].data, pq.Queue[i].priority);

	printf("\n");
}

int main() {
	char cnt = 'Y';
	int choice;
	PQueue pq;
	Item item;
	pq.size = 0;


	printf("===Choices===\n1 - Enqueue\n2 - Dequeue\n3 - Display\n4 - Exit\n");

	while (cnt == 'Y') {
		printf("\nEnter choice: ");
		scanf(" %d", &choice);
		switch (choice) {
			case 1:
				printf("Enter data and priority: ");
				scanf(" %d %d", &item.data, &item.priority);
				Enqueue(&pq, item);
				break;
			case 2:
				item = Dequeue(&pq);
				item.priority == -1 ?: printf("Data: %d --- Priority: %d\n", item.data, item.priority);
				break;
			case 3:
				Display(pq);
				break;
			default:
				cnt = 'N';
		}
	}
}

