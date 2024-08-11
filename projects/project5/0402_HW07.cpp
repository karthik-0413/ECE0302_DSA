#include <iostream>
using namespace std;

int main()
{
    // 0 - AND
    // 1 - XOR
    // 2 - NAND
    // 3 - OR
    // P(M) = 0.2
    // P(M') = 0.8
    // P(A) = 16/256 = 0.0625
    // P(A') = 0.9375
    // P(X) = 0.316
    // P(X') = 0.684

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                for (int l = 0; l < 2; l++)
                {
                    cout << i << " " << j << " " << k << " " << l << " " << endl;
                }
            }
        }
    }
    return 0;
}