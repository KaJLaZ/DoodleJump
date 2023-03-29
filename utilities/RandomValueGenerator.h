#pragma once
#include <random>

class RandomValueGenerator
{
public:
    RandomValueGenerator(std::default_random_engine randomEngine, std::uniform_int_distribution<unsigned> distribution)
        : randomEngine(randomEngine),
          distribution(distribution){}

    int generateRandomInt()
    {
        return distribution(randomEngine);
    }

private:
    
    std::default_random_engine randomEngine;
    std::uniform_int_distribution<unsigned> distribution;

};
