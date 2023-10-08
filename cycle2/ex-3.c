#include <stdio.h>
#define ERROR 888888
#define SIZE 10


void push(int S[], int *top, int item) {
	if (*top == SIZE)
		printf("Stack overflow\n");
	else {
		(*top)++;
		S[*top] = item;
	}
}

int pop(int S[], int *top) {
	if (*top == -1) {
		printf("Stack underflow");
		return ERROR;
	} else {
		return S[(*top)--];
	}
}

int main() {
	int S[100], top = -1, i;
	char cnt = 'Y';
	printf("Choices:\n\t1 - Push\n\t2 - Pop\n\t3 - Display\n\t4 - Exit\n");

	while(cnt == 'Y') {
		int choice, item;
		printf("\nChoice: ");
		scanf(" %d", &choice);

		switch (choice) {
			case 1:
				printf("--- PUSH ---\nEnter item: ");
				scanf(" %d", &item);
				push(S, &top, item);
				break;
			case 2:
				printf("--- POP ---\n");
				pop(S, &top);
				break;
			case 3:
				printf("--- DISPLAY ---\n");
				for(i=top; i>=0; i--) {
					if(i == top) {
						printf("%d <-- TOP\n", S[top]);
					} else
						printf("%d\n", S[i]);
				}
				break;
			default:
				printf("--- EXIT ---\n");
				cnt = 'N';
				break;
		}
	}
}