#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() {
    /*
            *** The perror and strerror Functions ***
        When a library function sets errno, a cryptic error number is assigned:
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
        - You can obtain the message using strerror() in the string.h header
        file, which returns a pointer to the message text.
        - For a more descriptive message about the error, you can use perror("string").
    */
    FILE *fptr;

    // Usando strerror:
    errno = 0;
    fptr = fopen("c:\\nonexistantfile.txt", "r");
    if (fptr == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        //exit(EXIT_FAILURE);
    }

    // Usando perror:
    fptr = fopen("c:\\nonexistantfile.txt", "r");
    if (fptr == NULL) {
        perror("Error");
        //exit(EXIT_FAILURE);
    }

    fclose(fptr);
    return 0;
}
