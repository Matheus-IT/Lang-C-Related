#include <stdio.h>
#include <stdlib.h>

int main() {
    /*
            *** Conditional Compilation Directives ***
        Conditional compilation of segments of code is controlled by a set of directives:
        #if, #else, #elif, and #endif.
    */
    #define LEVEL 4 

    #if LEVEL > 6
        /* do something */
    #elif LEVEL > 5
        /* else if branch */
    #elif LEVEL > 4
        /* another else if */
    #else
        /* last option here */
    #endif
    /*
        - There are instances where such conditional compilation can be useful, but this type of
        code should be used sparingly.
        - The defined() preprocessor operator can be used with #if, as in:
    */
    #if !defined(LEVEL)
        /* statements */
    #endif
    /*
        - The #if and if statement are not interchangeable. The #if is evaluated using data
        available to the preprocessor, which then sends only the true branch for compilation.
        - An if statement uses data provided at runtime with the possibility of branching to any
        else clause.
    */
    return 0;
}
