#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char title[40];
    float hours; 
} course;

void update_course(course *class) { //This one takes the pointer as parameter
    strcpy(class->title, "C++ Fundamentals");
    class->id = 111;
    class->hours = 12.30;
}

void display_course(course class) { //This one takes the value
    printf("%d\t%s\t%3.2f\n", class.id, class.title, class.hours);
}

int main() {
    /*  A function can have structure parameters that accept arguments by value when a copy
        of the structure variable is all that is needed.
        For a function to change the actual values in a struct variable, pointer parameters
        are required */

    course cs2;
    update_course(&cs2);
    display_course(cs2);
    return 0;
}
