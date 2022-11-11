#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "rock.hpp"

void RockInRio();
std::vector<float> createScoresVector(int A, int S);
void getBestShows(std::vector<float> scores);
void printScores(std::vector<float> scores);

int main() {
  
  //make a vector of ints
  std::vector<int> v;

  //make a map of strings to ints
  std::map<std::string, int> m;

  // call a function in another file
  RockInRio();
}

// Le entradas e checa se os votos sao satisfaziveis
void RockInRio() {
    int A = 0, S = 0;
    std::vector<float> scoreSums;

    do {
        std::cin >> A >> S;
        scoreSums = createScoresVector(A, S);
        getBestShows(scoreSums);
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

void printBestShows(std::vector<float> scores) {
    return;
}

void printScores(std::vector<float> scores) {
    int j = 1;
    for (auto i = scores.begin(); i != scores.end(); i++, j++) {
        std::cout << "Show " << j << ": " << *i << std::endl;
    }
}