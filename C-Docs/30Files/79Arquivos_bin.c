#include <stdio.h>
#include <stdlib.h>


int main(){
    /*
    == Binary file mode options for the fopen() function are ==
    - rb open for reading (file must exist)
    - wb open for writing (file need not exist)
    - ab open for append (file need not exist)
    - rb+ open for reading and writing from beginning
    - wb+ open for reading and writing, overwriting file
    - ab+ open for reading and writing, appending to file
   
    fwrite(ptr, item_size, num_items, fp) Writes num_items items of item_size size from pointer
    ptr to the file pointed to by file pointer fp.
    
    fread(ptr, item_size, num_items, fp) Reads num_items items of item_size size from the file
    pointed to by file pointer fp into memory pointed to by ptr. 

    fclose(fp) Closes file opened with file fp, returning 0 if close was successful. EOF is returned
    if there is an error in closing.
    */
    //The following program demonstrates writing to and reading from binary files:
    FILE *fptr;
    int arr[10];
    int x[10];
    int k;

    /* generate array of numbers */
    for (k = 0; k < 10; k++){
        arr[k] = k;
    }

    /* write array to file */
    fptr = fopen("79datafile.bin", "wb+");
    int item_size = sizeof(arr[0]);
    int num_items = sizeof(arr)/sizeof(arr[0]);
    fwrite(arr, item_size, num_items, fptr);
    fclose(fptr);

    /* read array from file */
    fptr = fopen("79datafile.bin", "rb");
    fread(x, item_size, num_items, fptr);
    fclose(fptr);

    /* print array */
    for (k = 0; k < 10; k++){
        printf("%d", x[k]);
    }
}
