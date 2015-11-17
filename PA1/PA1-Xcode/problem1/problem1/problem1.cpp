//
//  problem1.cpp
//  problem1
//
//  Created by Yuancheng Zhang on 9/27/15.
//

#include <stdio.h>

void CalculateEquation(float x)
{
    float a[6] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f };
    float y = a[5];
    // y = a[0] + a[1] * x + a[2] * x * x + a[3] * x * x * x + a[4] * x * x * x * x + a[5] * x * x * x * x * x;
    for (int i = 4; i >= 0; i--) {
        y = (y * x) + a[i];
    }
    printf("%0.3f \n", y);
    return;
}

int main()
{
    float x = 3.5f;
    CalculateEquation(x);
    return 0;
}