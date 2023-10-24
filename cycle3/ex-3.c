#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

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

void infixToPostfix(char infix[], char postfix[]) {
	int infixLength = strlen(infix);
	int postfixIndex = 0;
	char operatorStack[MAX_SIZE];
	int stackIndex = 0;

	for (int i = 0; i < infixLength; i++) {
		char ch = infix[i];

		if (ch == ' ' || ch == '\t') {
			continue; // Skip spaces and tabs
		} else if (isOperator(ch)) {
			while (stackIndex > 0 && getPrecedence(ch) <= getPrecedence(operatorStack[stackIndex - 1])) {
				postfix[postfixIndex++] = operatorStack[--stackIndex];
				postfix[postfixIndex++] = ' ';
			}
			operatorStack[stackIndex++] = ch;
		} else if (ch == '(') {
			operatorStack[stackIndex++] = ch;
		} else if (ch == ')') {
			while (stackIndex > 0 && operatorStack[stackIndex - 1] != '(') {
				postfix[postfixIndex++] = operatorStack[--stackIndex];
				postfix[postfixIndex++] = ' ';
			}
			if (stackIndex > 0 && operatorStack[stackIndex - 1] == '(') {
				stackIndex--; // Pop the '('
			}
		} else {
			// Operand
			while (i < infixLength && (isalnum(ch) || ch == '.')) {
				postfix[postfixIndex++] = ch;
				i++;
				ch = infix[i];
			}
			i--;
			postfix[postfixIndex++] = ' '; // Separate operands with spaces
		}
	}

	while (stackIndex > 0) {
		postfix[postfixIndex++] = operatorStack[--stackIndex];
		postfix[postfixIndex++] = ' ';
	}

	postfix[postfixIndex] = '\0';

	// Remove extra spaces at the end, if any
	while (postfixIndex > 0 && postfix[postfixIndex - 1] == ' ') {
		postfixIndex--;
	}
}

int main() {
	char infix[MAX_SIZE], postfix[MAX_SIZE];
	printf("Enter the infix expression: ");
	scanf("%[^\n]", infix);

	infixToPostfix(infix, postfix);
	printf("The postfix expression is: %s\n", postfix);

	return 0;
}
