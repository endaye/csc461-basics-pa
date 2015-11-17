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
 *
 *  Function: findMaxDistance()
 ￼*
 *  Input:
 *      int         nPlayers - number of players
 *      Vect_t      playerArray - the array of players
 *  Output:
 *      float       maxDist - the maxDistance between any two players
 *
 ***********************************************************************/


float findMaxDistance( int nPlayers, Vect_t* playerArray )
{
    int i,j;            // counter variables
    Vect_t tmpVect;     // temporary vector
    float tmpDist;      // temporary distance
    float maxDist;      // current max distance
    
    // initialize the distance to zero
    maxDist = 0.0f;
    
    for( i = 0; i < nPlayers; i++ )
    {
        for ( j = 0; j < i; j++ )
        {
            // Find a vector between point i and j
            tmpVect.x = playerArray[i].x - playerArray [j].x;
            tmpVect.y = playerArray[i].y - playerArray [j].y;
            tmpVect.z = playerArray[i].z - playerArray [j].z;
            
            // Get its length
            tmpDist = (float)sqrt( tmpVect.x * tmpVect.x
                                  + tmpVect.y * tmpVect.y
                                  + tmpVect.z * tmpVect.z );
            
            // determine if it’s a new maximum length
            if(tmpDist > maxDist)
            {
                // yes so keep it
                maxDist = tmpDist;
            }
            
        } // for(j)
    } // for(i)
    
    return maxDist;
} // End of findMaxDistance()

int main(int argc, const char * argv[]) {
    // insert code here...
    Vect_t a[PLAYER_NUM];
    
    srand(461);
    for(int i = 0; i < PLAYER_NUM; i++)
    {
        //a[i] = new Vect;
        a[i].x = (rand() % 10000) / 100.0f - 50.0f;
        a[i].y = (rand() % 10000) / 100.0f - 50.0f;
        a[i].z = (rand() % 10000) / 100.0f - 50.0f;
        printf("Vector[%d]:\t%0.2f,\t%0.2f,\t%0.2f\n", i, a[i].x, a[i].y, a[i].z);
    }
    
    
    float maxDist = -1.0f;
    
    maxDist = findMaxDistance(5, a);
    printf("The max distance is %0.4f\n", maxDist);
    
    return 0;
}


