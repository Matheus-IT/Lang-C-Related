#include <stdio.h>
#include <stdlib.h>

int main() {
    /*
        A pointer to a union points to the memory location allocated to the union.
        A union pointer is declared by using the keyword union and the union tag along with * and the pointer name.
        For example, consider the following statements:
    */
    union val {
        int int_num;
        float fl_num;
        char str[20]; 
    };

    union val info; //This is an union variable
    union val *ptr = NULL; //And this is an union pointer
    ptr = &info;
    //(*ptr).int_num is the same as ptr->int_num:
    ptr->int_num = 10;
    (*ptr).int_num = 10;
    printf("(*ptr).int_num is %d \n", ptr->int_num);
    return 0;
}
