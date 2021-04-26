#include <stdio.h>
#include <stdlib.h>
//#include <errno.h> This way
extern int errno; //Or this way

int main() {
    /*
        Some library functions, such as fopen(), set an error code when they do not execute as
        expected. The error code is set in a global variable named errno, which is defined in the
        errno.h header file. When using errno you should set it to 0 before calling a library function.

        To output the error code stored in errno, you use fprintf to print to the stderr file stream,
        the standard error output to the screen. Using stderr is a matter of convention and a good
        programming practice.

        You can output the errno through other means, but it will be easier to keep track of your
        exception handling if you only use stderr for error messages.

        To use errno, you need to declare it with the statement extern int errno; at the top of your
        program (or you can include the errno.h header file). 
    */
    FILE *p;

    errno = 0;
    p = fopen("nonexistantfile.txt", "r");
    if (p == NULL) {
        fprintf(stderr, "Error opening file. Error code: %d\n", errno);
        exit(EXIT_FAILURE);
    }
    fclose(p);

    /*
        Error codes:
        0: No error
        1: Operation not permitted
        2: No such file or directory
        3: No such process
        4: Interrupted function call
        5: Input/output error
        6: No such device or address
        7: Arg list too long
        8: Exec format error
        9: Bad file descriptor
        10: No child processes
        11: Resource temporarily unavailable
        12: Not enough space
        13: Permission denied
        14: Bad address
        15: Unknown error
        16: Resource device
        17: File exists
        18: Improper link
        19: No such device
        20: Not a directory
        21: Is a directory
        22: Invalid argument
        23: Too many open files in system
        24: Too many open files
        25: Inappropriate I/O control operation
        26: Unknown error
        27: File too large
        28: No space left on device
        29: Invalid seek
        30: Read-only file system
        31: Too many links
        32: Broken pipe
        33: Domain error
        34: Result too large
        35: Unknown error
        36: Resource deadlock avoided
        37: Unknown error
        38: Filename too long
        39: No locks available
        40: Function not implemented
        41: Directory not empty
        42: Illegal byte sequence
    */
    return 0;
}
