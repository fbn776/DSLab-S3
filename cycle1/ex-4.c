/*
 * Ex - 29
 * String library functions using pointers
 *
 */
#include <stdio.h>

int StringLength(char *s) {
	int len = 0;
	for (; *(s + len) != '\0'; len++);
	return len;
}

void StringCopy(char *s1, char *s2) {
	int i, len = StringLength(s1);
	for (i = 0; i < len; i++)
		*(s2 + i) = *(s1 + i);
}

int StringCompare(char *s1, char *s2) {
	int i = 0;
	char c1 = *(s1 + i), c2 = *(s2 + i);

	while(c1 != '\0' && c2 != '\0') {
		c1 = *(s1 + i);
		c2 = *(s2 + i);

		if(c1 > c2)
			return 1;
		if(c1 < c2)
			return -1;

		i++;
	}
	return 0;
}

void StringConcat(char *s1, char *s2) {
	int i, j = 0;
	for(i = StringLength(s1); *(s2 + j) != '\0'; i++, j++)
		*(s1 + i) = *(s2 + j);

}


int main() {
	char str1[100], str2[100], strcp[200];
	printf("Enter string 1: ");
	scanf(" %[^\n]", str1);
	printf("Enter string 2: ");
	scanf(" %[^\n]", str2);

	printf("Length of string 1 = %d\nLength of string 2 = %d\n", StringLength(str1), StringLength(str2));
	StringCopy(str1, strcp);
	printf("Copied string 1 is: %s\n", strcp);
	printf("Comparison of str1 and str2 is %d\n", StringCompare(str1, str2));
	StringConcat(str1, str2);
	printf("Concated str1 and str2 is %s\n", str1);
}