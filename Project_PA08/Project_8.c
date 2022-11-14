// header files
#include <stdio.h>
#include "Console_IO_Utility.h"
#include "File_Output_Utility.h"
#include "File_Input_Utility.h"

// global constants
    // enumerator for column indexes
typedef enum { COLUMN_A, COLUMN_B, COLUMN_C, COLUMN_D, COLUMN_E } TableColumns;
    // enumarator for filing type
typedef enum { MARRIED, SINGLE, NONE } FilingFlag;
    // conversion into percent rate
const double PERCENT_CONVERSION = 0.01;
    // tax table properties
const char TAX_TABLE_R_COUNT = 4;
const char TAX_TABLE_C_COUNT = 5;
    // on demand data files
const char MARRIED_TAX_DATA[] = "married.csv";
const char SINGLE_TAX_DATA[] =  "single.csv";
const int TAX_DATA_TITLE_SIZE = 60;
    // output table columns size
const int OUT_TABLE_COLUMN_SIZE = 15;

// function prototypes
/*
Name: printProgramTitle
Process: displays program title
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Returned: none
Device Input/Keyboard: none
Device Output/Monitor: title displayed as specified
Dependencies: Console IO Utilities tools
*/
void printProgramTitle();

/*
Name: uploadTaxTable
Process: uploads table from file into 2d array
Function Input/Parameters: accepts name of the file which stores tax table
                           and reference to tax data array in which to store
                           tax data (use constants to set size of array)
Function Output/Parameters: none
Function Output/Returned: none
Device Input/Keyboard: none
Device Output/Monitor: none
Dependencies: openInputFile, readDoubleFromFile, skipOneRow,
              readCharacterFromFile
*/
void uploadTaxTable();

/*
Name: skipOneRow
Process: skips one line of input file
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Returned: none
Device Input/Keyboard: none
Device Output/Monitor: none
Dependencies: readStringToDelimiterFromFile OR readStringToLineEndFromFile
*/
void skipOneRow();

/*
Name: getTaxReturnType
Process: ask user for input and based on input assigns appropriate filing type
Function Input/Parameters: none
Function Output/Parameters: none
Function Output/Returned: returns filling type either SINGLE or MARRIED
Device Input/Keyboard: character either m/M/s/S
Device Output/Monitor: none
Dependencies: promptForCharacter
*/
FilingFlag getTaxReturnType();

/*
Name: displayTaxTable
Process: based on filling type prints apropriate title for table
         and calls for table to be displayed
Function Input/Parameters: table containing tax data and filing type
Function Output/Parameters: none
Function Output/Returned: none
Device Input/Keyboard: none
Device Output/Monitor: title for table
Dependencies: displayCorrectTable, printf
*/
void displayTaxTable();

/*
Name: displayCorrectTable
Process: displays tax data table
Function Input/Parameters: table containing tax data
Function Output/Parameters: none
Function Output/Returned: none
Device Input/Keyboard: none
Device Output/Monitor: iteratively prints table as shown in examples
Dependencies: printCharacter, printDoubleJustified, printf
*/
void displayCorrectTable( int array[][] );

/*
Name: calculateTax
Process: identifies correct tax bracket using tax data from array and income
         calculates tax using tax data from array as well as with
         formula presented below
         TT = ((TI + Col_C) * Col_D %) + Col_E
         , where
         TT - Total Tax
         TI - Total Income
         Col_C - COLUMN_C (same as maximum limit of previous tax bracket)
         Col_D - COLUMN_D (same as rate, must be converted into %)
         Col_E - COLUMN_E (same as max possible tax for all previous brackets)

Function Input/Parameters: tax data aray and total income
Function Output/Parameters: none
Function Output/Returned: total tax
Device Input/Keyboard: none
Device Output/Monitor: none
Dependencies: none
*/
double calculateTax( );

int main()
  {
    // Initialize variables


    // Get input

      // Print title
        // functions: printProgramTitle
    printProgramTitle();

      // Request input
        // functions: promptForDouble, promptForCharacter

    // Process data

      // Upload tax table
        // functions: uploadTaxTable

      // Conduct tax calculations
        // functions: calculateTax

    // Display results
      // functions: displayTaxTable

    // End program
      // functions: printf
    printf("End Program\n\n\n");

    // Return 0
    return 0;
  }

  /*
  Name: printProgramTitle
  Process: displays program title
  Function Input/Parameters: none
  Function Output/Parameters: none
  Function Output/Returned: none
  Device Input/Keyboard: none
  Device Output/Monitor: title displayed as specified
  Dependencies: Console IO Utilities tools
  */
  void printProgramTitle()
    {
      printf("Basic Arizona Tax Calculator\n");
      printf("==============================\n\n");
    }

  /*
  Name: uploadTaxTable
  Process: uploads table from file into 2d array
  Function Input/Parameters: accepts name of the file which stores tax table
                             and reference to tax data array in which to store
                             tax data (use constants to set size of array)
  Function Output/Parameters: none
  Function Output/Returned: none
  Device Input/Keyboard: none
  Device Output/Monitor: none
  Dependencies: openInputFile, readDoubleFromFile, skipOneRow,
                readCharacterFromFile, closeInputFile
  */
  void uploadTaxTable( char *fileName, double *array )
    {
      // Initialize variables
      int iteratorOne, iteratorTwo;

      // Open file
        // functions: openInputFile
      openInputFile( fileName );

      // Skip first row
        // functions: skipOneRow
      skipOneRow();

      // Upload data from file into array
      for( iteratorOne = 0; iteratorOne < TAX_TABLE_R_COUNT; iteratorOne++ )
        {
          for(iteratorTwo = 0; iteratorTwo < TAX_TABLE_C_COUNT; iteratorTwo++)
            {
              // Upload data into array
                // functions: readDoubleFromFile
              array[ iteratorOne ][ iteratorTwo ] = readDoubleFromFile();

              // Check for end of line
              if( iteratorTwo < TAX_TABLE_C_COUNT-1 )
                {
                  // Read comma between data
                    // functions: readCharacterFromFile
                  readCharacterFromFile();
                }
            }
        }

        // Close file
          // functions: closeInputFile
        closeInputFile();
    }

  /*
  Name: skipOneRow
  Process: skips one line of input file
  Function Input/Parameters: none
  Function Output/Parameters: none
  Function Output/Returned: none
  Device Input/Keyboard: none
  Device Output/Monitor: none
  Dependencies: readStringToDelimiterFromFile OR readStringToLineEndFromFile
  */
  void skipOneRow()
    {
      readStringToLineEndFromFile();
    }

  /*
  Name: getTaxReturnType
  Process: ask user for input and based on input assigns appropriate filing type
  Function Input/Parameters: none
  Function Output/Parameters: none
  Function Output/Returned: returns filling type either SINGLE or MARRIED
  Device Input/Keyboard: character either m/M/s/S
  Device Output/Monitor: none
  Dependencies: promptForCharacter
  */
  FilingFlag getTaxReturnType();

  /*
  Name: displayTaxTable
  Process: based on filling type prints apropriate title for table
           and calls for table to be displayed
  Function Input/Parameters: table containing tax data and filing type
  Function Output/Parameters: none
  Function Output/Returned: none
  Device Input/Keyboard: none
  Device Output/Monitor: title for table
  Dependencies: displayCorrectTable, printf
  */
  void displayTaxTable();

  /*
  Name: displayCorrectTable
  Process: displays tax data table
  Function Input/Parameters: table containing tax data
  Function Output/Parameters: none
  Function Output/Returned: none
  Device Input/Keyboard: none
  Device Output/Monitor: iteratively prints table as shown in examples
  Dependencies: printCharacter, printDoubleJustified, printf
  */
  void displayCorrectTable( int array[][] );

  /*
  Name: calculateTax
  Process: identifies correct tax bracket using tax data from array and income
           calculates tax using tax data from array as well as with
           formula presented below
           TT = ((TI + Col_C) * Col_D %) + Col_E
           , where
           TT - Total Tax
           TI - Total Income
           Col_C - COLUMN_C (same as maximum limit of previous tax bracket)
           Col_D - COLUMN_D (same as rate, must be converted into %)
           Col_E - COLUMN_E (same as max possible tax for all previous brackets)

  Function Input/Parameters: tax data aray and total income
  Function Output/Parameters: none
  Function Output/Returned: total tax
  Device Input/Keyboard: none
  Device Output/Monitor: none
  Dependencies: none
  */
double calculateTax(double taxData[][], double income)
  {

  }
