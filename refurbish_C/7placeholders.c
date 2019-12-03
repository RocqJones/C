#include <stdio.h>

int main(void) {
	int j=456, k=56;
	int l = (j - k);
	
	// %d literally "holds the place" for the actual number that is the result
	printf("The integer answer is %d", l);
	
	// convert the answer to hexadecimals
	printf("\nThe answer into hexadecimals is %x", l);
	
	return 0;
}
