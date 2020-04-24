#ifndef SEQUENCE
#define SEQUENCE
#include "sequence.h"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <utility>
#include <vector>

Sequence::Sequence(std::vector<char> alphabet)
{
    trueseq = new char[4];
    makerand(alphabet);
}

Sequence::~Sequence()
{
    delete[] trueseq;
}

std::pair<int, int> Sequence::count_bulls_and_cows(std::string input, int n)
{
    int bulls = 0, cows = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                if (input[i] == trueseq[j]) {
                    ++cows;
                }
            } else {
                if (input[i] == trueseq[j])
                    ++bulls;
            }
        }
    }
    std::pair<int, int> a;
    a.first = bulls;
    a.second = cows;
    std::cout << "true : " << trueseq << std::endl;
    return a;
}

void Sequence::makerand(std::vector<char> alphabet)
{
    srand(time(0));
    std::random_shuffle(alphabet.begin(), alphabet.end());
    for (int i = 0; i < 4; ++i)
        trueseq[i] = alphabet[i];
}

#endif