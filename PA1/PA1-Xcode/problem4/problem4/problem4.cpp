//
//  problem4.cpp
//  problem4
//
//  Created by Edward Keenan & Yuancheng Zhang on 10/3/15.
//

#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <limits>

#define PLAYER_NUM 5

typedef struct Vect // Vector struct for positions
{
    float x;
    float y;
    float z;
} Vect_t;


/***********************************************************************
 *  Function: findMaxDistance()
 ￼*
 *  Input:
 *      int         nPlayers - number of players
 *      Vect_t      playerArray - the array of players
 *  Output:
 *      float       maxDist - the maxDistance between any two players
 *
 ***********************************************************************/


void findMaxDistance( int nPlayers, Vect_t* playerArray, float* maxDist, float* minDist )
{
    int i,j;            // counter variables
    Vect_t tmpVect;     // temporary vector
    float tmpDistSq;    // temporary distance
    float tmpMaxDistSq; // temporary max distance square
    float tmpMinDistSq; // temporary min distance square
    
    // initialize the distances to zero and infinity
    tmpMaxDistSq = -1.0f;
    tmpMinDistSq = std::numeric_limits<float>::max();
    
    for( i = 0; i < nPlayers; i++ )
    {
        for ( j = 0; j < i; j++ )
        {
            // Find a vector between point i and j
            tmpVect.x = playerArray[i].x - playerArray [j].x;
            tmpVect.y = playerArray[i].y - playerArray [j].y;
            tmpVect.z = playerArray[i].z - playerArray [j].z;
            
            // Get its length
            tmpDistSq = tmpVect.x * tmpVect.x
                      + tmpVect.y * tmpVect.y
                      + tmpVect.z * tmpVect.z;
            
            // determine if it’s a new maximum length
            if (tmpDistSq > tmpMaxDistSq)
            {
                // yes so keep it
                tmpMaxDistSq = tmpDistSq;
            }
            if (tmpDistSq < tmpMinDistSq)
            {
                tmpMinDistSq = tmpDistSq;
            }
            //printf("%f, %f,\t%f\n", tmpMaxDistSq, tmpMinDistSq, tmpDistSq);
        } //for(j)
    } // for(i)
    *maxDist = sqrtf(tmpMaxDistSq);
    *minDist = sqrtf(tmpMinDistSq);
    
    return;
} // End of findMaxDistance()

int main(int argc, const char * argv[]) {
    // insert code here...
    Vect_t a[PLAYER_NUM];
    
    srand(461);
    for(int i = 0; i < PLAYER_NUM; i++)
    {
        a[i].x = (rand() % 10000) / 100.0f - 50.0f;
        a[i].y = (rand() % 10000) / 100.0f - 50.0f;
        a[i].z = (rand() % 10000) / 100.0f - 50.0f;
        printf("Vector[%d]:\t%0.2f,\t%0.2f,\t%0.2f\n", i, a[i].x, a[i].y, a[i].z);
    }
    
    float maxDist = std::numeric_limits<float>::min();
    float minDist = std::numeric_limits<float>::max();
    printf("\n%f, %f\n\n", maxDist, minDist);
    findMaxDistance(PLAYER_NUM, a, &maxDist, &minDist);
    printf("The max distance is %0.4f \nThe min distance is %0.4f\n\n", maxDist, minDist);
    
    return 0;
}


