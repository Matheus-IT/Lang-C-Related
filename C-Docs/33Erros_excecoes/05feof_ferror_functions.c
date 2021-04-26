#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /*
            *** The feof and ferror Functions ***
        - In addition to checking for a NULL file pointer and using errno, the feof() and
        ferror() functions can be used for determining file I/O errors:
        - feof(fp) Returns a nonzero value if the end of stream has been reached, 0 otherwise.
        feof also sets EOF.
        - ferror(fp) Returns a nonzero value if there is an error, 0 for no error.
        - The following program incorporates several exception handling techniques:
    */
    FILE *fptr;
    int c;

    errno = 0;
    fptr = fopen("c:\\myfile.txt", "r");
    if (fptr == NULL) {
        perror("Erro ocorreu");
        exit(EXIT_FAILURE);
    }

    while ((c = getc(fptr)) != EOF) { /* read the rest of the file */
        printf("%c", c);
    }
    if (ferror(fptr)) {
        printf("I/O error reading file.");
        exit(EXIT_FAILURE);
    }
    else if (feof(fptr)) {
        printf("End of file reached.");
    }
    fclose(fptr);

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