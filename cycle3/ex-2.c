#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
	int top;
	char items[MAX_SIZE];
};

void push(struct Stack *stack, char item) {
	if (stack->top == MAX_SIZE - 1) {
		printf("Stack is full\n");
	} else {
		stack->items[++stack->top] = item;
	}
}

char pop(struct Stack *stack) {
	if (stack->top == -1) {
		printf("Stack is empty\n");
		return '\0';
	} else {
		return stack->items[stack->top--];
	}
}

int isOperator(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int getPrecedence(char ch) {
	switch (ch) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return 0;
	}
}

void infixToPrefix(char infix[], char prefix[]) {
	struct Stack operatorStack;
	operatorStack.top = -1;

	int infixLength = strlen(infix);
	int prefixIndex = 0;

	for (int i = infixLength - 1; i >= 0; i--) {
		char ch = infix[i];

		if(ch == ' ' || ch == '\t')
			continue;

		if (isOperator(ch)) {
			while (operatorStack.top != -1 && getPrecedence(ch) < getPrecedence(operatorStack.items[operatorStack.top])) {
				prefix[prefixIndex++] = pop(&operatorStack);
			}
			push(&operatorStack, ch);
		} else if (ch == ')') {
			push(&operatorStack, ch);
		} else if (ch == '(') {
			while (operatorStack.top != -1 && operatorStack.items[operatorStack.top] != ')') {
				prefix[prefixIndex++] = pop(&operatorStack);
			}
			if (operatorStack.top != -1 && operatorStack.items[operatorStack.top] == ')') {
				pop(&operatorStack); // Pop the '('
			}
		} else {
			prefix[prefixIndex++] = ch;
		}
	}

	while (operatorStack.top != -1) {
		prefix[prefixIndex++] = pop(&operatorStack);
	}

	prefix[prefixIndex] = '\0';

	strrev(prefix);
}

int main() {
	char infix[MAX_SIZE], prefix[MAX_SIZE];
	printf("Enter the infix expression: ");
	scanf(" %[^\n]", infix);

	infixToPrefix(infix, prefix);
	printf("The prefix expression is: %s\n", prefix);

	return 0;
}
