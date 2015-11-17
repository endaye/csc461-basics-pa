//
//  problem2.cpp
//  problem2
//
//  Created by Yuancheng Zhang on 9/29/15.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;
float InvSqrt(float x);
vector<float> normalize(vector<float> a);

vector<float> normalize(vector<float> a) {
    if (a.size() != 3) {
        throw invalid_argument("The size of vector is not 3.");
    }
    float len = 0;
    for (int i = 0; i < 3; i++) {
        if (a[i] == 0.0f) {
            throw invalid_argument("The vector has zero.");
        }
        else {
            len += a[i] * a[i];
        }
    }
    len = InvSqrt(len);
    for (int i = 0; i < 3; i++) {
        a[i] *= len;
    }
    return a;
}

float InvSqrt(float x)
{
    if (x == 0.0f) {
        throw invalid_argument("Denoimnator can not be zero.");
    }
    // basic way:
    /*
     if (x == 0.0f) {
     throw invalid_argument("received negative value");
     }
     return 1.0f / sqrtf(x);
     */
    
    // Chris Lomont way:
    float xhalf = 0.5f*x;
    int i = *(int*)&x; // get bits for floating value
    i = 0x5f375a86 - (i >> 1); // gives initial guess y0
    x = *(float*)&i; // convert bits back to float
    x = x*(1.5f - xhalf*x*x); // Newton step, repeating increases accuracy
    return x;
}

int main()
{
    vector<float> a = { 3.0f, 2.0f, 1.0f };
    vector<float> b(3, 0.0f);
    
    try {
        b = normalize(a);
    }
    catch (const invalid_argument& e) {
        cout << e.what();
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 3; i++) {
        printf("%0.3f ", b[i]);
    }
    return 0;
}