/*
* Name: Mansi Patel
*/

#include <time.h>
#include <math.h>
#include <chrono>
#include <random>
#include <algorithm>

// generates pseudorandom floats between MIN and MAX
float rnd_num(float MIN, float MAX) {
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::uniform_real_distribution<float> dist(MIN, MAX);
    return dist(rng);
}

// generates pseudorandom integers between MIN and MAX
int rnd_num(int MIN, int MAX) {
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::uniform_int_distribution<int> dist(MIN, MAX);
    return dist(rng);
}

// coin flip returns true with 50% chance, returns false otherwise
bool coin_flip() {
    float probe = rnd_num(0.0f, 1.0f);
    if (probe > 0.5f) {
        return true;
    }
    return false;
}