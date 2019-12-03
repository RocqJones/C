# C 🔥

## Learning C basic concepts and hands on problem solving with data structures and algorithms in C  😎 

Then, presuming you are using GCC, type gcc -o hello hello.c. This tells gcc to compile your hello.c program into a form the machine can execute. The '-o hello' tells it to call the compiled program 'hello'.

## Compiling and Executing on Linux
    gcc -o hello hello.c //compile with your terminal
    ls // check if there's an exacutable file listed
    ./hello // execute the exec file
For Windows use [Dev-C++](https://sourceforge.net/projects/orwelldevcpp/) and for Mac OS [Code::Blocks](https://sourceforge.net/projects/codeblocks/) 
 

## TAKES ✔
* #include ```<stdio.h>``` tells the C compiler to find the standard header called ```<stdio.h>``` and add it to this program. In C, you often have to pull in extra optional components when you need them.
* " argv" , or "pointer to pointers" , is the same as ```*x[]``` or "array of pointers"; and "exit(0)" does the same as ```return 0``` for the main function.

* Block code? Generally, a block consists of executable statements.
example of blocks.
```
int main(void) {
    /* this is a 'block' */
    int i = 5;
    {
        /* this is also a 'block,' separate from the last one */
        int i = 6;
    }
    return 0;
}
```

## WHITESPACE.
* Refers to the tab, space and newline/EOL (End Of Line).

## SCOPE.
* Describes the level at which a piece of data or a function is visible.
Types of Scope
1. Local. Refers to something that can be seen or manipulated only within the block it was declared. 
2. Global. It's something that can be seen or manipulated from anywhere in the program.

## FUNCTIONS.
* There are a big part of programming. A function is a special kind of block that performs a well-defined task. If a function is well-designed, it can enable a programmer to perform a task without knowing anything about how the function works. 
"Function call". The act of requesting a function to perform its task.

## COMPILATION. 
* Its purpose is to provide an intuitive way for humans to provide instructions that can be easily converted into machine code that is comprehensible to a microprocessor.
* Compiler. It's what takes this code, and translates it into the machine code.

## PREPROCESSOR. 
* The preprocessor provides the ability for the inclusion of header files, macro expansions, conditional compilation, and line control. Many times you will need to give special instructions to your compiler. This is done by inserting preprocessor directives into your code. When you begin compiling your code, a special program called the preprocessor scans the source code and performs simple substitution of tokenized strings for others according to predefined rules. The preprocessor is not a part of the C language.
* In C language, all preprocessor directives begin with the pound character (#). You can see one preprocessor directive in the Hello world program introduced in A taste of C. #include <stdio.h> is an example of an header included in a code.

#### STEP 1: Syntax Checking. 
* This step ensures that the code is valid and will sequence into an executable program. Under most compilers, you may get messages or warnings indicating potential issues with your program (such as a statement always being true or false, etc.) When an error is detected in the program, the compiler will normally report the file name and line that is preventing compilation.

#### STEP 2: Object Code. 
* The compiler produces a machine code equivalent of the source code that can then be linked into the final program. The code itself can't be executed yet, as it has to complete the linking stage.

#### STEP 3: Linking. 
* Linking combines the separate object codes into one complete program by integrating libraries and the code and producing either an executable program or a library. Linking is performed by a linker, which is often part of a compiler. Common errors during this stage are either missing functions, or duplicate functions.

## AUTOMATION. 
* For large C projects, many programmers choose to automate compilation, both in order to reduce user interaction requirements and to speed up the process by only recompiling modified files. Most integrated development environments have some kind of project management, which makes such automation very easy. On UNIX-like systems, make and Makefiles are often used to accomplish the same.

## Making your programs clearer and more effective.
- By convention, a statement should be kept on its own line, as shown in the example below:
```
#include <stdio.h>
int main(void)
{
    printf("Hello, World!\n");
    return 0;
}
```

### ERROR HANDLING.
- C does not provide direct support for error handling (also known as exception handling). By convention, the programmer is expected to prevent errors from occurring in the first place, and test return values from functions. For example, -1 and NULL are used in several functions such as socket() (Unix socket programming) or malloc() respectively to indicate problems that the programmer should be aware about. In a worst case scenario where there is an unavoidable error and no way to recover from it, a C programmer usually tries to log the error and "gracefully" terminate the program.

### PREVENTING DIVIDE BY ZERO ERRORS. 
- A common pitfall made by C programmers is not checking if a divisor is zero before a division command. The following code will produce a runtime error and in most cases, exit.
```
    int dividend = 50;
    int divisor = 0;
    int quotient;
```
``` 
    quotient = (dividend/divisor); /* This will produce a runtime error! */
```
 
* For reasons beyond the scope of this document, you must check or make sure that a divisor is never zero. Alternatively, for *nix processes, you can stop the OS from terminating your process by blocking the SIGFPE signal. The code below fixes this by checking if the divisor is zero before dividing.
```
    #include <stdio.h> /* for fprintf and stderr */
    #include <stdlib.h> /* for exit */
    int main( void )
    {
        int dividend = 50;
        int divisor = 0;
        int quotient;
        if (divisor == 0) {
            /* Example handling of this error. Writing a message to stderr, and exiting with failure. */
            fprintf(stderr, "Division by zero! Aborting...\n");
            exit(EXIT_FAILURE); /* indicate failure.*/
        }
        quotient = dividend / divisor;
        exit(EXIT_SUCCESS); /* indicate success.*/
    }
```
    
### SIGNALS. 
- Events raised by the host environment or operating system to indicate that a specific error or critical event has occurred (e.g. a division by zero, interrupt, and so on.) However, these signals are not meant to be used as a means of error catching; they usually indicate a critical event that will interfere with normal program flow.
* This example creates a signal handler and raises the signal:
```
    #include <signal.h>
    #include <stdio.h>
    #include <stdlib.h>
    static void catch_function(int signal) {
        puts("Interactive attention signal caught.");
    }
    int main(void) {
        if (signal(SIGINT, catch_function) == SIG_ERR) {
        fputs("An error occurred while setting a signal handler.\n", stderr);
        return EXIT_FAILURE;
    }
    puts("Raising the interactive attention signal.");
    if (raise(SIGINT) != 0) {
        fputs("Error raising the signal.\n", stderr);
        return EXIT_FAILURE;
    }
    puts("Exiting.");
        return 0;
    }
```
    
### setjmp. 
- The setjmp function can be used to emulate the exception handling feature of other programming languages. The first call to setjmp provides a reference point to returning to a given function, and is valid as long as the function containing setjmp() doesn't return or exit. A call to longjmp causes the execution to return to the point of the associated setjmp call.
```
    #include <stdio.h>
    #include <setjmp.h>
    
    jmp_buf test1;
    void tryjump()
    {
        longjmp(test1, 3);
    }
    int main (void)
    {
        if (setjmp(test1)==0) {
            printf ("setjmp() returned 0.");
            tryjump();
        } else {
            printf ("setjmp returned from a longjmp function call.");
        }
    }
```

* The values of non-volatile variables may be corrupted when setjmp returns from a longjmp call.
While ```setjmp()``` and ```longjmp()``` may be used for error handling, it is generally preferred to use the return value of a function to indicate an error, if possible.

### VARIABLES. 
Simply names used to refer to some location in memory, a location that holds a value with which we are working.
 * So, if you have a variable i that is initialized (set equal) to 4, then it follows that i+1 will equal 5 eg ```some_number=3;```
 * Declaring variables is the way in which a C program shows the number of variables it needs, what they are going to be named, and how much memory they will need eg ```int some_number;```

### BASIC DATA TYPES
#### int Type.
The int type stores integers in the form of "whole numbers" which is is typically the size of one machine word, which on most modern home PCs is 32 bits (4 octets). Example ```int numberOfStudents, i, j=5;```
#### char Type.
The char type is capable of holding any member of the execution character set. It stores the same kind of data as an int (i.e. integers), but typically has a size of one byte. The size of a byte is specified by the macro CHAR_BIT which specifies the number of bits in a char (byte). Examples of character literals are ```'a', 'b', '1'. etc``` and ```char letter1 = 'a';```
#### float Type.
float is short for floating point. float literals must be suffixed with F or f, otherwise they will be interpreted as doubles.
Examples are: 3.1415926f, 4.0f, 6.022e+23f. float variables can be declared using the float keyword. ```float nums=12.45;```

#### double Type.
double keyword allows you to store double-precision floating point numbers, real numbers, in other words, both integer and non-integer values. Its size is typically two machine words, or 8 bytes on most machines. Examples of double literals are 3.1415926535897932, 4.0, 6.022e+23 (scientific notation 5 ) and are declared as ```double```

### sizeof. 
If you have any doubts as to the amount of memory actually used by any variable, you can use the sizeof operator to find out for sure. Its syntax is: ```size_t size;   int i;    size = sizeof(i);```

### const qualifier. 
When the const qualifier is used, the declared variable must be initialized at declaration. It is then not allowed to be changed.

### * define. 
- When you write programs, you can create what is known as a macro, so when the computer is reading your code, it will replace all instances of a word with the specified expression. Here's an example. If you write ```#define PRICE_OF_CORN 0.99```
### * static.
- It's sometimes a useful keyword. It is a common misbelief that the only purpose is to make a variable stay in memory. When you declare a function or global variable as static it will become internal. You cannot access the function or variable through the extern (see below) keyword from other files in your project.

### * register. 
- Is a hint to the compiler to attempt to optimize the storage of the given variable by storing it in a register of the computer's CPU when the program is run. Most optimizing compilers do this anyway, so use of this keyword is often unnecessary. In fact, ANSI C states that a compiler can ignore this keyword if it so desires – and many do. Microsoft Visual C++ is an example of an implementation that completely ignores the register keyword.

### Placeholder codes. 
The printf function is a powerful function, and is probably the most-used function in C programs.
For example, ```int main(void) { printf("19+31 is "); }``` but damn! ```printf``` only prints strings! Thankfully, ```printf``` has methods for printing numbers. What we do is put a placeholder format code in the string. We write: ```printf("19+31 is %d", 19+31);```. The placeholder %d literally "holds the place" for the actual number that is the result of adding 19 to 31.
#### These placeholders are called format specifiers.
```
• %d - int (same as %i)
• %ld - long int (same as %li)
• %f - float
• %lf - double
• %c - char
• %s - string
• %x - hexadecimal
```

### Input using scanf(). 
The ```scanf()``` function is the input method equivalent to the ```printf()``` output function, simple yet powerful. The ```scanf()``` function requires the memory address of the variable to which you want to save the input value which uses the simple technique is to use the ```address-of operator, &```.
#### Note on inputs:
When data is typed at a keyboard, the information does not go straight to the program that is running. It is first stored in what is known as a buffer - a small amount of memory reserved for the input source.
