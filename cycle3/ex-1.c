#include <stdio.h>

//// STACK OPERATIONS
void Push(char s[], int *top, char item) {
	s[++(*top)] = item;
}

char Pop(char s[], int *top) {
	if (*top == -1)
		return '\0';

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

int main() {
	char Stack[100], Q[100] = "a^b^c", P[100], curr;
	int top = -1, len = 0, i, j = 0;

//	printf("Enter Expression: ");
//	scanf("%[^\n]", Q);

	//Find length
	for (; Q[len] != '\0'; len++);

	//Add initial brackets
	Push(Stack, &top, '(');
	Q[len++] = ')';
	Q[len] = '\0';

	for (i = 0; Q[i] != '\0'; i++) {
		curr = Q[i];
		if (curr == ' ' || curr == '\t')
			continue;


		if (isOperand(curr)) {
			P[j++] = curr;
		} else if (curr == '(') {
			Push(Stack, &top, curr);
		} else if (isOperator(curr)) {

			while (top > -1 && getPrecedence(curr) <= getPrecedence(Stack[top])) {
				char item = Pop(Stack, &top);
				P[j++] = item;
			}
			Push(Stack, &top, curr);

		} else if (curr == ')') {
			while (top > -1 && Stack[top] != '(') {
				char item = Pop(Stack, &top);
				P[j++] = item;
			}
			Pop(Stack, &top);
		} else {
			printf("Error is expression\n");
			break;
		}
	}
	P[j] = '\0';

	printf("P: %s\n", P);

}