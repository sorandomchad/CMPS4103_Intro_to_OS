#include<iostream>

using namespace std;

int main()
{
    int skipped = 0;
    int average = 0;
    int bit = 0;
    int count = 0;

    union
    {
        int x;
        unsigned char a[4];
    }z;
    z.x = 242099;

    cout << hex << (int)z.a[0] << endl;

    for(int j = 0; j < 4; j++)
    {
        for(int i = 7; i >= 0; i--)
        {
            bit = z.a[j] >> i;
            bit = bit & 1;
            cout << bit;

            if(bit == 0)
                count++;
            else
            {
                count = 0;
            }
            
            if(count == 4)
            {
                cout << "\nSkipped holes: " << skipped << endl;
                j = 4;
                break;
            }
        }
    }

    // average = skipped/10.0;
    // cout << "Average number of holes skipped (for 10 trials): " << average;

    return 0;
}

// 0000 0000 0000 0001 0001 0001 0111 0000

// 0111 0000 0001 0001 0000 0001 0000 0000