#include <stdio.h>

#define ERROR '~'
#define SIZE 50


void push(char S[], int *top, char item) {
	if (*top == SIZE)
		printf("Stack overflow\n");
	else {
		(*top)++;
		S[*top] = item;
	}
}

char pop(char S[], int *top) {
	if (*top == -1) {
		printf("Stack underflow");
		return ERROR;
	} else {
		return S[(*top)--];
	}
}

int main() {
	int top = -1, i, len = 0, isPalindrome = 1;
	char S[SIZE], str[100];

	printf("Enter string: ");
	scanf(" %s", str);

	for (; str[len] != '\0'; len++);

	for (i = 0; i < len / 2; i++)
		push(S, &top, str[i]);

	i = ((len % 2 == 1) ? (len / 2) + 1 : len / 2);
	for(; i < len; i++)
		if(pop(S, &top) != str[i]) {
			isPalindrome = 0;
			break;
		}

	if(isPalindrome == 1)
		printf("String is a palindrome\n");
	else
		printf("String is not a palindrome");
}