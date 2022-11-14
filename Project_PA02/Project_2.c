// header files
#include "Console_IO_Utility.h"

// global constants
const double ABSOLUTE_BASE = 0.0000001;
const double BOOSTING_VALUE = 5.55;
const double DRYWALL_PRICE = 3.00;
const double PLYWOOD_PRICE = 3.125;    // per square foot
const double ROOFING_PRICE = 3.535525;  // per square foot
const double SIDE_WALL_RATIO = 0.67;
const double SQUARE_ROOT_PRECISION = 0.000001;
const double TWO_BY_FOUR_PRICE = 7.50;  // per board

const int HOUSE_HEIGHT = 10;
const int NUM_2x4_PER_FOOT = 6;
const int TRIMMING_VALUE = 10;
const int TWO_ENDLINES = 2;

// constants for table
const int DESCRIPTION_WIDTH = 16;
const int TABLE_WIDTH = 39;
const int UNIT_WIDTH = 9;
const int VALUE_WIDTH = 10;

const char THICK_LINE = '=';
const char THIN_LINE = '-';

// prototypes
double findAbsolute( int value );
double findSquareRoot( double value );
void printDividedLine( char thickness );
void printHeavyDividedLine();
void printLightDividedLine();
void printTopLine();

// main program
int main()
   {
    // TODO: Write program as specified

      //Initialize function/variables
      double houseWidth, houseDepth, roofingCost, plywoodCost, twoByFourCost;
      double drywallCost, totalEstimate;
      int desiredArea, actualArea, frontBackArea, sideAreas, numOfTwoByFours;

        //Print title
          //functions: printString, printEndline(s)
        printString("House Cost Estimator\n");
        printString("====================");
        printEndlines(TWO_ENDLINES);

      //Get input
        //Ask for input
          //functions: promptForInteger, printEndlines
        desiredArea =
          promptForInteger("Enter the desired floor square footage: ");
        printEndline();

      //Calculate values
        //Calculate houseWidth
        houseWidth = findSquareRoot(desiredArea / SIDE_WALL_RATIO);

        //Calculate houseDepth
        houseDepth = SIDE_WALL_RATIO * houseWidth;

        //Round front and side lenth
          //Round houseWidth
        houseWidth = (int) (houseWidth + BOOSTING_VALUE);
        houseWidth = houseWidth / TRIMMING_VALUE;
        houseWidth = (int) houseWidth * TRIMMING_VALUE;

          //Round houseDepth
        houseDepth = (int) (houseDepth + BOOSTING_VALUE);
        houseDepth = houseDepth / TRIMMING_VALUE;
        houseDepth = (int) houseDepth * TRIMMING_VALUE;

        //Calculate actualArea
        actualArea = houseDepth * houseWidth;

        //Calculate roofingCost
        roofingCost = actualArea * ROOFING_PRICE;

        //Calculate plywoodCost
          //Get area of front/back
        frontBackArea = houseWidth * HOUSE_HEIGHT * 2;

          //Get area of sides
        sideAreas = houseDepth * HOUSE_HEIGHT * 2;

          //Calculate plywoodCost with side areas
        plywoodCost = frontBackArea + sideAreas;
        plywoodCost += actualArea;
        plywoodCost *= PLYWOOD_PRICE;

          //Calculate twoByFourCost
        numOfTwoByFours = houseWidth + houseDepth;
        numOfTwoByFours *= NUM_2x4_PER_FOOT;
        twoByFourCost = numOfTwoByFours * TWO_BY_FOUR_PRICE;

          //Calculate drywallCost
        drywallCost = (frontBackArea + sideAreas) * DRYWALL_PRICE;

          //Calculate totalEstimate
        totalEstimate = roofingCost + plywoodCost +
          twoByFourCost + drywallCost;

      //Print values
        //Print top line
          //functions: printTopLine, printEndline
      printTopLine();
      printEndline();

        //Print title line
          //functions; printCharacter, printStringJustified, printEndline
      printCharacter(PIPE);
      printStringJustified("Description", DESCRIPTION_WIDTH, "CENTER");
      printCharacter(PIPE);
      printStringJustified("Value", VALUE_WIDTH, "CENTER");
      printCharacter(PIPE);
      printStringJustified("Unit", UNIT_WIDTH, "CENTER");
      printCharacter(PIPE);
      printEndline();

        //Print heavy divided line
          //functions: printHeavyDividedLine, printEndline
      printHeavyDividedLine();
      printEndline();

      //Print desired area line
        //functions: printCharacter, printStringJustified,
        //  printEndline, printString
      printString("| ");
      printStringJustified("Desired Area", DESCRIPTION_WIDTH-1, "LEFT");
      printCharacter(PIPE);
      printIntegerJustified(desiredArea, VALUE_WIDTH-1, "RIGHT");
      printString(" | ");
      printStringJustified("sq ft", UNIT_WIDTH-1, "LEFT");
      printCharacter(PIPE);
      printEndline();

      //Print divider line
        //functions: printDividedLine, printEndline
      printDividedLine(THIN_LINE);
      printEndline();

      //Print actual area line
        //functions: printCharacter, printStringJustified,
        //  printEndline, printString
      printString("| ");
      printStringJustified("Actual Area", DESCRIPTION_WIDTH-1, "LEFT");
      printCharacter(PIPE);
      printIntegerJustified(actualArea, VALUE_WIDTH-1, "RIGHT");
      printString(" | ");
      printStringJustified("sq ft", UNIT_WIDTH-1, "LEFT");
      printCharacter(PIPE);
      printEndline();

      //Print divider line
        //functions: printDividedLine, printEndline
      printDividedLine(THIN_LINE);
      printEndline();

      //Print house width line
        //functions: printCharacter, printStringJustified,
        //  printEndline, printString
      printString("| ");
      printStringJustified("House Width", DESCRIPTION_WIDTH-1, "LEFT");
      printCharacter(PIPE);
      printIntegerJustified(houseWidth, VALUE_WIDTH-1, "RIGHT");
      printString(" | ");
      printStringJustified("feet", UNIT_WIDTH-1, "LEFT");
      printCharacter(PIPE);
      printEndline();

      //Print divider line
        //functions: printDividedLine, printEndline
      printDividedLine(THIN_LINE);
      printEndline();

      //Print house depth line
        //functions: printCharacter, printStringJustified,
        //  printEndline, printString
      printString("| ");
      printStringJustified("House Depth", DESCRIPTION_WIDTH-1, "LEFT");
      printCharacter(PIPE);
      printIntegerJustified(houseDepth, VALUE_WIDTH-1, "RIGHT");
      printString(" | ");
      printStringJustified("feet", UNIT_WIDTH-1, "LEFT");
      printCharacter(PIPE);
      printEndline();

      //Print divider line
        //functions: printDividedLine, printEndline
      printDividedLine(THIN_LINE);
      printEndline();

      //Print roofing cost line
        //functions: printCharacter, printDoubleJustified,
        //  printEndline, printString
      printString("| ");
      printStringJustified("Roofing Cost", DESCRIPTION_WIDTH-1, "LEFT");
      printCharacter(PIPE);
      printDoubleJustified(roofingCost, 2, VALUE_WIDTH-1, "RIGHT");
      printString(" | ");
      printStringJustified("dollars", UNIT_WIDTH-1, "LEFT");
      printCharacter(PIPE);
      printEndline();

      //Print divider line
        //functions: printDividedLine, printEndline
      printDividedLine(THIN_LINE);
      printEndline();

      //Print plywood cost line
        //functions: printCharacter, printDoubleJustified,
        //  printEndline, printString
      printString("| ");
      printStringJustified("Plywood Cost", DESCRIPTION_WIDTH-1, "LEFT");
      printCharacter(PIPE);
      printDoubleJustified(plywoodCost, 2, VALUE_WIDTH-1, "RIGHT");
      printString(" | ");
      printStringJustified("dollars", UNIT_WIDTH-1, "LEFT");
      printCharacter(PIPE);
      printEndline();

      //Print divider line
        //functions: printDividedLine, printEndline
      printDividedLine(THIN_LINE);
      printEndline();

      //Print 2x4 cost line
        //functions: printCharacter, printDoubleJustified,
        //  printEndline, printString
      printString("| ");
      printStringJustified("2 x 4 Cost", DESCRIPTION_WIDTH-1, "LEFT");
      printCharacter(PIPE);
      printDoubleJustified(twoByFourCost, 2, VALUE_WIDTH-1, "RIGHT");
      printString(" | ");
      printStringJustified("dollars", UNIT_WIDTH-1, "LEFT");
      printCharacter(PIPE);
      printEndline();

      //Print divider line
        //functions: printDividedLine, printEndline
      printDividedLine(THIN_LINE);
      printEndline();

      //Print drywall cost line
        //functions: printCharacter, printDoubleJustified,
        //  printEndline, printString
      printString("| ");
      printStringJustified("Drywall Cost", DESCRIPTION_WIDTH-1, "LEFT");
      printCharacter(PIPE);
      printDoubleJustified(drywallCost, 2, VALUE_WIDTH-1, "RIGHT");
      printString(" | ");
      printStringJustified("dollars", UNIT_WIDTH-1, "LEFT");
      printCharacter(PIPE);
      printEndline();

      //Print divider line
        //functions: printDividedLine, printEndline
      printDividedLine(THIN_LINE);
      printEndline();

      //Print total estimate line
        //functions: printCharacter, printDoubleJustified,
        //  printEndline, printString
      printString("| ");
      printStringJustified("Total Estimate", DESCRIPTION_WIDTH-1, "LEFT");
      printCharacter(PIPE);
      printDoubleJustified(totalEstimate, 2, VALUE_WIDTH-1, "RIGHT");
      printString(" | ");
      printStringJustified("dollars", UNIT_WIDTH-1, "LEFT");
      printCharacter(PIPE);
      printEndline();

      //Print divider line
        //functions: printDividedLine, printEndlines
      printDividedLine(THIN_LINE);
      printEndlines(TWO_ENDLINES);

      //End program
        //functions: printSting
      printString("End Program");

      // return program success
      return 0;
   }


// supporting functions

double findAbsolute( int value )
   {
    // test for value less than negative precision
    if( value < -ABSOLUTE_BASE )
       {
        // return negated value
        return -value;
       }

    // otherwise, assume positive value, return unchanged
    return value;
   }

double findSquareRoot( double value )
   {
    // initialize function/variables
    double testSquare, mid, high = value, low = 0;

    // set initial mid value
    mid = ( high + low ) / 2.0;

    // set initial test square value
    testSquare = mid * mid;

    // loop while difference between test square and value
    //   is greater than desired precision
       // function: findAbsolute
    while( findAbsolute( testSquare - value ) > SQUARE_ROOT_PRECISION )
       {
        // test for calculated value too high
        if( testSquare > value )
           {
            // change low to the mid value
            high = mid;
           }

        // otherwise, assume value was too low
        else
           {
            low = mid;
           }

        // calculate new mid
        mid = ( high + low ) / 2.0;

        // calculate new test square
        testSquare = mid * mid;
       }

    // return estimated square root
    return mid;
   }

void printDividedLine( char thickness )
   {
    // print first pipe
       // function: printCharacter
    printCharacter( PIPE );

    // print description line
       // function: printCharacters
    printCharacters( DESCRIPTION_WIDTH, thickness );

    // print divider pipe
       // function: printCharacter
    printCharacter( PIPE );

    // print description line
       // function: printCharacters
    printCharacters( VALUE_WIDTH, thickness );

    // print divider pipe
       // function: printCharacter
    printCharacter( PIPE );

    // print description line
       // function: printCharacters
    printCharacters( UNIT_WIDTH, thickness );

    // print last pipe
       // function: printCharacter
    printCharacter( PIPE );
   }

void printHeavyDividedLine()
   {
    // call print divided line with heavy character
       // function: printDividedLine
    printDividedLine( THICK_LINE );
   }

void printLightDividedLine()
   {
    // call print divided line with heavy character
       // function: printDividedLine
    printDividedLine( THIN_LINE );
   }

void printTopLine()
   {
    // print top line
       // function: printCharacters
    printCharacters( TABLE_WIDTH, THIN_LINE );
   }
