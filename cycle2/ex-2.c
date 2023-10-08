/**
 * Binary search
 */

#include <stdio.h>

int main() {
	int N, nums[30], key, i, top = 0, middle, bottom;
	printf("Enter N: ");
	scanf("%d", &N);
	printf("Enter sorted numbers list: ");
	for (i = 0; i < N; i++)
		scanf(" %d", &nums[i]);

	printf("Enter number to search: ");
	scanf(" %d", &key);

	bottom = N - 1;

	while(top < bottom) {
		middle = top + (bottom - top) / 2;
		if(nums[middle] < key)
			top = middle + 1;
		else if(nums[middle] > key)
			bottom = middle - 1;
		else {
			top = bottom = middle;
			break;
		}
	}

	if(top == bottom)
		printf("Found at index %d\n", top + 1);
	else
		printf("Not found");
}