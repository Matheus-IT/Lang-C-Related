#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int number;
    int age;
} student;

void set_std(student *std) { // Sending a struct "student" to a function
    *std = (student){"Krishna", 5, 21};
}

int main() {
    /*  Just like pointers to variables, pointers to structures can also be defined:
            struct myStruct *struct_ptr; // defines a pointer to the myStruct structure.
            struct_ptr = &struct_var; // stores the address of the structure variable struct_var
            struct_ptr -> struct_mem; // accesses the value of the structure member struct_mem
            (*struct_ptr).struct_mem; // Also can be this way
    */

    student st1;
    set_std(&st1);
    student *ptr = NULL; // Struct pointer
    ptr = &st1;
    // (*ptr).name is the same as ptr->name:
    printf("Name: %s Number: %d Age: %d \n", ptr->name, ptr->number, ptr->age);
    return 0;
}
