// header files
#include <stdlib.h>
#include "Console_IO_Utility.h"
#include "File_Output_Utility.h"
#include "File_Input_Utility.h"

// global constants
const int EXPECTED_ARGUMENTS_COUNT = 2;
const char COMMA_CHAR = ',';
const char TAB_CHAR = '\t';

/*
Name: displayTable
Process: displays program title
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Returned: none
Device Input/Keyboard: none
Device Output/Monitor: title displayed as specified
Dependencies: Console IO Utilities tools
*/
void displayTable( char *allCharsArray, int charsCount, const char *fileName );

int getCharsCount( const char *fileName );

void storeCharsInArray( const char *fileName, char *allCharsArray );

void swapCommas( char *allCharsArray, int charsCount );

int main(int argc, char **argv)
  {
    // Initialize variables
    char fileName[ MAX_STR_LEN ];
    char* allCharsArray;
    int totalChars;
    bool check = true;

    // Check for expected arguments
    if(!(argc == EXPECTED_ARGUMENTS_COUNT))
      {
        // If not enough or too many arguments, set check to false
        check = false;
      }
    // If correct amount of arguments, continue with program
    else
      {
        // Set fileName to argument
          // functions: sprintf
        sprintf(fileName, argv[1]);

        // Get total number of characters
          // functions: getCharsCount
        totalChars = getCharsCount( fileName );

        // Allocate memory to array
          // functions: calloc
        allCharsArray = malloc(totalChars, sizeof(char));

        // Upload chars into array
          // functions: storeCharsInArray
        storeCharsInArray( fileName, allCharsArray );

        // Swap commas
          // functions: swapCommas
        swapCommas( allCharsArray, totalChars );

        displayTable( allCharsArray, totalChars, fileName );
      }

    // Return 0
    return 0;
  }

void displayTable( char *allCharsArray, int charsCount )
  {

  }

int getCharsCount( const char *fileName )
  {
    // Initialize variables
    int counter = 0;

    // Open file
      // functions: openInputFile
    openInputFile( fileName );

    // Get count of chars

      // Check for end of files
        // functions: checkForEndOfInputFile
    while( !checkForEndOfInputFile() )
      {
        // Read next char
          // functions: readRawCharFromFile
        readRawCharFromFile();

        // Iterate counter
        counter++;
      }

    // Close file
      // functions: closeInputFile
    closeInputFile();

    // Return counter
    return counter;
  }

void storeCharsInArray( const char *fileName, char *allCharsArray )
  {
    // Initialize variables
    int counter = 0;

    // Open file
      // functions: openInputFile
    openInputFile( fileName );

    // Check for end of file
      // functions: checkForEndOfInputFile
    while(!checkForEndOfInputFile())
      {
        // Store characters in array
          // functions: readCharacterFromFile
        allCharsArray[counter] = readCharacterFromFile();

        // Iterate counter
        counter++;
      }
  }

void swapCommas( char *allCharsArray, int charsCount )
  {
    // Initialize variables
    int iterator;

    // Loop through all chars in array
    for(iterator = 0; iterator < charsCount; iterator++)
      {
        // Check if char is comma
        if(allCharsArray[iterator] == COMMA_CHAR)
          {
            // Set comma char to tab char
            allCharsArray[iterator] = TAB_CHAR;
          }
      }
  }
