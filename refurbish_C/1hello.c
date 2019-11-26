// the classical hello world program
/*
This gives include statement, brings in the header file stdio.h , located often on unix systems at the directory /usr/include/, and includes
* the printf() function, as well as others, snprintf, scanf, getchar, getline. In C, functions that are exported have their "signatures" - 
* function name and parameter list -listed in header files for exporting, and then the same signatures are defined in another file, often of
* the same name, to be compiled once into an object file, and on unix systems often reside in /usr/lib/ with file names like stdlib.a or 
* stdlib.so , often as soft links to versioned files e.g. stdlib.1.3.so ,
*/
#include <stdio.h>
/*
This gives the standard library, which has functions such as rand() random number generation (e.g. for games) malloc() and free() for 
* dynamic heap memory allocation as opposed to stack memory allocation. Stack memory can be allocated by declaring variables and arrays at 
* the start of a function , including the main function, and will be destroyed when the function exits.
*/
#include <stdlib.h>

/*
The next line is the standard expected function name "main" and argument list of the first function to be executed for this program when the 
* compiled program is executed. The first argument is the number of arguments, and the second argument is an array of pointers to arrays of 
* characters (strings) which contain arguments .e.g. "-?" , "-v" , "-c"
*/
int main( int argc, char** argv) {
	//outputs a string without formatting
	printf("Hello World! I'm coding C again \n");
	// stdlib.h function to exit with a code, if executed from say a bash shell script, 0 will be  returned , which can be used inside a 
	// shell conditional if statement.
	return 0;
}
