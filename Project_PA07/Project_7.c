// header files
#include <time.h>
#include <stdlib.h>
#include "Console_IO_Utility.h"
#include "File_Input_Utility.h"
#include "File_Output_Utility.h"
#include "StandardConstants.h"

// global constants
const int MIN_RAND_COUNT = 1;
const int MAX_RAND_COUNT = 10;
const int MIN_RAND_LIMIT = 1;
const int MAX_RAND_LIMIT = 100000;
const int VALUES_IN_ONE_LINE = 5;

// function prototypes

/*
Name: calculateTotal
Process: accepts the one dimensional array and total count,
         sums up all the numbers, and returns the sum
Function input/parameters: the one dimensional array and total count
Function output/parameters: none
Function output/returned: sum of one dimensional array
Function input/keyboard: none
Device output/file: none
Dependencies: none
*/
int calculateTotal(int array[], int totalCount);

/*
Name: displayResults
Process: accepts appropriate data and displays results
         ONLY if values are found in the file
Function input/parameters: number of values in array (int),
                           one dimensional array (int[])
Function output/parameters: none
Function output/returned: none
Function input/keyboard: none
Device output/monitor: displays data results or error message
Device output/file: none
Dependencies: printf
*/
void displayResults(int sum, int totalCount);

/*
Name: downloadRandomValues
Process: accepts the file name and a min and max number of output values,
         finds a random num between the two values (inclusive),
         opens file, downloads that number of random nums as
         comma-delimited values, and closes file
Function input/parameters: file name (const char *), min and max values (int)
Function output/parameters: none
Function output/returned: none
Function input/keyboard: none
Device output/file: random numbers generated
Dependencies: openOutputFile, closeOutputFile, getRandBetween, printf
              writeStringToFile, writeIntegerToFile, writeEndlineToFile
*/
void downloadRandomValues(const char *fileName, int minVal, int maxVal);

/*
Name: getRandBetween
Process: accepts a low limit and high limit value and generates a value
         between them (inclusive), then returns it
Function input/parameters: low and high limit (int)
Function output/parameters: none
Function output/returned: random number
Function input/keyboard: none
Device output/file: none
Dependencies: rand
*/
int getRandBetween(int lowLim, int highLim);

/*
Name: printTitle
Process: prints the title of the program with a thick underline
Function input/parameters: none
Function output/parameters: none
Function output/returned: none
Function input/keyboard: none
Device output/monitor: prints title
Device output/file: none
Dependencies: printf
*/
void printTitle();

/*
Name: uploadData
Process: accepts the file name, opens the file,
         loads the one dimensional array with the data, closes the file,
         and returns the number of values. Otherwise the function returns zero
Function input/parameters: file name (const char *), one dimensional array
Function output/parameters: none
Function output/returned: number of values in array
Function input/keyboard: none
Device output/file: none
Dependencies: openInputFile, closeInputFile, checkForEndOfInputFile,
              readIntegerFromFile, readCharacterFromFile
*/
int uploadData(const char *fileName, int array[]);

// main program
int main()
  {
    // Initialize time
    srand(time(NULL));

    // Initialize variables
    int numOfValues, sum;
    int array[MAX_RAND_COUNT];
    char fileName[STD_STR_LEN];

    // Get input
      // Print title
        // functions: printTitle
    printTitle();
      // Get file name
        // functions: promptForString
    promptForString( "Enter the file name for random number generation: ",
                                                                     fileName );
    // Process file
      // Check if valid file
        // functions: openInputFile
    if(!openInputFile(fileName))
      {
        // If file doesn't exist, create file and fill with values
          // functions: downloadRandomValues
        downloadRandomValues(fileName, MIN_RAND_COUNT, MAX_RAND_COUNT);
      }

      // Upload data from file to array and get the number of values
        // functions: uploadData
    numOfValues = uploadData(fileName, array);

    // Calculate sum
      // functions: calculateTotal
    sum = calculateTotal(array, numOfValues);

    // Display results
      // functions: displayResults
    displayResults(sum, numOfValues);

    // End program
    return 0;
  }

/*
Name: calculateTotal
Process: accepts the one dimensional array and total count,
         sums up all the numbers, and returns the sum
Function input/parameters: the one dimensional array and total count
Function output/parameters: none
Function output/returned: sum of one dimensional array
Function input/keyboard: none
Device output/file: none
Dependencies: none
*/
int calculateTotal(int array[], int totalCount)
  {
    // Initialize variables
    int sum = 0;
    int index;

    // Loop through values and add to sum
    for(index = 0; index < totalCount; index++)
      {
        sum += array[index];
      }
    // Return sum
    return sum;
  }

/*
Name: displayResults
Process: accepts appropriate data and displays results
         ONLY if values are found in the file
Function input/parameters: number of values in array (int),
                           one dimensional array (int[])
Function output/parameters: none
Function output/returned: none
Function input/keyboard: none
Device output/monitor: displays data results or error message
Device output/file: none
Dependencies: printf
*/
void displayResults(int sum, int totalCount)
  {
    // Check if no values
    if(totalCount == 0)
      {
        // Display error
          // functions: printf
        printf("\nERROR: Data file not found. Program aborted.\n");
      }
    // Else, display results
    else
      {
        // Display results
          // functions: printf
        printf("\nTotal Sources of income : %d\n", totalCount);
        printf("\nTotal income            : %d\n", sum);
        printf("\nEnd Program");
      }
  }

/*
Name: downloadRandomValues
Process: accepts the file name and a min and max number of output values,
         finds a random num between the two values (inclusive),
         opens file, downloads that number of random nums as
         comma-delimited values, and closes file
Function input/parameters: file name (const char *), min and max values (int)
Function output/parameters: none
Function output/returned: none
Function input/keyboard: none
Device output/file: random numbers generated
Dependencies: openOutputFile, closeOutputFile, getRandBetween, printf
              writeStringToFile, writeIntegerToFile, writeEndlineToFile
*/
void downloadRandomValues(const char *fileName, int minVal, int maxVal)
  {
    // Initialize variables
    int numOfValues, randomNum, index;

    // Find number of values
    numOfValues = getRandBetween(minVal, maxVal);

    // Open file
    openOutputFile(fileName);

    // Loop through numOfValues-1 and write a random number to file
    for(index = 0; index < numOfValues - 1; index++)
      {
        // Generate random num and write to file
          // functions: getRandBetween, writeIntegerToFile, writeStringToFile
        randomNum = getRandBetween(MIN_RAND_LIMIT, MAX_RAND_LIMIT);
        writeIntegerToFile(randomNum);
        writeStringToFile(", ");

        // Check if fifth value on line, if so move to next line
          // functions: writeEndlineToFile
        if(index == VALUES_IN_ONE_LINE - 1)
          {
            writeEndlineToFile();
          }
      }

    // Fence post last random number
      // functions: getRandBetween, writeIntegerToFile
    randomNum = getRandBetween(MIN_RAND_LIMIT, MAX_RAND_LIMIT);
    writeIntegerToFile(randomNum);

    // Close file
      // functions: closeOutputFile
    closeOutputFile();
  }

/*
Name: getRandBetween
Process: accepts a low limit and high limit value and generates a value
         between them (inclusive), then returns it
Function input/parameters: low and high limit (int)
Function output/parameters: none
Function output/returned: random number
Function input/keyboard: none
Device output/file: none
Dependencies: rand
*/
int getRandBetween(int lowLim, int highLim)
  {
    // Initalize variables
    int randNum, range;

    // Calculate range
    range = highLim - lowLim + 1;

    // Generate random number
      // functions: rand
    randNum = rand() % range + lowLim;

    // Return random number
    return randNum;
  }

/*
Name: printTitle
Process: prints the title of the program with a thick underline
Function input/parameters: none
Function output/parameters: none
Function output/returned: none
Function input/keyboard: none
Device output/monitor: prints title
Device output/file: none
Dependencies: printf
*/
void printTitle()
  {
    // Print title
      // functions: printf
    printf("\nTotal Income From File Calculator\n");
    printf("=================================\n\n");
  }

/*
Name: uploadData
Process: accepts the file name, opens the file,
         loads the one dimensional array with the data, closes the file,
         and returns the number of values. Otherwise the function returns zero
Function input/parameters: file name (const char *), one dimensional array
Function output/parameters: none
Function output/returned: number of values in array
Function input/keyboard: none
Device output/file: none
Dependencies: openInputFile, closeInputFile, checkForEndOfInputFile,
              readIntegerFromFile, readCharacterFromFile
*/
int uploadData(const char *fileName, int array[])
  {
    // Initialize variables
    int index;

    // Define index
    index = 0;

    // Open file
      // functions: openInputFile
    openInputFile(fileName);

    // Upload data to array
      // functions: checkForEndOfInputFile
    while(!checkForEndOfInputFile())
      {
        // Upload data to array
          // readIntegerFromFile
        array[index] = readIntegerFromFile();

        // Read delimiter
          // functions: readCharacterFromFile
        readCharacterFromFile();

        // Iterate index
        index++;
      }

    // Check if the file is empty by checking if the first value in array is 0
    if(array[0] == 0)
      {
        // if the file is empty, set index = 0 for the return value
        index = 0;
      }

    // Close file
      // closeInputFile
    closeInputFile();

    // Return total number of values
    return index;
  }
