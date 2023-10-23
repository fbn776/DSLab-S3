#include <stdio.h>
#include <math.h>

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

			while (top > -1 && getPrecedence(curr) <= getPrecedence(Stack[top])) {
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

int getAlphaPos(char ch) {
	if (ch >= 'a' && ch <= 'z')
		ch -= 32;

	return ch - 'A';
}

float evalExpr(char opr, float a, float b) {
	switch (opr) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		case '^':
			return powf(a, b);
		default:
			return 0;
	}
}

float evalPostfix(char P[]) {
	char curr;
	float Stack[100];
	int i, top = -1;
	//Stores value (taken from user) of the operands (alphabets) in the index of its alphabetic position;
	//Each element is an array of len 2, representing [value, first-time?]
	// (a(A) -> 0, b(B) -> 2 ... z(Z) -> 25
	float values[26][2] = {{0, 0}};

	for (i = 0; P[i] != '\0'; i++) {
		curr = P[i];
		if (isOperand(curr)) {
			int val = getAlphaPos(curr);
			//Get value from user of the current operand;
			if(values[val][1] == 0) {
				printf("Enter %c: ", curr);
				scanf(" %f", &values[val][0]);
				//Visited = true
				values[val][1] = 1;
			}
			PushF(Stack, &top, values[val][0]);
		} else if (isOperator(curr)) {
			float b = PopF(Stack, &top),
				  a = PopF(Stack, &top), c;
			c = evalExpr(curr, a, b);
			PushF(Stack, &top, c);
		}
	}

	return Stack[0];
}

int main() {
	char Q[100], P[100];
	int status;

	printf("Enter Expression: ");
	scanf("%[^\n]", Q);

	status = convertInfixToPostfix(Q, P);

	if (status) {
		printf("P: %s\n", P);

		printf("result: %f\n", evalPostfix(P));

	} else
		printf("Error in expression\n");

}