#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "rock.hpp"

void RockInRio();
void readScores(int A, int S);

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

    do {
        std::cin >> A >> S;
        readScores(A, S);
        std::cout << A << " " << S << std::endl;

    } while (A > 0 && S > 0);

}

void readScores(int A, int S) {
    float score = 0;
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < S; j++) { 
            std::cin >> score;
            std::cout << score << " ";
        }
        std::cout << std::endl;
    }
}