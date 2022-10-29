#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "rock.hpp"

void RockInRio();
std::vector<float> createScoresVector(int A, int S);
void printScores(std::vector<float> sums);

int main() {
  
  //make a vector of ints
  std::vector<int> v;

  //make a map of strings to ints
  std::map<std::string, int> m;

  // call a function in another file
  RockInRio();
}

// Ler entradas e checar se os votos sao satisfaziveis
void RockInRio() {
    int A = 0, S = 0;
    std::vector<float> scoreSums;

    do {
        std::cin >> A >> S;
        scoreSums = createScoresVector(A, S);
        printScores(scoreSums);

    } while (A > 0 && S > 0);

}

std::vector<float> createScoresVector(int A, int S) {
    float score = 0;
    std::vector<float> scoreSums(S, 0);

    for (int i = 0; i < A; i++) {
        for (int j = 0; j < S; j++) { 
            std::cin >> score;
            scoreSums[j] += score;
        }
    }

    return scoreSums;
}

void printScores(std::vector<float> sums) {
    int j = 1;
    for (auto i = sums.begin(); i != sums.end(); i++, j++) {
        std::cout << "Show " << j << ": " << *i << std::endl;
    }
}