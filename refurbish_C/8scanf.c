#include <stdio.h>

int main (void) {
	// local var
	int a;
	// char b;
	char c[10];
	
	// Request inputs from the user
	printf("Please enter your age: ");
	scanf("%d", &a);
	printf("Please enter your name: ");
	//scanf(" %c", &b); // leave a white space before %c
	scanf("%s", c);
	
	// Print outpus back to console
	printf("\n\nHello! %s is %d years old", c, a);
	
	return 0;
}
