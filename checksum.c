/****************************************/
/* Program Name: checksum.c             */
/* Author: Jericho Raz                  */
/* Date: 2/16/21                        */
/****************************************/
/* Description: checksum algorithm in C */
/* Validation Checks:                   */
/* Enhancements: None                   */
/****************************************/

#include "stdio.h"
#include "stdlib.h"

#define max_int (255)
#define byte unsigned char

int read(int fildes, void* buf, size_t nbyte);

int main(int argc, char* argv[], char** envp) {

    int count = 10;
    int checksumpos = 5;
    int sum = 0;
    byte checksum;
    byte complement;

    int quotient;
    int remainder;

    byte header[count];
    int numRead = read(0, &header, 10);

    if (numRead > 0)
    {
        for (int i = 0; i < count; i++)
        {
            if (i == checksumpos)
            {
                checksum = header[i];
                header[i] = 0;
            }

            sum += header[i];

            if (sum > max_int)
            {
                sum -= max_int;
            }

            complement = max_int - sum;
        }
    }
    
    fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
    if (checksum != complement) {
        fprintf(stderr, "Error Detected!\n");
        return 1;
    }
    return 0;
}