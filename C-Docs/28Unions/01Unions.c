#include <stdio.h>
#include <stdlib.h>

int main() {
    /* 
        A union allows to store different data types in the same memory location.
        It is like a structure because it has members. However, a union variable uses the same memory location for
        all its member's and only one member at a time can occupy the memory location. Trying to access a member
        that isn't occupying the memory location gives unexpected results

        A union declaration uses the keyword union, a union tag, and curly braces { } with a list of members.

        Union members can be of any data type, including basic types, strings, arrays, pointers, and structures. 
    */

    union val { //This guy is an Union
        int int_num;
        float float_num;
        char str[20];
    }; //Don't forget to place this guy here

    /*
        After declaring a union, you can declare union variables. You can even assign
        one union to another of the same type: 
    */
    union val u1;
    union val u2;
    u2 = u1;
    /*
        Unions are used for memory management. The largest member data type is used to
        determine the size of the memory to share and then all members use this one
        location. This process also helps limit memory fragmentation
    */
    return 0;
}
