// header files
#include "Console_IO_Utility.h"

// global constants
    //AZ taxes
        // AZ tax Baseline RATE
const double AZ_TAX_BASELINE_RATE = 0.0259;
        // AZ tax Baseline LIMIT
const double AZ_TAX_BASELINE_LIMIT = 27808.5;
        // AZ tax First bracket RATE
const double AZ_TAX_FIRST_BRACKET_RATE = 0.0334;
        // AZ tax First bracket LIMIT
const double AZ_TAX_FIRST_BRACKET_LIMIT = 55615.5;
        // AZ tax Second bracket RATE
const double AZ_TAX_SECOND_BRACKET_RATE = 0.0417;
        // AZ tax Second bracket LIMIT
const double AZ_TAX_SECOND_BRACKET_LIMIT = 166843.5;
        // AZ tax MAX bracket RATE
const double AZ_TAX_MAX_RATE = 0.045;

    // Federal taxes
        // Minimum FED Tax RATE
const double FED_TAX_BASELINE_RATE = 0.1000;
        // FED tax Baseline LIMIT
const double FED_TAX_BASELINE_LIMIT = 10275.5;
        // FED tax First bracket RATE
const double FED_TAX_FIRST_BRACKET_RATE = 0.1200;
        // FED tax First bracket LIMIT
const double FED_TAX_FIRST_BRACKET_LIMIT = 41775.5;
        // FED tax Second bracket RATE
const double FED_TAX_SECOND_BRACKET_RATE = 0.2200;
        // FED tax Second bracket LIMIT
const double FED_TAX_SECOND_BRACKET_LIMIT = 89075.5;
        // FED tax Third bracket RATE
const double FED_TAX_THIRD_BRACKET_RATE = 0.2400;
        // FED tax Third bracket LIMIT
const double FED_TAX_THIRD_BRACKET_LIMIT = 170050.5;
        // FED tax Fourth bracket RATE
const double FED_TAX_FOURTH_BRACKET_RATE = 0.3200;
        // FED tax Fourth bracket LIMIT
const double FED_TAX_FOURTH_BRACKET_LIMIT = 215950.5;
        // FED tax Fifth bracket RATE
const double FED_TAX_FIFTH_BRACKET_RATE = 0.3500;
        // FED tax Fifth bracket LIMIT
const double FED_TAX_FIFTH_BRACKET_LIMIT = 539900.5;
        // AZ tax MAX bracket RATE
const double FED_TAX_MAX_RATE = 0.3700;

    // Other Taxes
        // SSN Tax RATE
const double TAX_SSN = 0.0620;
        // MC Tax RATE
const double TAX_MC = 0.0145;


    // Percent Conversion, ratio
const double PERCENTAGE_CONVERSION = 100;

    // printing related constants
const int TWO_ENDLINES = 2;
    // constants for table
const int TABLE_WIDTH = 46;
const int DATA_NAME_WIDTH = 20;
const int UNIT_WIDTH = 7;
const int VALUE_WIDTH = 15;
const char TOP_LINE[]
                = "==============================================";
const char THICK_LINE_DIVIDER[]
                = "|============================================|";
const char THIN_LINE_DIVIDER[]
                = "|--------------------------------------------|";
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
    printEndline();
    printString( "Dummy tax calculator V0.2" );
    printEndline();
    printString( TOP_LINE );
    printEndlines( TWO_ENDLINES );


    // initialize variables/functions
    double totalIncome, contributionToIRA, adjustedIncome;
    double taxBracketRateAZ, taxBracketRateFed;
    double taxFederal, taxArizona;
    double taxSSN, taxMC, taxTotal;
    double incomeAfterTaxes;
    double effectiveTax, incomeLocked;

    // get user input
       // section title
           // function: printString, printEndline, promptForDouble
    printString( "Provide your Tax information below.\n" );
    totalIncome = promptForDouble( "Total income $: " );
    contributionToIRA = promptForDouble( "Your IRA contributions $: " );

    // TODO

        // adjust income and set fed and arizona tax to max
    adjustedIncome = totalIncome - contributionToIRA;
    taxBracketRateAZ = AZ_TAX_MAX_RATE;
    taxBracketRateFed = FED_TAX_MAX_RATE;

      // determine Arizona and Fed tax bracket
        // functions: printString

    // check if income is higher than fifth fed bracket
    if(adjustedIncome > FED_TAX_FIFTH_BRACKET_LIMIT)
       {
         printString( "User is too rich, call IRS! \n" );
       }
    // check all other brackets
    else
       {
         // check if income is below fed baseline
         if(adjustedIncome < FED_TAX_BASELINE_LIMIT)
            {
              taxBracketRateFed = FED_TAX_BASELINE_RATE;
              taxBracketRateAZ = AZ_TAX_BASELINE_RATE;
            }
          // check if income is below az baseline
          else if(adjustedIncome < AZ_TAX_BASELINE_LIMIT)
             {
               taxBracketRateFed = FED_TAX_FIRST_BRACKET_RATE;
               taxBracketRateAZ = AZ_TAX_BASELINE_RATE;
             }
          // check if income is below first fed bracket
          else if(adjustedIncome < FED_TAX_FIRST_BRACKET_LIMIT)
             {
               taxBracketRateFed = FED_TAX_FIRST_BRACKET_RATE;
               taxBracketRateAZ = AZ_TAX_FIRST_BRACKET_RATE;
             }
          // check if income is below first arizona bracket
          else if(adjustedIncome < AZ_TAX_FIRST_BRACKET_LIMIT)
             {
               taxBracketRateFed = FED_TAX_SECOND_BRACKET_RATE;
               taxBracketRateAZ = AZ_TAX_FIRST_BRACKET_RATE;
             }
          // check if income is below second fed bracket
          else if(adjustedIncome < FED_TAX_SECOND_BRACKET_LIMIT)
             {
               taxBracketRateFed = FED_TAX_SECOND_BRACKET_RATE;
               taxBracketRateAZ = AZ_TAX_SECOND_BRACKET_RATE;
             }
          // check if income is below second arizona bracket
          else if(adjustedIncome < AZ_TAX_SECOND_BRACKET_LIMIT)
             {
               taxBracketRateFed = FED_TAX_THIRD_BRACKET_RATE;
               taxBracketRateAZ = AZ_TAX_SECOND_BRACKET_RATE;
             }
          // check if income is below third fed bracket
          else if(adjustedIncome < FED_TAX_THIRD_BRACKET_LIMIT)
             {
               taxBracketRateFed = FED_TAX_THIRD_BRACKET_RATE;
             }
          // else, user is in fourth fed bracket
          else
             {
               taxBracketRateFed = FED_TAX_FOURTH_BRACKET_RATE;
             }
       }


    // TODO

        // calculate federal tax, $
    taxFederal = adjustedIncome * taxBracketRateFed;
        // calculate AZ tax, $
    taxArizona = adjustedIncome * taxBracketRateAZ;
        // calculate SSN tax, $
    taxSSN = adjustedIncome * TAX_SSN;
        // calculate MC tax, $
    taxMC =  adjustedIncome * TAX_MC;
        // calculate Total tax to be payed, $
    taxTotal = taxFederal + taxArizona + taxSSN + taxMC;
        // calculate Income after Tax, $
    incomeAfterTaxes = totalIncome - taxTotal;
        // calculate effective tax rate, %
    effectiveTax = taxTotal / totalIncome;
        // calculate % of income locked in IRA, %
    incomeLocked = (contributionToIRA / totalIncome) * PERCENTAGE_CONVERSION;

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
    printStringJustified( "Value", VALUE_WIDTH - 2, "CENTER" );
    printString( SPACE_PIPE );
    // printStringJustified( "MAX", VALUE_WIDTH - 1, "CENTER" );
    // printString( SPACE_PIPE );
    printEndline();

    // print thin divider line
       // function: printString, printEndline
    printString( THICK_LINE_DIVIDER );
    printEndline();

        // print Effective tax rate
       // function: printStringJustified, printString, printCharacter,
       //    printEndline
    printString( PIPE_SPACE );
    printStringJustified( "AZ Tax Rate ", DATA_NAME_WIDTH - 1, "LEFT" );
    printCharacter( PIPE );
    printStringJustified( "%", UNIT_WIDTH, "CENTER" );
    printCharacter( PIPE );
    printDoubleJustified( taxBracketRateAZ * PERCENTAGE_CONVERSION,
                                PRECISION, VALUE_WIDTH -1, "RIGHT" );
    printString( SPACE_PIPE );
    printEndline();

    // print thin divider line
       // function: printString, printEndline
    printString( THIN_LINE_DIVIDER );
    printEndline();


        // print Effective tax rate
       // function: printStringJustified, printString, printCharacter,
       //    printEndline
    printString( PIPE_SPACE );
    printStringJustified( "Fed Tax Rate", DATA_NAME_WIDTH - 1, "LEFT" );
    printCharacter( PIPE );
    printStringJustified( "%", UNIT_WIDTH, "CENTER" );
    printCharacter( PIPE );
    printDoubleJustified( taxBracketRateFed * PERCENTAGE_CONVERSION,
                                PRECISION, VALUE_WIDTH -1, "RIGHT" );
    printString( SPACE_PIPE );
    printEndline();

    // print thin divider line
       // function: printString, printEndline
    printString( THIN_LINE_DIVIDER );
    printEndline();


    // print Effective tax rate
       // function: printStringJustified, printString, printCharacter,
       //    printEndline
    printString( PIPE_SPACE );
    printStringJustified( "Effective Tax Rate ", DATA_NAME_WIDTH - 1, "LEFT" );
    printCharacter( PIPE );
    printStringJustified( "%", UNIT_WIDTH, "CENTER" );
    printCharacter( PIPE );
    printDoubleJustified( effectiveTax * PERCENTAGE_CONVERSION,
                                PRECISION, VALUE_WIDTH -1, "RIGHT" );
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
    printStringJustified( "Tax To Be Payed ", DATA_NAME_WIDTH - 1, "LEFT" );
    printCharacter( PIPE );
    printStringJustified( "$", UNIT_WIDTH, "CENTER" );
    printCharacter( PIPE );
    printDoubleJustified( taxTotal, PRECISION, VALUE_WIDTH -1, "RIGHT" );
    printString( SPACE_PIPE );
    printEndline();

    // print thin divider line
       // function: printString, printEndline
    printString( THIN_LINE_DIVIDER );
    printEndline();

    printString( PIPE_SPACE );
    printStringJustified( "Income After Tax ", DATA_NAME_WIDTH - 1, "LEFT" );
    printCharacter( PIPE );
    printStringJustified( "$", UNIT_WIDTH, "CENTER" );
    printCharacter( PIPE );
    printDoubleJustified( incomeAfterTaxes,
                                PRECISION, VALUE_WIDTH -1, "RIGHT" );
    printString( SPACE_PIPE );
    printEndline();

    // print thin divider line
       // function: printString, printEndline
    printString( THIN_LINE_DIVIDER );
    printEndline();

    printString( PIPE_SPACE );
    printStringJustified( "Locked in IRA ", DATA_NAME_WIDTH - 1, "LEFT" );
    printCharacter( PIPE );
    printStringJustified( "%", UNIT_WIDTH, "CENTER" );
    printCharacter( PIPE );
    printDoubleJustified( incomeLocked,
                                PRECISION, VALUE_WIDTH -1, "RIGHT" );
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
