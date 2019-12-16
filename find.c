#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
	// Open input file
	FILE* inFile;
	// Open output text file
	FILE* outFile;
	// Used with '-i'
	int activateI = 0;
	// Used with '-o'
	int activateO = 0;
	// Used with '-c'
	int ignoreCase = 0;
	// Accumulator to determine line number
	int lineAcc = 1;
	// Character buffer for the current line
	char curLine[1000];
	

	// Loop through arguments
	for (int i=0; i<argc; ++i)
	{
		// If -i is present
		if (strcmp(argv[i], "-i") == 0)
		{
			activateI = 1;
			inFile = fopen(argv[i+1], "r");
		}
		
		// If -o is present
		if (strcmp(argv[i], "-o") == 0)
		{
			activateO = 1;
			outFile = fopen(argv[i+1], "w");
		}
		
		// If -c is present
		if (strcmp(argv[i], "-c") == 0)
		{
			ignoreCase = 1;
		}	
	}

	// If -i isn't detected, go to stdin
	if (activateI == 0)
	{
		inFile = stdin;
		printf("\nType something to find your query within it! Use CTRL+Z to exit.\n");
	}

	// If -o isn't detected, go to stdout
	if (activateO == 0)
	{
		outFile = stdout;
		printf("\nYou haven't specified an output file. Results will print to the console.\n\n\n");
	}
	
	// While characters are read from curLine
	while (fgets(curLine, sizeof(char) * 1000, inFile))
	{
		// If -c was entered by the user, 
		if (ignoreCase == 1)
		{
			// Make the string lower case
			strlwr(argv[1]);
			// Make the current line lower case
			strlwr(curLine);
		}
		
		// If argv[1] is detected in curLine
		if (strstr(curLine, argv[1]))
		{
			// Writes where and what line the search query was found to output file
			fprintf(outFile, "%s was found on Line %d : %s\n", argv[1], lineAcc, curLine);
		}
		
		// Increment line number acummulator
		lineAcc++;
	}
	
	// If File is still open, close it
	if(inFile)
	{
		fclose(inFile);
	}
	
	// If file is still open, close it
	if(outFile)
	{
		fclose(outFile);
	}
	return 0;
}