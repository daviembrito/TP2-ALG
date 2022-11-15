#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "rock.hpp"

#define MINUSINFINITY -10000

std::vector<float> createScoresVector(int A, int S);
void printBestShows(std::vector<float> scores);
std::vector<float> maxShowSequence(std::vector<float> A, float low, float high);
std::vector<float> maxCrossSequence(std::vector<float> A, float low, float mid, float high);

int main() {
    // Inicializando variaveis para guardar entradas
    int A = 0, S = 0;
    std::vector<float> scoreSums;

    // Lendo entradas
    std::cin >> A >> S;
    while (A > 0 && S > 0) {
        // Criando o vetor de notas dos shows
        scoreSums = createScoresVector(A, S);

        // Imprimindo a sequencia de shows com maior nota agregada
        printBestShows(scoreSums);
        std::cin >> A >> S;
    } 
}

// Le notas e soma ao vetor final retornado
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

// Imprime o numero inicial e final da sequencia de shows com maior nota agregada
void printBestShows(std::vector<float> scores) {
    std::vector<float> results = maxShowSequence(scores, 0, scores.size()-1);
    std::cout << results[0]+1 << " " << results[1]+1 << std::endl;
}

// Calcula os indices da maior subsequencia de notas de shows 
std::vector<float> maxShowSequence(std::vector<float> A, float low, float high) {
    if (high == low) {
        std::vector<float> results = {low, high, A[low]};
        return results;
    } 
        
    int mid = (low + high)/2;
    
    std::vector<float> left = maxShowSequence(A, low, mid);
    std::vector<float> right = maxShowSequence(A, mid+1, high);
    std::vector<float> cross = maxCrossSequence(A, low, mid, high);

    if (left[2] >= right[2] && left[2] >= cross[2])
        return left;
    else if (right[2] >= left[2] && right[2] >= cross[2])
        return right;
    else
        return cross;
}

// Funcao auxiliar para calcular a maior subsequencia cruzada de duas partes do vetor
std::vector<float> maxCrossSequence(std::vector<float> A, float low, float mid, float high) {
    float maxleft = 0, maxright = 0, sum = 0;

    float leftsum = MINUSINFINITY;
    for (int i = mid; i >= low; i--) {
        sum += A[i];
        if (sum >= leftsum) {
            leftsum = sum;
            maxleft = i;
        }
    }
    
    sum = 0;
    float rightsum = MINUSINFINITY;  
    for (int j = mid+1; j <= high; j++) {
        sum += A[j];
        if (sum >= rightsum) {
            rightsum = sum;
            maxright = j;
        }
    }
    
    std::vector<float> results = {maxleft, maxright, leftsum + rightsum};
    return results;
}