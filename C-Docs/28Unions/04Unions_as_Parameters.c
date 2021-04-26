#include <stdio.h>
#include <stdlib.h>

typedef union {
    int id_num;
    char name[20]; 
} id;

void set_id(id *item) {
    item->id_num = 42;
}

void show_id(id item) {
    printf("ID is %d \n", item.id_num);
}

int main() {
    /*
        A function can have union parameters that accept arguments by value when a copy of the union
        variable is all that is needed.
        For a function to change the actual value in a union memory location, pointer parameters are
        required. 
    */

    id item;
    
    set_id(&item); //This one goes by reference
    show_id(item); //This one goes by value
    return 0;
}
