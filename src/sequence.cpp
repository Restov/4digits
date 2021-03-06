#include "sequence.h"

Sequence::Sequence(std::vector<char> alphabet, int lenght)
{
    seq_lenght = lenght;
    makerand(alphabet);
}

Sequence::~Sequence()
{
}

std::string Sequence::get_answer()
{
    return trueseq;
}

bool Sequence::set_trueseq(std::string new_seq)
{
    int size = new_seq.size();
    if (size == seq_lenght) {
        trueseq = new_seq;
        return true;
    }
    return false;
}

std::pair<int, int> Sequence::count_bulls_and_cows(std::string input)
{
    int bulls = 0, cows = 0;
    for (int i = 0; i < seq_lenght; ++i) {
        for (int j = 0; j < seq_lenght; ++j) {
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
    return a;
}

void Sequence::makerand(std::vector<char> alphabet)
{
    srand(time(0));
    std::random_shuffle(alphabet.begin(), alphabet.end());
    for (int i = 0; i < seq_lenght; ++i) {
        trueseq.push_back(alphabet[i]);
    }
}
