// header files
#include "StandardConstants.h"
#include "Console_IO_Utility.h"
#include "File_Input_Utility.h"
#include "File_Output_Utility.h"
#include "Arizona_Tax_Utility.h"

// TODO

// constants
    // none

// function prototypes

/*
Name: createOutputString
Process: creates string to be displayed and output to file;
         only one string can be assembled in the function
Function input/parameters:  the output string pointer, tax year and total tax
Function output/parameters: the generated output string (char *)
Function output/returned: none
Function input/keyboard: none
Device output/file: none
Dependencies: sprintf
*/
// TODO
void createOutputString(char *outputString, int taxYear, double totalTax);

/*
Name: outputResultsToFile
Process: opens file for output, writes string to file with endline,
         closes file
Function input/parameters: file name (const char *),
                           output string (const char *)
Function output/parameters: none
Function output/returned: none
Function input/keyboard: none
Device output/file: none
Dependencies: File Output Utility tools
*/
// TODO
void outputResultsToFile( const char *fileName, const char *outputString);

// main program
int main()
    {

     // TODO

      // Initialize variables
      char taxInformationFile[ STD_STR_LEN ], outputString[ STD_STR_LEN ],
           outputFileName[ STD_STR_LEN ];
      double income, totalTax;
      int taxYear, counter;

      // Print title
          // functions: printf
      printf( "\nDUMMY TAX CALCULATOR V0.4 \n" );
      printf( "=========================== \n\n" );

      // Request for input
        // functions: promptForString, printEndline
      promptForString( "Enter file name containing income information: ",
                                                           taxInformationFile );
      printEndline();

      // Check if valid file / prime loop
        // functions: openInputFile
      if( openInputFile(taxInformationFile) )
        {
          // Define counter
          counter = 0;
          // Read taxYear from file
            // functions: readIntegerFromFile
          taxYear = readIntegerFromFile();

        // Loop through data in tax file
          // Check if end of file
          while( taxYear != 0 )
            {
              // Read income from file
                // functions: readDoubleFromFile
              income = readDoubleFromFile();

              // Calculate Arizona tax
                // functions: calculateArizonaTax
              totalTax = calculateArizonaTax( income );

              // Create output string
                // functions: createOutputString
              createOutputString( outputString, taxYear, totalTax );

              // Update file name
                // functions: sprintf
              sprintf( outputFileName, "Tax_Report_%d.txt", taxYear );

              // Output string to file
                // functions: outputResultsToFile
              outputResultsToFile( outputFileName, outputString );

              // Read next taxYear from file / reprime loop
                // functions: readIntegerFromFile
              taxYear = readIntegerFromFile();

              // Iterate counter
              counter++;
            }

          // Print results
            // functions: printf
          printf("Arizona Tax for %d years has been calculated. \n\n", counter);
          printf("The results can be viewed in the report files. \n\n");
          printf("Program End");
        }
      else
        {
          printf( "Error: File name not recognized \n\n" );
          printf( "Program End" );
        }

      // End program
      return 0;
    }


// supporting functions

// TODO

/*
Name: createOutputString
Process: creates string to be displayed and output to file;
         only one string can be assembled in the function
Function input/parameters:  the output string pointer, tax year and total tax
Function output/parameters: the generated output string (char *)
Function output/returned: none
Function input/keyboard: none
Device output/file: none
Dependencies: sprintf
*/
void createOutputString(char *outputString, int taxYear, double totalTax)
{
  // Create string to output
    //functions: sprintf
  sprintf(outputString,
               "For the tax year %d total AZ tax to be payed is %0.2f $.",
                                                             taxYear, totalTax);
}

/*
Name: outputResultsToFile
Process: opens file for output, writes string to file with endline,
         closes file
Function input/parameters: file name (const char *),
                           output string (const char *)
Function output/parameters: none
Function output/returned: none
Function input/keyboard: none
Device output/file: none
Dependencies: File Output Utility tools
*/
void outputResultsToFile( const char *fileName, const char *outputString)
  {
    // Create file
    openOutputFile( fileName );
    writeStringToFile( outputString );
    closeOutputFile();
  }
