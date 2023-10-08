/**
 * Array merge without sort
 */

#include <stdio.h>

void findLongestSubstring(char *str) {
	int n = 0, maxLength = 0, start = 0, longestStart = 0, i;

	while (str[n] != '\0')
		n++;

	for (int i = 0; i < n; i++) {
		int currentLength;
		for (int j = start; j < i; j++) {
			if (str[i] == str[j]) {
				start = j + 1;
				break;
			}
		}
		currentLength = i - start + 1;
		if (currentLength > maxLength) {
			maxLength = currentLength;
			longestStart = start;
		}
	}

	printf("The longest substring with no repeating characters is: ");
	for (i = longestStart; i < longestStart + maxLength; i++) {
		printf("%c", str[i]);
	}
	printf("\n");
}

int main() {
	char str[100];
	printf("Enter string: ");
	scanf("%s", str);

	findLongestSubstring(str);
}
