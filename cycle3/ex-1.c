#include <stdio.h>

#define ERROR "ERROR"
#define SIZE 100
#define POP_ERROR '~'

void Push(char S[], int *top, char item) {
	if (*top == SIZE)
		return;

	S[(*top)++] = item;
}

char Pop(char S[], int *top) {
	if (*top == -1)
		return POP_ERROR;
	else {
		return S[(*top)--];
	}
}

int getPrecedence(char item) {
	switch (item) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return -1;
	}
}

//Checks if a character is an alphabet
int isAlpha(char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

//Checks if a character is an operator or not
int isOperator(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

//Checks if ch is a bracket; if left bracket -1, if right bracket 1, else 0
int isBrace(char ch) {
	return ch == '(' ? -1 : (ch == ')' ? 1 : 0);
}

void convertToPostfix(char input[], int len, char result[]) {
	char Stack[SIZE], item = '(';
	int top = -1, i, k = 0;


	//Push an initial left parenthesis to the stack
	Push(Stack, &top, '(');

	for (i = 0; i < len; i++) {
		char curr = input[i];

		printf("Char is %c\n", curr);

		if (curr == ' ' || curr == '\t')
			continue;

		if (isAlpha(curr) == 1)
			result[k++] = curr;
		else if (isOperator(curr) == 1) {
			if (top == -1 || getPrecedence(Stack[top]) < getPrecedence(curr)) {
				Push(Stack, &top, curr);
			} else {
				while (top > -1 && getPrecedence(Stack[top]) >= getPrecedence(curr)) {
					result[k++] = Pop(Stack, &top);
				}
			}
		}
//		else if (isBrace(curr)) {
//			if(isBrace(curr) == 1) {
//				while(top > -1 && Stack[top] != '(') {
//					result[k++] = Pop(Stack, &top);
//				}
//			}
//		} else
			break;
	}

	while(top > -1) {
		item = Pop(Stack, &top);

		result[k++] = item;
	}
}

int main() {
	char input[100], output[100];
	int len = 0;

	printf("Enter infix expression: ");
	scanf("%[^\n]", input);

	for (; input[len] != '\0'; len++) ;

	convertToPostfix(input, len, output);

	printf("Result is: %s\n", output);
}