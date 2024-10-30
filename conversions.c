
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

/*
This program converts an original input of either temperature or distance in a certain unit type to the desired temperature or distance in a different unit type

We first ask the user for their first input (to convert temperature or distance)
We then ask the user for their second input (the temperature or distance with the original unit that will later be converted)
We then ask the user for their third and final input (the temperature or distance into the unit they want it to be converted in)

if the user does not ever provide a right input, we check why that input is wrong and display an error message
*/

void checkInputError(char input) {
    /*
    Checks what the input error is
    @param input is the input given by the user
    Does not @return anything
    */
    if (!isascii(input)) {
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }
    else if ((input != 'T') && (input != 't') && (input != 'D') && (input != 'd')) {
        input = toupper(input);
        printf("Unknown conversion type %c chosen. Ending program.\n", input);
        exit(0);
    }
}
void checkUnitType(char tempOrDist, char input) {
    /*
    Checks what is wrong with the unit type
    @param tempOrDist tells the program whether the user was trying to convert a distance or temperature type
    @param input is the user's input
    Does not @return anything
    */
    char unit[20];
    input = toupper(input);
    if (tempOrDist == 'T') {
        strcpy(unit, "temperature");
    } else {
        strcpy(unit, "distance");
    }
    printf("%c is not a valid %s type. Ending program.\n", input, unit);
    exit(0);
}

int fahrenheitConversion(double tempVal, char tempUnit, char newTempUnit) {
    /*
    Converts from FAHRENHEIT to other unit types
    @param tempVal is the original temperature value
    @param tempUnit is the unit of the original temperature value
    @param newTempUnit is the new temperature unit to be converted to
    @return is 0 for successful completion
    */

    double conversionVal;

    if ((newTempUnit == 'F') || (newTempUnit == 'f')) {
        conversionVal = tempVal;
        printf("%.2lfF is %.2lfF\n", tempVal, conversionVal);
    } else if ((newTempUnit == 'C') || (newTempUnit == 'c')) {
        conversionVal = ((tempVal - 32.0) * (5.0/9.0));
        printf("%.2lfF is %.2lfC\n", tempVal, conversionVal);
    } else if ((newTempUnit == 'K') || (newTempUnit == 'k')) {
        conversionVal = ((tempVal - 32.0) * (5.0/9.0) + 273.15);
        printf("%.2lfF is %.2lfK\n", tempVal, conversionVal);
    } else {
        checkUnitType('T', tempUnit);
    }
    return 0;
}
int celsiusConversion(double tempVal, char tempUnit, char newTempUnit) {
    double conversionVal;
    /*
    Converts from CELSIUS to other unit types
    @param tempVal is the original temperature value
    @param tempUnit is the unit of the original temperature value
    @param newTempUnit is the new temperature unit to be converted to
    @return is 0 for successful completion
    */

    if ((newTempUnit == 'F') || (newTempUnit == 'f')) {
        conversionVal = (tempVal * (9.0/5.0)) + 32;
        printf("%.2lfC is %.2lfF\n", tempVal, conversionVal);
    } else if ((newTempUnit == 'C') || (newTempUnit == 'c')) {
        conversionVal = tempVal;
        printf("%.2lfC is %.2lfC\n", tempVal, conversionVal);
    } else if ((newTempUnit == 'K') || (newTempUnit == 'k')) {
        conversionVal = tempVal + 273.15;
        printf("%.2lfC is %.2lfK\n", tempVal, conversionVal);
    } else {
        checkUnitType('T', tempUnit);
    }
    return 0;
}
int kelvinConversion(double tempVal, char tempUnit, char newTempUnit) {
    double conversionVal;
    /*
    Converts from KELVINS to other unit types
    @param tempVal is the original temperature value
    @param tempUnit is the unit of the original temperature value
    @param newTempUnit is the new temperature unit to be converted to
    @return is 0 for successful completion
    */

    if ((newTempUnit == 'F') || (newTempUnit == 'f')) {
        conversionVal = (tempVal - 273.15) * (9.0/5.0) + 32;
        printf("%.2lfK is %.2lfF\n", tempVal, conversionVal);
    } else if ((newTempUnit == 'C') || (newTempUnit == 'c')) {
        conversionVal = tempVal - 273.15;
        printf("%.2lfK is %.2lfC\n", tempVal, conversionVal);
    } else if ((newTempUnit == 'K') || (newTempUnit == 'k')){
        conversionVal = tempVal;
        printf("%.2lfK is %.2lfK\n", tempVal, conversionVal);
    } else {
        checkUnitType('T', tempUnit);
    }
    return 0;
}

int inchesConversion(double distVal, char distUnit, char newDistUnit) {
    double conversionVal;
    /*
    Converts from INCHES to other unit types
    @param distVal is the original distance value
    @param distUnit is the unit of the original distance value
    @param newDistUnit is the new distance unit to be converted to
    @return is 0 for successful completion
    */

    if ((newDistUnit == 'I') || (newDistUnit == 'i')) {
        conversionVal = distVal;
        printf("%.2lfI is %.2lfI\n", distVal, conversionVal);
    } else if ((newDistUnit == 'F') || (newDistUnit == 'f')) {
        conversionVal = distVal / 12.0;
        printf("%.2lfI is %.2lfF\n", distVal, conversionVal);
    } else if ((newDistUnit == 'Y') || (newDistUnit == 'y')) {
        conversionVal = distVal / 36.0;
        printf("%.2lfI is %.2lfY\n", distVal, conversionVal);
    } else if ((newDistUnit == 'M') || (newDistUnit == 'm')) {
        conversionVal = distVal / 63360.0;
        printf("%.2lfI is %.2lfM\n", distVal, conversionVal);
    } else {
        checkUnitType('D', distUnit);
    }
    return 0;
}
int feetConversion(double distVal, char distUnit, char newDistUnit) {
    double conversionVal;
    /*
    Converts from FEET to other unit types
    @param distVal is the original distance value
    @param distUnit is the unit of the original distance value
    @param newDistUnit is the new distance unit to be converted to
    @return is 0 for successful completion
    */

    if ((newDistUnit == 'I') || (newDistUnit =='i')) {
        conversionVal = distVal * 12;
        printf("%.2lfF is %.2lfI\n", distVal, conversionVal);
    } else if ((newDistUnit == 'F') || (newDistUnit == 'f')) {
        conversionVal = distVal;
        printf("%.2lfF is %.2lfF\n", distVal, conversionVal);
    } else if ((newDistUnit == 'Y') || (newDistUnit == 'y')) {
        conversionVal = distVal / 3.0;
        printf("%.2lfF is %.2lfY\n", distVal, conversionVal);
    } else if ((newDistUnit == 'M') || (newDistUnit == 'm')) {
        conversionVal = distVal / 5280.0;
        printf("%.2lfF is %.2lfM\n", distVal, conversionVal);
    } else {
        checkUnitType('D', distUnit);
    }
    return 0;
}
int yardConversion(double distVal, char distUnit, char newDistUnit) {
    double conversionVal;
    /*
    Converts from YARDS to other unit types
    @param distVal is the original distance value
    @param distUnit is the unit of the original distance value
    @param newDistUnit is the new distance unit to be converted to
    @return is 0 for successful completion
    */

    if ((newDistUnit == 'I') || (newDistUnit == 'i')) {
        conversionVal = distVal * 36.0;
        printf("%.2lfY is %.2lfI\n", distVal, conversionVal);
    } else if ((newDistUnit == 'F') || (newDistUnit == 'f')) {
        conversionVal = distVal * 3.0;
        printf("%.2lfY is %.2lfF\n", distVal, conversionVal);
    } else if ((newDistUnit == 'Y') || (newDistUnit == 'y')) {
        conversionVal = distVal;
        printf("%.2lfY is %.2lfY\n", distVal, conversionVal);
    } else if ((newDistUnit == 'M') || (newDistUnit == 'm')) {
        conversionVal = distVal / 1760.0;
        printf("%.2lfY is %.2lfM\n", distVal, conversionVal);
    } else {
        checkUnitType('D', distUnit);
    }
    return 0;
}
int mileConversion(double distVal, char distUnit, char newDistUnit) {
    double conversionVal;
    /*
    Converts from MILES to other unit types
    @param distVal is the original distance value
    @param distUnit is the unit of the original distance value
    @param newDistUnit is the new distance unit to be converted to
    @return is 0 for successful completion
    */

    if ((newDistUnit == 'I') || (newDistUnit == 'i')) {
        conversionVal = distVal * 63360.0;
        printf("%.2lfM is %.2lfI\n", distVal, conversionVal);
    } else if ((newDistUnit == 'F') || (newDistUnit == 'f')) {
        conversionVal = distVal * 5280.0;
        printf("%.2lfM is %.2lfF\n", distVal, conversionVal);
    } else if ((newDistUnit == 'Y') || (newDistUnit == 'y')) {
        conversionVal = distVal * 1760.0;
        printf("%.2lfM is %.2lfY\n", distVal, conversionVal);
    } else if ((newDistUnit == 'M') || (newDistUnit == 'm')) {
        conversionVal = distVal;
        printf("%.2lfM is %.2lfM\n", distVal, conversionVal);
    } else {
        checkUnitType('D', distUnit);
    }
    return 0;
}

int askTempInput() {
    /*
    Asks the user for their temperature inputs
    1. The original temperature and its unit type
    2. The temperature unit type that it will be converted to
    Also checks if there seems to be something wrong with the input
    @return 0 for successful completion
    */
    double tempVal;
    char tempUnit;
    char newTempUnit;
    char isLastVal;

    printf("Enter the temperature followed by its suffix (F, C, or K): ");
    scanf(" %lf %c", &tempVal, &tempUnit);
    scanf("%c", &isLastVal);

    if (isLastVal != '\n') {
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }

    switch (tempUnit) {
        case 'F':
        case 'f':
        case 'C':
        case 'c':
        case 'K':
        case 'k':
            break;
        default:
            checkUnitType('T', tempUnit);
            break;
    }

    printf("Enter the new unit type (F, C, or K): ");
    scanf(" %c", &newTempUnit);
    scanf("%c", &isLastVal);

    if (isLastVal != '\n') {
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }

    switch (newTempUnit) {
        case 'F':
        case 'f':
        case 'C':
        case 'c':
        case 'K':
        case 'k':
            break;
        default:
            checkUnitType('T', newTempUnit);
            break;
    }

    if ((tempUnit == 'F') || (tempUnit == 'f')) {
        fahrenheitConversion(tempVal, tempUnit, newTempUnit);
    } else if ((tempUnit == 'C') || (tempUnit == 'c')) {
        celsiusConversion(tempVal, tempUnit, newTempUnit);
    } else if ((tempUnit == 'K') || (tempUnit == 'k')) {
        kelvinConversion(tempVal, tempUnit, newTempUnit);
    } else {
        checkUnitType('T', newTempUnit);
    }
    return 0;
}
int askDistInput() {
    /*
    Asks the user for their distance inputs
    1. The original distance and its unit type
    2. The distance unit type that it will be converted to
    Also checks if there seems to be something wrong with the input
    @return 0 for successful completion
    */
    double distVal;
    char distUnit;
    char newDistUnit;
    char isLastVal;

    printf("Enter the distance followed by its suffix (I,F,Y,M): ");
    scanf(" %lf %c", &distVal, &distUnit);
    scanf("%c", &isLastVal);

    if (isLastVal != '\n') {
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }

    switch (distUnit) {
        case 'I':
        case 'i':
        case 'F':
        case 'f':
        case 'Y':
        case 'y':
        case 'M':
        case 'm':
            break;
        default:
            checkUnitType('D', distUnit);
            break;
    }

    printf("Enter the new unit type (I,F,Y,M): ");
    scanf(" %c", &newDistUnit);
    scanf("%c", &isLastVal);

    if (isLastVal != '\n') {
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }

    switch (newDistUnit) {
        case 'I':
        case 'i':
        case 'F':
        case 'f':
        case 'Y':
        case 'y':
        case 'M':
        case 'm':
            break;
        default:
            checkUnitType('D', newDistUnit);
            break;
    }

    if ((distUnit == 'I') || (distUnit == 'i')) {
        inchesConversion(distVal, distUnit, newDistUnit);
    } else if ((distUnit == 'F') || (distUnit == 'f')) {
        feetConversion(distVal, distUnit, newDistUnit);
    } else if ((distUnit == 'Y') || (distUnit == 'y')) {
        yardConversion(distVal, distUnit, newDistUnit);
    } else if ((distUnit == 'M') || (distUnit == 'm')) {
        mileConversion(distVal, distUnit, newDistUnit);
    } else {
        checkUnitType('D', distUnit);
    }

    return 0;
}

int askFirstInput() {
    /*
    Asks the user whether we will be converting distance or temperature
    Also checks if something may be wrong with the input
    @return 0 for successful completion
    */
    char conversionType;
    char isLastVal;

    printf("Pick the type of conversion that you would like to do.\n");
    printf("T or t for temperature\n");
    printf("D or d for distance\n");
    printf("Enter your choice: ");

    scanf(" %c", &conversionType);
    scanf("%c", &isLastVal);

    if (isLastVal != '\n') {
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }

    if ((conversionType == 't') || (conversionType == 'T')) {
        askTempInput();
    } else if ((conversionType == 'd') || (conversionType == 'D')) {
        askDistInput();
    } else {
        checkInputError(conversionType);
    }
    return 0;
}

int main(void) {
    /*
    Starts the program by asking the first input
    @return 0 for successful completion
    */
    askFirstInput();

    return 0;
}