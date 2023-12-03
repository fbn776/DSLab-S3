#include <stdio.h>

void StrRev(char str[]) {
	int i = 0, j = 0;
	for(; str[j] != '\0'; j++);
	j--;
	while(i <= j) {
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++; j--;
	}
}

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

int ICP(char ch) {
	switch (ch) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 3;
		case '^':
			return 6;
	}
	return -1;
}


int ISP(char ch) {
	switch (ch) {
		case '+':
		case '-':
			return 2;
		case '*':
		case '/':
			return 4;
		case '^':
			return 5;
	}
	return -1;
}


/**Converts infix to postfix**/
int convertInfixToPostfix(char infix[], char postfix[]) {
	char Stack[100], curr;
	int top = -1, len = 0, i, j = 0;

	//Find length
	for (; infix[len] != '\0'; len++);

	//Add initial brackets
	Push(Stack, &top, '(');
	infix[len++] = ')';
	infix[len] = '\0';

	for (i = 0; infix[i] != '\0'; i++) {
		curr = infix[i];
		if (curr == ' ' || curr == '\t')
			continue;


		if (isOperand(curr)) {
			postfix[j++] = curr;
		} else if (curr == '(') {
			Push(Stack, &top, curr);
		} else if (isOperator(curr)) {

			while (top > -1 && ICP(curr) <= ISP(Stack[top])) {
				char item = Pop(Stack, &top);
				postfix[j++] = item;
			}
			Push(Stack, &top, curr);

		} else if (curr == ')') {
			while (top > -1 && Stack[top] != '(') {
				char item = Pop(Stack, &top);
				postfix[j++] = item;
			}
			Pop(Stack, &top);
		} else {
			return 0;
		}
	}
	postfix[j] = '\0';
	return 1;
}

int main() {
	char infix[100], prefix[100];
	printf("Enter infix: ");
	scanf(" %[^\n]", infix);

	StrRev(infix);
	printf("Infix rev: %s\n", infix);

	convertInfixToPostfix(infix, prefix);
	StrRev(prefix);
	printf("Prefix: %s\n", prefix);
}