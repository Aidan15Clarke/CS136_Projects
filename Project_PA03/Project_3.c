// header files
#include "Console_IO_Utility.h"

// global constants
    // Minimum Arizona Tax, %
const double MIN_AZ_TAX = 2.59;
    // Maximum Arizona Tax, %
const double MAX_AZ_TAX = 4.50;
    // Minimum Federal Tax, %
const double MIN_FED_TAX = 10.00;
    // Maximum Federal Tax, %
const double MAX_FED_TAX = 37.00;
    // SSN Tax, %
const double TAX_SSN = 6.20;
    // MC Tax, %
const double TAX_MC = 1.45;
    // Percent Conversion, ratio
const double PERCENTAGE_CONVERSION = 0.01;

    // printing related constants
const int TWO_ENDLINES = 2;
    // constants for table
const int TABLE_WIDTH = 52;
const int DATA_NAME_WIDTH = 20;
const int UNIT_WIDTH = 7;
const int VALUE_WIDTH = 10;
const char TOP_LINE[]
                = "====================================================";
const char THICK_LINE_DIVIDER[]
                = "|==================================================|";
const char THIN_LINE_DIVIDER[]
                = "|--------------------------------------------------|";
const char PIPE_SPACE[] = "| ";
const char SPACE_PIPE[] = " |";

// function prototypes
    // none

// main program
int main()
    {
    // TODO: Write program as specified
    // show title
        // function: printString, printEndline(s)
    printString( "Dummy tax calculator\n" );
    printString( TOP_LINE );
    printEndlines( TWO_ENDLINES );

    // initialize variables/functions
    double totalIncome, contributionToIRA, adjustedIncome;
    double minTaxFederal, maxTaxFederal, minTaxArizona, maxTaxArizona;
    double taxSSN, taxMC, minTaxTotal, maxTaxTotal;
    double maxIncome, minIncome;
    double minEffectiveTax, maxEffectiveTax;

    // get user input
       // section title
        // functions: printString, promptForDouble, printEndline
    printString( "Please provide your information below.\n" );
    totalIncome = promptForDouble( "Total income $: " );
    contributionToIRA = promptForDouble( "Your IRA contributions $: " );
    printEndline();

    // conduct computations
      // calculate adjustedIncome
    adjustedIncome = totalIncome - contributionToIRA;

      //calculate minTaxFederal
    minTaxFederal = MIN_FED_TAX * PERCENTAGE_CONVERSION * adjustedIncome;

      //calculate maxTaxFederal
    maxTaxFederal = MAX_FED_TAX * PERCENTAGE_CONVERSION * adjustedIncome;

      //calculate minTaxArizona
    minTaxArizona = MIN_AZ_TAX * PERCENTAGE_CONVERSION * adjustedIncome;

      //calculate maxTaxArizona
    maxTaxArizona = MAX_AZ_TAX * PERCENTAGE_CONVERSION * adjustedIncome;

      //calculate taxSSN
    taxSSN = TAX_SSN * PERCENTAGE_CONVERSION * adjustedIncome;

      //calculate taxMC
    taxMC = TAX_MC * PERCENTAGE_CONVERSION * adjustedIncome;

      //calculate minTaxTotal
    minTaxTotal = minTaxFederal + minTaxArizona + taxSSN + taxMC;

      //calculate maxTaxTotal
    maxTaxTotal = maxTaxFederal + maxTaxArizona + taxSSN + taxMC;

      //calculate minEffectiveTax
    minEffectiveTax = minTaxTotal / totalIncome /
                                        PERCENTAGE_CONVERSION;

      //calculate maxEffectiveTax
    maxEffectiveTax = maxTaxTotal / totalIncome /
                                          PERCENTAGE_CONVERSION;

      // calculate minIncome
    minIncome = totalIncome - maxTaxTotal;

      // calculate maxIncome
    maxIncome = totalIncome - minTaxTotal;

    // show results

    // display results
       // print top line
          // function: printString, printEndline
    printEndline();
    printString( TOP_LINE );
    printEndline();

    // print title line
        // function: printCharacter, printStringJustified, printEndline
    printCharacter( PIPE );
    printStringJustified( "DUMMY TAX CALCULATIONS",
                                                  TABLE_WIDTH - 2, "CENTER" );
    printCharacter( PIPE );
    printEndline();

    // print thick divider line
        // function: printString, printEndline
    printString( THICK_LINE_DIVIDER );
    printEndline();

    // print sub title line
       // function: printStringJustified, printString, printCharacter,
       //    printEndline
    printString( PIPE_SPACE );
    printStringJustified( "Data Name", DATA_NAME_WIDTH - 1, "LEFT" );
    printCharacter( PIPE );
    printStringJustified( "Units", UNIT_WIDTH, "CENTER" );
    printString( PIPE_SPACE );
    printStringJustified( "MIN", VALUE_WIDTH - 2, "CENTER" );
    printString( SPACE_PIPE );
    printStringJustified( "MAX", VALUE_WIDTH - 1, "CENTER" );
    printString( SPACE_PIPE );
    printEndline();

    // print thin divider line
       // function: printString, printEndline
    printString( THICK_LINE_DIVIDER );
    printEndline();

    // print Effective tax rate
       // function: printStringJustified, printString, printCharacter,
       //    printEndline
    printString( PIPE_SPACE );
    printStringJustified( "Effective tax rate ", DATA_NAME_WIDTH - 1, "LEFT" );
    printCharacter( PIPE );
    printStringJustified( "%", UNIT_WIDTH, "CENTER" );
    printCharacter( PIPE );
    printDoubleJustified( minEffectiveTax, PRECISION,
                                                  VALUE_WIDTH -1, "RIGHT" );
    printString( SPACE_PIPE );
    printDoubleJustified( maxEffectiveTax, PRECISION,
                                                  VALUE_WIDTH - 1, "RIGHT" );
    printString( SPACE_PIPE );
    printEndline();

    // print thin divider line
       // function: printString, printEndline
    printString( THIN_LINE_DIVIDER );
    printEndline();

    // Total tax payed
       // function: printStringJustified, printString, printCharacter,
       //    printEndline
    printString( PIPE_SPACE );
    printStringJustified( "Total tax payed ", DATA_NAME_WIDTH - 1, "LEFT" );
    printCharacter( PIPE );
    printStringJustified( "$", UNIT_WIDTH, "CENTER" );
    printCharacter( PIPE );
    printDoubleJustified( minTaxTotal, PRECISION, VALUE_WIDTH -1, "RIGHT" );
    printString( SPACE_PIPE );
    printDoubleJustified( maxTaxTotal, PRECISION, VALUE_WIDTH - 1, "RIGHT" );
    printString( SPACE_PIPE );
    printEndline();

    // print thin divider line
       // function: printString, printEndline
    printString( THIN_LINE_DIVIDER );
    printEndline();

    printString( PIPE_SPACE );
    printStringJustified( "Income after Tax ", DATA_NAME_WIDTH - 1, "LEFT" );
    printCharacter( PIPE );
    printStringJustified( "$", UNIT_WIDTH, "CENTER" );
    printCharacter( PIPE );
    printDoubleJustified( minIncome, PRECISION, VALUE_WIDTH -1, "RIGHT" );
    printString( SPACE_PIPE );
    printDoubleJustified( maxIncome, PRECISION, VALUE_WIDTH - 1, "RIGHT" );
    printString( SPACE_PIPE );
    printEndline();

    // print thick divider line
       // function: printString, printEndline
    printString( THICK_LINE_DIVIDER );
    printEndline();

    // end program / return program success
    return 0;
    }

// supporting functions
    // none
