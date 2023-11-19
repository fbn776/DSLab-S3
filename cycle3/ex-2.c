#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100


int StrLen(char str[]) {
	int i = 0;
	for(; str[i]; i++) ;
	return i;
}

void StrRev(char str[]) {
	int len = StrLen(str), i = 0, j;
	for(j = len - 1; i < len/2; i++, j--) {
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

//// STACK OPERATIONS
void Push(char s[], int *top, char item) {
	s[++(*top)] = item;
}

void PushF(float s[], int *top, float item) {
	s[++(*top)] = item;
}

char Pop(char s[], int *top) {
	if (*top == -1)
		return '\0';

	return s[(*top)--];
}

float PopF(float s[], int *top) {
	if (*top == -1)
		return 0;

	return s[(*top)--];
}

/**Checks if a given character is an operand**/
int isOperand(char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

/**Checks if a given character is an operator**/
int isOperator(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

/**Gets the precedence of an operator**/
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

/**Converts infix to prefix**/
int convertInfixToPrefix(char infix[], char prefix[]) {
	char revInfix[100];
	strcpy(revInfix, infix);
	StrRev(revInfix);

	char Stack[100], curr;
	int top = -1, len = 0, i, j = 0;

	//Find length
	for (; revInfix[len] != '\0'; len++);

	//Add initial brackets
	Push(Stack, &top, '(');
	revInfix[len++] = ')';
	revInfix[len] = '\0';

	for (i = 0; revInfix[i] != '\0'; i++) {
		curr = revInfix[i];
		if (curr == ' ' || curr == '\t')
			continue;

		if (isOperand(curr)) {
			prefix[j++] = curr;
		} else if (curr == '(') {
			Push(Stack, &top, curr);
		} else if (isOperator(curr)) {

			while (top > -1 && getPrecedence(curr) <= getPrecedence(Stack[top])) {
				char item = Pop(Stack, &top);
				prefix[j++] = item;
			}
			Push(Stack, &top, curr);

		} else if (curr == ')') {
			while (top > -1 && Stack[top] != '(') {
				char item = Pop(Stack, &top);
				prefix[j++] = item;
			}
			Pop(Stack, &top);
		} else {
			return 0;
		}
	}
	StrRev(prefix);
	prefix[j] = '\0';
	return 1;
}

int main() {
	char infix[MAX_SIZE], prefix[MAX_SIZE];
	printf("Enter the infix expression: ");
	scanf(" %[^\n]", infix);

	convertInfixToPrefix(infix, prefix);
	printf("The prefix expression is: %s\n", prefix);

	return 0;
}
