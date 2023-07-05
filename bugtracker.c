// C program for the
// Bug Tracking System

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to file the Bug into
// the Bug Tracking System
void filebug(int id)
{
	printf("**********");
	printf("FILING A BUG");
	printf("***********\n");

	// Current Time
	time_t CurrentTime;
	time(&CurrentTime);

	char name[20], bugtype[50];
	char bugdescription[1000];
	char bugpriority[30];
	int bugstatus;

	FILE* ptr;

	// User name
	printf("Enter your name:\n");
	scanf("%s", name);
	char ids[10];
	itoa(id, ids, 10);
	strcat(name, ids);
	char ex[] = ".txt";
	strcat(name, ex);

	// Filename of the Bug
	printf("Filename :%s\n", name);
	ptr = fopen(name, "w");

	// Case when file cannot be created
	if (ptr == NULL)
		printf("cannot create file!!!\n");

	fprintf(ptr, "DATE AND TIME : %s",
			ctime(&CurrentTime));

	// ID in the Text File
	fprintf(ptr, "BUG ID : %d\n", id);

	// Adding New Line in Text File
	fprintf(ptr, "\n");

	// Bug ID
	printf("BUG ID:%d\n", id);

	fprintf(ptr, "BUG FILED BY: %s\n",
			name);
	fprintf(ptr, "\n");

	printf("Enter bug type:\n");
	scanf(" %[^\n]", bugtype);

	// Bug Type
	fprintf(ptr, "TYPE OF BUG: %s",
			bugtype);
	fprintf(ptr, "\n");

	// Bug Priority
	printf("Enter bug priority:\n");
	scanf(" %[^\n]s", bugpriority);

	fprintf(ptr, "BUG PRIORITY: %s\n",
			bugpriority);
	fprintf(ptr, "\n");

	// Bug Description
	printf("Enter the bug description:\n");
	scanf(" %[^\n]s", bugdescription);

	fprintf(ptr, "BUG DESCRIPTION: %s\n",
			bugdescription);
	fprintf(ptr, "\n");

	printf("Status of bug:\n");
	printf("1. NOT YET ASSIGNED\n");
	printf("2.IN PROCESS\n 3.FIXED\n");
	printf("4.DELIVERED\n ENTER YOUR CHOICE:");

	int j;
	scanf("%d", &j);

	// Date and time of Bug Creation
	fprintf(ptr, "DATE AND TIME: %s",
			ctime(&CurrentTime));

	fprintf(ptr, "BUG STATUS:");

	// Switching for the Status of the
	// Bug
	switch (j) {
	case 1:
		fprintf(ptr, "NOT YET ASSIGNED\n");
		break;
	case 2:
		fprintf(ptr, "IN PROCESS\n");
		break;
	case 3:
		fprintf(ptr, "FIXED\n");
		break;
	case 4:
		fprintf(ptr, "DELIVERED\n");
		break;
	default:
		printf("invalid choice\n");
		break;
	}

	fclose(ptr);
}

// Function to Change the status
// of the Bug
void changestatus()
{
	printf("*************");
	printf("Change status");
	printf("**************\n");

	// Current Time
	time_t CurrentTime;
	time(&CurrentTime);

	FILE* file;
	char name[50];

	// Bug File name
	printf("Enter file name:\n");
	scanf("%s", name);
	char ex[] = ".txt";
	strcat(name, ex);

	// Opening the Bug in Append Mode
	file = fopen(name, "a");

	printf("\n 1. NOT YET ASSIGNED\n");
	printf(" 2.IN PROCESS\n 3.FIXED\n");
	printf(" 4.DELIVERED\n ENTER YOUR CHOICE:");

	// Change the Status
	int k;
	scanf("%d", &k);

	fprintf(file, "\n");
	fprintf(file, "DATE AND TIME : %s",
			ctime(&CurrentTime));

	fprintf(file, "BUG STATUS:");

	// Changing the status on the
	// basis of the user input
	switch (k) {
	case 1:
		fprintf(file, "NOT YET ASSIGNED\n");
		break;
	case 2:
		fprintf(file, "IN PROCESS\n");
		break;
	case 3:
		fprintf(file, "FIXED\n");
		break;
	case 4:
		fprintf(file, "DELIVERED\n");
		break;
	default:
		printf("invalid choice\n");
		break;
	}
	fclose(file);
}

// Function to report the Bug
// in the Bug Tracking System
void report()
{
	printf("**********");
	printf("REPORT");
	printf("**********\n");

	FILE* fp;
	char name[50];

	// Asking the Filename to report
	// the bug of the file
	printf("Enter file name:\n");
	scanf("%s", name);
	char ex[] = ".txt";
	strcat(name, ex);

	// Opening the file into the
	// Read mode
	fp = fopen(name, "r");

	char ch;
	ch = getc(fp);

	// Character of the File
	while (ch != EOF) {
		printf("%c", ch);
		ch = getc(fp);
	}

	fclose(fp);
	getch();
}

// Driver Code
void main()
{
	printf("***************");
	printf("BUG TRACKING SYSTEM");
	printf("***************\n");

	int number, i = 1;

	// Id initialised to 0
	int id = 0;

	// while loop to run
	while (i != 0) {
		printf("\n1. FILE A NEW BUG\n");
		printf("2. CHANGE THE STATUS OF THE BUG\n");
		printf("3. GET BUG REPORT\n4. EXIT");
		printf("\n\n ENTER YOUR CHOICE:");


		scanf("%d", &number);

		// Using switch to go case by case
		switch (number) {
		case 1:
			id++;

			// Creating a New Bug
			filebug(id);
			break;
		case 2:

			// Change Status of Bug
			changestatus();
			break;
		case 3:

			// Report the Bug
			report();
			break;
		case 4:
			i = 0;
			break;
		default:
			printf("\ninvalid entry");
			break;
		}
	}
}
