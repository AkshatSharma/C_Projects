/*
 * Name: Akshat Sharma
 * Date: October 28, 2013
 * Course: CSCI 474:Operating Systems Concepts
 *
 * NOTE: To compile end the gcc -o command with -lrt, since clock_gettime() method has been used to record time
 * example command: gcc -o project1 Project1_Sharma_Akshat.c -lrt
 *
 * REFERENCES: http://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm
 * REFERENCES: http://www.tutorialspoint.com/c_standard_library/c_function_fseek.htm
 * REFERENCES: http://www.dreamincode.net/forums/topic/195643-runtime-with-fork-and-pipe/
 * REFERENCES: http://www.qnx.com/developers/docs/6.3.2/neutrino/lib_ref/c/clock_gettime.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/time.h>

// Declaration and initialization of the variables that are to be used
	int numberOfChildProcesses = 0;
	int numberOfLinesInFile = 0;
	int segmentForEachChild = 0;
	int fileNum = 0;
	char *fileName;

// this function gets the number of lines in file1.dat
int getNumberOfLinesInFirstFile()
{
	//Opens the file using File pointer
	FILE *file1 = fopen("file1.dat", "r");
	int fileReader;
	int numberOfLines_FileOne = 0;

	//Reads the file1.dat until it reaches the End of File
	while(fileReader != EOF)
	{
		fileReader = fgetc(file1);
		if(fileReader == '\n')
		{
			numberOfLines_FileOne++;
		}
	}

	//closes file
	fclose(file1);
	printf("\nNumber of lines in file1.dat = %d\n", numberOfLines_FileOne);
	return numberOfLines_FileOne++;
}

// this function gets the number of lines in file2.dat
int getNumberOfLinesInSecondFile()
{
	//Opens the file using File pointer
	FILE *file2 = fopen("file2.dat", "r");
	int fileReader;
	int numberOfLines_FileTwo = 0;

	//Reads the file1.dat until it reaches the End of File
	while(fileReader != EOF)
	{
		fileReader = fgetc(file2);
		if(fileReader == '\n')
		{
			numberOfLines_FileTwo++;
		}
	}

	//closes file
	fclose(file2);
	printf("\nNumber of lines in file2.dat = %d\n", numberOfLines_FileTwo);
	return numberOfLines_FileTwo++;
}

// this function gets the number of lines in file3.dat
int getNumberOfLinesInThirdFile()
{
	//Opens the file using File pointer
	FILE *file3 = fopen("file3.dat", "r");
	int fileReader;
	int numberOfLines_FileThree = 0;

	//Reads the file1.dat until it reaches the End of File
	while(fileReader != EOF)
	{
		fileReader = fgetc(file3);
		if(fileReader == '\n')
		{
			numberOfLines_FileThree++;
		}
	}

	//closes file
	fclose(file3);
	printf("\nNumber of lines in file3.dat = %d\n", numberOfLines_FileThree);
	return numberOfLines_FileThree++;
}

// this function gets the number of lines in file4.dat
int getNumberOfLinesInFourthFile()
{
	//Opens the file using File pointer
	FILE *file4 = fopen("file4.dat", "r");
	int fileReader;
	int numberOfLines_FileFour = 0;

	//Reads the file1.dat until it reaches the End of File
	while(fileReader != EOF)
	{
		fileReader = fgetc(file4);
		if(fileReader == '\n')
		{
			numberOfLines_FileFour++;
		}
	}

	//closes file
	fclose(file4);
	printf("\nNumber of lines in file1.dat = %d\n", numberOfLines_FileFour);
	return numberOfLines_FileFour++;
}

// function that decides which file is to be used
void fileToBeUsed()
{
	//Asks the user which file needs to be processed
	printf("\nPlease enter the file number you would like to use (1, 2, 3, 4): ");
	scanf("%d", &fileNum);
	
	/*
	 * if first file is selected, gets the number of lines in file1.dat
	 * and assigns file1.dat to the fileName pointer
	 */
	if(fileNum == 1)
	{
		printf("----Processing File 1-----\n");
		numberOfLinesInFile = getNumberOfLinesInFirstFile();
		fileName = "file1.dat";
	}

	/*
	 * if second file is selected, gets the number of lines in file2.dat
	 * and assigns file2.dat to the fileName pointer
	 */
	else if(fileNum == 2)
	{
		printf("----Processing File 2-----\n");
		numberOfLinesInFile = getNumberOfLinesInSecondFile();
		fileName = "file2.dat";
	}

	/*
	 * if third file is selected, gets the number of lines in file3.dat
	 * and assigns file3.dat to the fileName pointer
	 */
	else if(fileNum == 3)
	{
		printf("----Processing File 3-----\n");
		numberOfLinesInFile = getNumberOfLinesInThirdFile();
		fileName = "file3.dat";
	}

	/*
	 * if fourth file is selected, gets the number of lines in file4.dat
	 * and assigns file4.dat to the fileName pointer
	 */
	else if(fileNum == 4)
	{
		printf("----Processing File 4-----\n");
		numberOfLinesInFile = getNumberOfLinesInFourthFile();
		fileName = "file4.dat";
	}

	/*
	 * if an invalid is selected, the default file1 is selected 
	 * and gets the number of lines in file1.dat
	 * and assigns file1.dat to the fileName pointer
	 */
	else
	{
		printf("Invalid Entry, using default File 1\n");
		fileNum = 1;
		numberOfLinesInFile = getNumberOfLinesInFirstFile();
	}
}

// function to determine the number of child processes to be created
void numberOfChildProcessesToBeCreated()
{
	//Asks the user how many child processes needs to be created (1, 2, or 4)
	printf("\nPlease enter the number of child processes you would like to create (1, 2, or 4): ");
	scanf("%d", &numberOfChildProcesses);
	
	/*
	 * if user selects 1 child process to be created
	 * the variable to hold the child processes is assigned the value 1
	 */
	if(numberOfChildProcesses == 1)
	{
		numberOfChildProcesses = 1;
	}

	/*
	 * if user selects 2 child process to be created
	 * the variable to hold the child processes is assigned the value 4
	 */
	else if(numberOfChildProcesses == 2)
	{
		numberOfChildProcesses = 2;
	}

	/*
	 * if user selects 4 child process to be created
	 * the variable to hold the child processes is assigned the value 4
	 */
	else if(numberOfChildProcesses == 4)
	{
	      numberOfChildProcesses = 4;
	}

	/*
	 * if user selects an invalid number for the child process to be created
	 * the variable is assigned the default value to create 1 child process
	 */
	else
	{
		numberOfChildProcesses = 1;
		printf("Invalid choice, setting number of child processes to %d\n", numberOfChildProcesses);
	}
	
	// Prints the number of child processes to be used to the console
	printf("----Using %d Child Process-----\n", numberOfChildProcesses);
}

main()
{
	//Holds the child process id
	pid_t childprocess_id;

	#define BILLION 1E9

	// Array to hold the lower and upper bound Index which the parent will send to the child
	int sendIndexToChild[2];

	// Array to hold the lower and upper bound Index which the child will receive from the parent
	int receiveIndexFromParent[2];
	
	//4 pipes to send data from the parent to the maximum of 4 children
	int fd[4][2];

	// 4 pipes to send the total from a maximum of 4 children to the parent
	int fdp[4][2];

	//This variable will hold the data from the file
	char getValuesFromFile[230];

	// This variable will hold the sum from each child
	int sumOfEachChild;

	// This variable gets the sum from each child to the parent
	int getSumFromEachChild;

	// This variable holds the total from all children
	int totalFromAllChildren;

	// Variable holds the total time taken to execute the processes
	double totalTimeTaken;

	// Struct variables for holding the starting time of the program and ending time of the program
	// to calculate the total time for the processes
	struct timespec timerStart;
	struct timespec timerEnd;

	//Call the function to ask the user the number of Child processes to be created
	numberOfChildProcessesToBeCreated();

	//Call the function to ask the user which file needs to be processed
	fileToBeUsed();
	
	// Calculates the number of lines each segment will hold based on the number of child processes created
	segmentForEachChild = numberOfLinesInFile/numberOfChildProcesses;
	printf("Each child will process %d numbers\n\n", segmentForEachChild);

	//this function takes the starting time of the program
	clock_gettime(CLOCK_REALTIME, &timerStart);
	int x;

	// loops based on the number of child processes that will be created by the user
	for(x = 0; x < numberOfChildProcesses; x++)
	{
		//Storing the Lower bound for the segment
		sendIndexToChild[0] = x * segmentForEachChild;

		//Storing the Upper bound for the segment 
		sendIndexToChild[1] = (x+1)*segmentForEachChild;
		
		//The pipes are initialized based on the number of Child processes that are created by the user
		pipe(fd[x]);
		pipe(fdp[x]);

		//Sends the information of the indexes that needs to the operated on to the child using pipes (Write method)
		write(fd[x][1], sendIndexToChild, 2*sizeof(int));

		//Fork function call
	    childprocess_id = fork();
	    
		//If the child process id = 0, child processes successfully created
		if(childprocess_id == 0)
	      {
			  // receives the indexes that needs to be operated on from the parent using pipes (Read method)
			    read(fd[x][0],receiveIndexFromParent,2*sizeof(int));
				
				// Initializes the file pointer and opens the file in the "read" mode.
				FILE *fp = fopen(fileName, "r");

				// Since each line is 5 characters long, we put the offset at 5 to start reading the file, so that the bounds 
				// are not read twice, and we have a correct total
				fseek(fp, receiveIndexFromParent[0]*5, SEEK_SET);
				//Each Child calculates its individual sum with the current index received from the parent it is operating on
				
				/* 
				 * Loop for calculating the sum for each child process
				 * The loop operates on the index bounds received from the parent
				 * Using fgets, the values in the file are taken line by line and
				 * are stored the character array 'getValuesFromFile'.
				 * Then using the fseek function call, and setting the 'whence' parameter to SEEK_CUR
				 * we seek the newline and return characters and move forward to the next line. 
				 * The character stored in the character array are converted to int using the atoi function call, and
				 * then added to the sumOfEachChild variable, which hence returns the sum from each individual child process
				 */
				int z;
				for(z = receiveIndexFromParent[0]; z < receiveIndexFromParent[1]; z++)
				{
					fgets(getValuesFromFile,4,fp);
					fseek(fp,2,SEEK_CUR);
					sumOfEachChild+=atoi(getValuesFromFile);
				}

				// The sum from each individual child is printed to the terminal window
				printf("sum from Child %d is %d\n", x+1, sumOfEachChild);
				
				//The child writes the sum taken from each child to the parent using pipes
				write(fdp[x][1], &sumOfEachChild, sizeof(int));
				
				//file is closed
				fclose(fp);

				//Exit child process
				exit(0);	
	      }
	}

	// The parent now reads the information written by the child using pipes
	int j;
	for(j = 0; j < numberOfChildProcesses; j++)
	{
		//reads information from the children using pipes
		read(fdp[j][0],&getSumFromEachChild,sizeof(int));

		// Gets the sum from each child and adds it to the grand total.
		totalFromAllChildren+=getSumFromEachChild;
	}

	// This function call takes the ending time of the program
	clock_gettime(CLOCK_REALTIME, &timerEnd);

	//Prints the total sum received from all the children
	printf("\nTotal from all the children is %d\n", totalFromAllChildren);

	// The variable calculates and holds the total time during which the program was in execution.
	totalTimeTaken = (timerEnd.tv_sec - timerStart.tv_sec) + (timerEnd.tv_nsec - timerStart.tv_nsec) / BILLION;

	// Prints the total time taken by the program
	printf("The total time taken is: %lf secs\n\n", totalTimeTaken);
}
