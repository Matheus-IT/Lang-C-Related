#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /*
        Unions are often used within structures because a structure can have a member to keep track of which
        union member stores a value.
        For example, in the following program, a vehicle struct uses either a vehicle identification number (VIN)
        or an assigned id, but not both:
    */
    typedef struct { //Structure
    char make[20];
    int model_year;
    int id_type; /* 0 for id_num, 1 for VIN */
    union { //Union
        int id_num;
        char VIN[20]; 
    } id; //This time the name comes here
    } vehicle;
    /*
        Note that the union was declared inside the structure. When doing this,                 <<- Pay attention!
        a union name was required at the end of the declaration.
    */

    vehicle car1;
    strcpy(car1.make, "Ford");
    car1.model_year = 2017;
    car1.id_type = 0;
    car1.id.id_num = 123098;

    /* display vehicle data */
    printf("Make: %s\n", car1.make);
    printf("Model Year: %d\n", car1.model_year);
    if (car1.id_type == 0)
        printf("ID: %d\n", car1.id.id_num);
    else
        printf("ID: %s\n", car1.id.VIN);
    //A union can also contain a structure!                                                     <<- Pay attention!
    return 0;
}
