#include <random>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <chrono>
#include <unordered_map>
#include <numeric>

const int numRuns = 1000000;

typedef std::unordered_map<int, int> specialSpaces_t;

specialSpaces_t LADDERS{
    {1, 38},
    {4, 14},
    {9, 31},
    {21, 42},
    {28, 84},
    {36, 44}, 
    {51, 67},
    {71, 91},
    {80, 100},
};

specialSpaces_t SNAKES{
    {16, 6},
    {47, 26},
    {49, 11},
    {56, 53},
    {62, 19},
    {64, 60},
    {87, 24},
    {93, 73},
    {95, 75},
    {98, 78},
};

// std::random_device rd;
// std::mt19937_64 generator(rd());
// std::uniform_int_distribution<int> distribution(1,6);

//---------------------------------------------------------------------------
int roll(void){
    // return distribution(generator);
    return rand() % 6 + 1;
}

//---------------------------------------------------------------------------
int simulateSingleGame(specialSpaces_t ladders, specialSpaces_t snakes){
    int turns = 0;
    int spot = 0;

    int rollVal;

    while(spot != 100){
        rollVal = roll();
        spot += rollVal;
        if(spot > 100){
            spot -= rollVal;
        }
        else{
            // see if we're on a special spot
            if(SNAKES[spot]){
                spot = SNAKES[spot];
            }
            else if(LADDERS[spot]){
                spot = LADDERS[spot];
            }
            // not a special spot so stay there (do nothing)
        }

        turns += 1;
    }

    return turns;
}

//---------------------------------------------------------------------------
std::array<int, numRuns> turns;
float averageTurns(void){
    for(auto &turn : turns){
        turn = simulateSingleGame(LADDERS, SNAKES);
    }

    int sum = std::accumulate(turns.begin(), turns.end(), 0);

    return sum / float(numRuns);
}

//---------------------------------------------------------------------------
int main(void){
    //give the generator a good random seed
    // typedef std::chrono::high_resolution_clock myclock;
    // generator.seed(myclock::now().time_since_epoch().count());
    srand(time(NULL));

    std::cout << averageTurns() << std::endl;

    return 0;
}