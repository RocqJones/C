#include <stdio.h>
#include <stdlib.h>

// An example of Global  and Local Scope

/* this is a 'global' variable, anywhere in the program can access it */
int i = 5;

/* this is a function, all variables inside of it are "local" to the function. */
int main(void) {
	/* 'i' now equals 6 */
	int i = 6;
	/* prints a '6' to the screen, instead of the global variable of 'i', which is 5 */
	printf("%d\n", i);
	return 0;
}
