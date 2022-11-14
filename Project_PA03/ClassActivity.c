//header files
#include "Console_IO_Utility.h"

#define _USE_MATH_DEFINES
#include <math.h>

//global Constants
  const char DOUBLE_DASH = '=';
  const char CROSS = '+';

  const int TWO_ENDLINES = 2;
  const int TABLE_WIDTH = 65;
  const int MEASURED_BLOCK_WIDTH = 20;
  const int NAME_BLOCK_WIDTH = 29;
  const int VALUE_BLOCK_WIDTH = 12;
  const char PIPE_SPACE[] = "| ";
  const char SPACE_PIPE[] = " |";
  const char CROSS_SPACE[] = "+ ";
  const double TWO_PI = 2.0 * M_PI;

  int main()
    {
      //initalize Variables
      double indactance, current, resistance, frequency, capacitance;

      //print title
        //fucntions: printString, printEndline
      printString( "Indactance Calculation Program\n" );
      printString( "==============================\n" );
      printEndline();

      //get input
        //functions: promptForDouble, printEndline
      current = promptForDouble( "  Enter Current       (A): " );
      resistance = promptForDouble( "  Enter Resistance (Ohms): " );
      frequency = promptForDouble( "  Enter Frequency    (hz): " );
      capacitance = promptForDouble( "  Enter Capacitance   (F): " );
      printEndline();

      //calculate
      indactance = current * resistance;
      indactance /= ( TWO_PI * frequency * capacitance );

      //print results
        //functions: printCharacter(s), printStringJustified, printEndline(s)
        //    printDoubleJustified

      //print top line
      printCharacter( PIPE );
      printCharacters( TABLE_WIDTH, DOUBLE_DASH );
      printCharacter( PIPE );
      printEndline();

      //print title line
      printCharacter( PIPE );
      printStringJustified( "INDACTANCE CALCULATION PROGRAM",
                                                    TABLE_WIDTH, "CENTER" );
      printCharacter( PIPE );
      printEndline();

      //end program
      return 0;
    }
