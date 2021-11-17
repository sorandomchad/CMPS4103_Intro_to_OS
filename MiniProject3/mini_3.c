/*  Chad Callender
    CMPS 4103
    Mini Project #3
*/
// To compile use g++ mini_3.cpp

#include<stdio.h>

int main()
{
    FILE *fPtr = fopen("spice.txt", "r");
    int pages[12];                  // implementation of TLB of 12 entries as an array
    unsigned int code, address, page;
    int misses = 0;

    for (int i = 0; i < 12; i++)
        pages[i] = -1;              // -1 indicates TLB entry is empty

    while(fscanf(fPtr, "%d %x", &code, &address) != EOF)  // reading code and address to separate variables
    {

        page = address >> 12;
        // the offset is 12 bits (since page size is 2^12 B) and the virtual addresss
        // is 32 bits, so the page number is the leftmost 20 bits.
        // Therefore, shifting the last 12 bits to the right gives the page number.

        for(int i = 0; i < 12; i++)
        {// iterating through TLB
            if(pages[i] == page)
            {// page found in TLB
                break;                
            }
            else if(pages[i] == -1)
            {// empty TLB entry found, TLB miss
                pages[i] = page;
                misses += 1;
                // cout << hex << page;
                break;
            }
            
            if(i == 11)
            {// page is not in TLB, TLB miss
                misses += 1;
                for(int j = 0; j < 11; j++)
                    pages[j] = pages[j+1];
                    // first page brought to TLB occupuies position 0.
                    // FIFO algorithm consequently removes position 0 by
                    // copying the next element in the array to the current element
                    // i.e. moving the queue.

                pages[11] = page;       // add page to the end of the array (back of the queue)

            } 
        }     
        // printf("%d %x\n", code, page);
    }

    printf("TLB misses: %d", misses);

    fclose(fPtr);

    return 0;
}