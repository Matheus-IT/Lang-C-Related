#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main() {
    /*  A structure is a user-defined data type that groups related variables of different
    data types. A structure declaration includes the keyword struct, a structure tag for 
    referencing the structure, and curly braces { } with a list of variable declarations
    called members.

    Example:
    struct course {
        int id;
        char title[40];
        float hours; 
    }; 

    This struct statement defines a new data type named course that has three members.
    Structure members can be of any data type, including basic types, strings, arrays,
    pointers, and even other structures. */

    struct horario {
        int hour, minutes, seconds;
    }; // <- I need to put this guy here!

    // struct horario now = {15, 17, 30}; // Can set the values this way...
    struct horario now = {.hour = 15, .minutes = 17, .seconds = 30}; // Also can be this way!
    
    // To initialize a structure using curly braces after declaration, you will also need 
    // to type cast:
    now = (struct horario){17, 14, 36};

    // To show you don't need to specify the element, just maintain the order:
    printf("%d:%d:%d\n", now);
    
    // A struct variable is stored in a contiguous block of memory. The sizeof operator must be
    // used to get the number of bytes needed for a struct, just as with the basic data types.
    return 0;
}
