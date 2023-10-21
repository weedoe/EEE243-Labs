// Written by OCdt Patterson and Paterson. Program to write hello world on the 3pi.
// Date: Sept 6, 2023

#include <pololu/3pi.h>
int main() {
    while (1) {
        print("Hello"); // print hello on top line of lcd
        delay(1000); //delays for 1 second
        lcd_goto_xy(0, 1); //moves cursor to bottom line of lcd
        print("World");
        delay(1000);
        clear(); //clears lcd
        delay(1000);
    }
    return 0;
} // end main