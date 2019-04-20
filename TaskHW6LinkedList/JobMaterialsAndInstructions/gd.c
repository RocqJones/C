//https://stackoverflow.com/questions/34780546/how-to-run-c-code-from-terminal
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>				// needed to use tolower()
#pragma warning(disable: 4996) // for Visual Studio Only

#define MAX_BOOKS 20
#define MAX_NAME_LENGTH 35

typedef enum { noble = 0, hayden } library; // enumeration type library

char * libNames[] = { "Noble", "Hayden" };
struct bookDetails {
	char bookName[MAX_NAME_LENGTH];
	int pubYear;    // publication year
	library libName;
	int noOfCopies;
};

struct bookDetails list[MAX_BOOKS]; // declare list of books
int count = 0; // the number of books currently stored in the list (initialized at 0)

			   // forward declaration of functions (already implmented)
void flushStdIn();
void executeAction(char);
void save(char* fileName);

// functions that need implementation:
int add(char* bookName_input, int pubYear_input, char* libName_input, int noOfCopies_input); // 20 points
void display();                         // 10 points
void sort();                            // 10 points
void load(char* fileName); // 10 points

int main() {
	load("Book_List.txt");// load list of books from file(if it exists). Initially there will be no file.
	char choice = 'i'; // initialized to a dummy value
	do {
		printf("\nCSE240 HW5\n");
		printf("Please enter your selection: \n");
		printf("\t a: add a new book to the list\n");
		printf("\t d: display entire list of books\n");
		printf("\t s: sort books by name\n");
		printf("\t q: quit\n");
		choice = tolower(getchar());
		flushStdIn();
		executeAction(choice);
	} while (choice != 'q');

	save("Book_List.txt"); // save list of books to file (overwrites, if it exists)
	return 0;
}

// flush out leftover '\n' characters
void flushStdIn() {
	char c;
	do
		c = getchar();
	while (c != '\n' && c != EOF);
}

// ask for details from user for the given selection and perform that action
void executeAction(char c) {
	char bookName_input[MAX_NAME_LENGTH];
	unsigned int pubYear_input, noOfCopies_input, add_result = 0;
	char libName_input[10];
	switch (c) {
	case 'a':
		// input book details from user
		printf("\nPlease enter book name: ");
		fgets(bookName_input);

		printf("Please enter publication year: ");
		scanf("%d", &pubYear_input);
		flushStdIn();

		printf("Please enter library name (noble/hayden): ");
		gets(libName_input);
		libName_input[strlen(libName_input) - 1] = '\0';// discard the trailing '\n' char

		printf("Please enter no. of copies of book: ");
		scanf("%d", &noOfCopies_input);
		flushStdIn();

		// add the book to the list
		add_result = add(bookName_input, pubYear_input, libName_input, noOfCopies_input);

		if (add_result == 0)
			printf("\nThat book is already on the list!\n");
		else
			printf("\nBook successfully added to the list!\n");

		break;
	case 's':sort();
		break;
	case 'd':display();
		break;
	case 'q':
		break;
	default: printf("%c is invalid input!\n", c);
	}
}

int findBook(char* bookName) {
	for (int i = 0; i < count; i++) {
		if (strcmp(list[i].bookName, bookName) == 0) {
			return i;
		}
	}
	return -1;
}

int add(char* bookName_input, int pubYear_input, char* libName_input, int noOfCopies_input) {
	if (findBook(bookName_input) >= 0) // check whether book already exists in the list
		return 0;

	struct bookDetails bd;
	//struct bookDetails bd;
	strcpy(bd.bookName, bookName_input);
	bd.pubYear = pubYear_input;
	bd.noOfCopies = noOfCopies_input;

	//if statement
	if (strcmp(libName_input, "noble") == 0){
		bd.libName = 0;
	}
	else {
		bd.libName = 1; }

	list[count] = bd;
	count++;
}


void display() {

		for (int i = 0; i < count; i++)
		{
			printf("\nBook name: %-20s\n", list[i].bookName);
			printf("Publication year: %-4d\n", list[i].pubYear);
			printf("Library: %s\n", libNames[list[i].libName]);
			printf("No. of copies: %-6d\n", list[i].noOfCopies);
		}
		printf("\n");
}

void sort() {
	struct bookDetails bookTemp;// needed for swapping book structs. Not absolutely necessary to use.

	for (int i = 0; i < count; i++) {
		for (int j = i + 1; j < count; j++) {
			if (strcmp(list[i].bookName, list[j].bookName) > 0) {
				bookTemp = list[i];
				list[i] = list[j];
				list[j] = bookTemp;
			}
		}
	}
	printf("\nBook list sorted! Use display option 'd' to view sorted list.\n");
}

// save() is called at the end of main()
// This function saves the array of structures to file. It is already implemented.
// You should understand how this code works so that you know how to use it for future homework.
// It will also help you with 'load' function.
void save(char* fileName) {
	FILE* file;
	int i, libnameValue = 0;
	file = fopen(fileName, "wb");

	fwrite(&count, sizeof(count), 1, file);// First, store the number of books in the list

										   // Parse the list and write book details to file1
	for (i = 0; i < count; i++) {
		fwrite(list[i].bookName, sizeof(list[i].bookName), 1, file);
		fwrite(&list[i].pubYear, sizeof(list[i].pubYear), 1, file);

		// convert enum to a number for storing
		if (list[i].libName == noble) {
			libnameValue = 0;               // 0 for noble
		}
		else
			libnameValue = 1;               // 1 for hayden

		fwrite(&libnameValue, sizeof(libnameValue), 1, file);
		fwrite(&list[i].noOfCopies, sizeof(list[i].noOfCopies), 1, file);
	}
	fclose(file);
}


void load(char* fileName) {
	FILE* file;
	int i, libnameValue = 0;
	file = fopen(fileName, "rb");

	//FILE* file;
	//int i, libnameValue = 0;
	//file = fopen(fileName, "rb");

	fread(&count, sizeof(count), 1, file);


	for (i = 0; i < count; i++) {
		fread(list[i].bookName, sizeof(list[i].bookName), 1, file);
		fread(&list[i].pubYear, sizeof(list[i].pubYear), 1, file);
		fread(&libnameValue, sizeof(libnameValue), 1, file);
		fread(&list[i].noOfCopies, sizeof(list[i].noOfCopies), 1, file);
	}
	fclose(file);
}
