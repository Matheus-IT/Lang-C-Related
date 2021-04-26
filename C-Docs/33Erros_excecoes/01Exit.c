#include <stdio.h>
#include <stdlib.h>


int main() {
    /*
        C does not explicitly support exception handling, but there are ways to manage errors:
        - Write code to prevent the errors in the first place. You can't control user input, but
        you can check to be sure that the user entered valid input. When performing division, take
        the extra step to ensure that division by 0 won't occur.
        - Use the exit statement to gracefully end program execution. You may not be able to
        control if a file is available for reading, but you don't need to allow the problem to
        crash your program.
    */
    /*
        The exit command immediately stops the execution of a program and sends an exit code back
        to the calling process. For example, if a program is called by another program, then the
        calling program may need to know the exit status. 
        Using exit to avoid a program crash is a good practice because it closes any open file    <- Pay attention
        connections and processes.
        You can return any value through an exit statement, but 0 for success and -1 for failure
        are typical. The predefined stdlib.h macros EXIT_SUCCESS and EXIT_FAILURE are also commonly used:
        0 for success //EXIT_SUCCESS
        -1 for failure //EXIT_FAILURE
    */
    int n1 = 10;
    int n2 = 0;

    if (n2 != 0) {
        printf(" n1/n2 = %d \n", n1/n2);
    } else {
        printf("Divisor igual a 0, programa saindo...");
        //exit(-1);
        exit(EXIT_FAILURE);
    }
    return 0;
}
