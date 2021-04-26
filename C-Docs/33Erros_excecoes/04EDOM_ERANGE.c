#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <math.h>

int main() {
    /*
            *** EDOM and ERANGE Error Codes ***
        - Some of the mathematical functions in the math.h library set errno to the defined
        macro value EDOM when a domain is out of range.
        - Similarly, the ERANGE macro value is used when there is a range error.
    */
    float k = -5;
    float num = 1000;
    float result;

    errno = 0;
    result = sqrt(k);
    if (errno == 0)
        printf("%f ", result);
    else if (errno == EDOM)
        perror("Ocorreu um erro");

    errno = 0;
    result = exp(num);
    if (errno == 0)
        printf("%f ", result);
    else if (errno == ERANGE)
        perror("Ocorreu um erro");

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