/*  Chad Callender
    CMPS 4103
    Mini Project #4
*/
// To compile use g++ mini_4.cpp

#include<iostream>
#include<random>

using namespace std;

int main()
{
    int skipped = 0;                    // counts skipped holes for each experiment
    int total = 0;                      // counts sum of all skipped holes
    float average = 0;                    // average of skipped holes for 10 trials
    int bit = 0;                        // bit of the stored number
    int count = 0;                      // keeps track of the number of zeros

    mt19937 rng;
    uint32_t seed_val;
    rng.seed(seed_val);
    uniform_int_distribution<uint32_t> uint_dist10(70000,2000000); // distribution in range [1, 6]

    union
    { // x and a share the same address space
        int x;
        unsigned char a[4];
    }z;

    // cout << hex << (int)z.a[0] << endl;

    for(int k = 1; k <= 10; k++)
    { // loop 10 times for 10 trials
        cout << "Trial: " << k << endl;
        skipped = 0;                // resets skipped hole counter
        z.x = uint_dist10(rng);     // generates random number
        cout << z.x << endl;

        for(int j = 0; j < 4; j++)
        {
            for(int i = 7; i >= 0; i--)
            {
                bit = z.a[j] >> i;              // shifts bit until it is LSB
                bit = bit & 1;                  // extracts LSB
                cout << bit;

                if(bit == 0)
                    count++;                    // counts zeros
                else // bit is 1
                {
                    if(count != 0)
                    { // there is a switch from a 0 to 1
                        count = 0;
                        skipped++;
                        total++;
                    }

                }
                
                if(count == 4)
                { // yay! we have space for a file of 4 blocks
                    cout << "\nSkipped holes: " << skipped << "\n\n";
                    j = 4;
                    break;
                }
            }
        }
    }

    cout << "Total skips: " << total << endl;
    average = total/10.0;
    cout << "Average number of holes skipped (for 10 trials): " << average;

    return 0;
}

// 0000 0000 0000 0001 0001 0001 0111 0000

// 0111 0000 0001 0001 0000 0001 0000 0000