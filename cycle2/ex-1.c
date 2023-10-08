/**
 * Linear search
 */
#include <stdio.h>

int main() {
	int arr[100], n, key, i, found = 0, index;

	printf("Enter number of elements: ");
	scanf(" %d", &n);

	printf("Enter numbers: ");
	for(i=0; i<n; i++)
		scanf(" %d", &arr[i]);

	printf("Enter key to search for: ");
	scanf(" %d", &key);

	for(i=0; i<n; i++) {
		if(arr[i] == key) {
			found = 1;
			index = i;
			break;
		}
	}

	if(found == 1) {
		printf("Found key at index %d\n", index);
	} else {
		printf("Key not found\n");
	}
}
