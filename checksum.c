/********************************/
/* Program Name:                */
/* Author:                      */
/* Date:                        */
/********************************/
/* Description:                 */
/* Validation Checks:           */
/* Enhancements:                */
/********************************/

#include "stdio.h"
#include "stdlib.h"

#define max_int (255)
#define byte (char)

int main(int argc, char* argv[], char** envp) {

    int count = 10;
    int sum = 0;
    byte checksum = 0;
    byte complement = 0;

    /* the following is the prototype for the read system call */
    /* int read(int fildes, void *buf, size_t nbyte);  */

    byte num[count];
    int readNum = read(0, &num, sizeof(byte));

    if (readNum > 0)
    {
        for (int i = 0; i < count; i++)
        {
            fprintf(stdout, "%d ", num[i]);
        }
    }
    
    fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
    if (checksum != complement) {
        fprintf(stderr, "Error Detected!\n");
        return 1;
    }
    return 0;
}