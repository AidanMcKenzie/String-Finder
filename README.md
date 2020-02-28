# String Finder

Submitted in Fevruary 2016 for the Programming Fundamentals module (SET07109), as part of the BEng Software Engineering (Hons) degree at Edinburgh Napier University.

## Description

The program (find.c) is designed to read a user specified text file and search for a single string that the user specifies.
The application will find the specified string within the text file and will print the string, the line number it was found on and
the whole line itself where the string was located, to give context for the string. It will print the results to an output text file.

The application does not require a text file to already exist for the output file. The application will create an output file with the
name of what the user enters.

In the event that no input text file is given, the program will instead read in text that the user inputs in the console. It behaves
similarly in that it will show the user the string, line number and the whole line when the string is located when it is printed.

In the event that no output text file is given, the program will instead print to the console. It behaves functionally the same as if
it was printed to a text file.

The user can also specify if case is to be ignored. This means that a search for 'Hello World!' and 'HELLO WORLD!' will result in the
same output.

The program is compiled using Microsoft C/C++ Compiler.

## How to Use

The application must first be built using the find.mak makefile using the following command: 
```
nmake find.mak
```
The makefile builds the application and runs three test searches on three text files, using different types of searches each time. The makefile then cleans up
by deleting any .exes or .obj files created during the tests. The user will then be able to make their own search.


'keyword', 'input.txt' and 'output.txt' are only sample names for the following instructions.

If the user wants to include an input file and output file searches must be made in the following format or errors may occur:
```
find keyword -i input.txt -o output.txt
```

If the user wants to input into the console, leave -i out:
```
find keyword -o output.txt
```

If the user wants to print search results to the console, leave -o out:
```
find keyword -i input.txt
```

The user can use any combination of -i and -o, using one and not the other, neither or both.

The user can also append '-c' to indicate that case will be ignored, like so:
```
find keyword -i input.txt -o output.txt -c
```

There is one exception to the correct format of the searches, the input and output specification can be swapped around like so:
```
find -o output.txt -i input.txt -c
```

Failure to adhere to the correct format of searching may result in errors.

### Description of Makefile

The makefile find.mak consists of the commands:
```
cl find.c
find "Boba Fett" -i empire.txt -o boba.txt
find footloose -i footloose.txt -c
find obama -i snowden.txt -o obama.txt -c
	
cl find.c
```

Step-by-step, this is:

* Compile the program
* Find the string "Boba Fett" in the file 'empire.txt' and output to the file 'boba.txt'
* Find the string 'footloose' in the file 'footloose.txt' and output to the console. Also ignore case.
* Find the string 'obama' in the file 'snowden.txt' and output to the file 'obama.txt'. Also ignore case.
* Compile the program (So the user can search for something)

### Files Used for this Application

* find.c (C source file containing code)
* find.mak (Makefile which builds the application, runs some test searches and allows the user to make searches)
* A collection of three text (.txt) files to test the application on, consisting of:
	* empire.txt (The script to the 1980 film 'The Empire Strikes Back')
	* footloose.txt (The lyrics to the 1984 song 'Footloose', recorded by Kenny Loggins)
	* snowden.txt (A transcript of an interview with American whistleblower Edward Snowden)