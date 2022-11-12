#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "rock.hpp"

#define NINFINITY -10000

std::vector<float> createScoresVector(int A, int S);
void printBestShows(std::vector<float> scores);
std::vector<float> maxSubarray(std::vector<float> A, float low, float high);
std::vector<float> maxCrossSubarray(std::vector<float> A, float low, float mid, float high);
void printScores(std::vector<float> scores);

int main() {
    int A = 0, S = 0;
    std::vector<float> scoreSums;

    std::cin >> A >> S;
    while (A > 0 && S > 0) {
        scoreSums = createScoresVector(A, S);
        printBestShows(scoreSums);
        std::cin >> A >> S;
    } 
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
    std::vector<float> results = maxSubarray(scores, 0, scores.size()-1);
    std::cout << results[0]+1 << " " << results[1]+1 << std::endl;
}

void printScores(std::vector<float> scores) {
    int j = 1;
    for (auto i = scores.begin(); i != scores.end(); i++, j++) {
        std::cout << "Show " << j << ": " << *i << std::endl;
    }
}

std::vector<float> maxSubarray(std::vector<float> A, float low, float high) {
    if (high == low) {
        std::vector<float> results = {low, high, A[low]};
        return results;
    } 
        
    int mid = (low + high)/2;
    
    std::vector<float> left = maxSubarray(A, low, mid);
    std::vector<float> right = maxSubarray(A, mid+1, high);
    std::vector<float> cross = maxCrossSubarray(A, low, mid, high);

    if (left[2] >= right[2] && left[2] >= cross[2])
        return left;
    else if (right[2] >= left[2] && right[2] >= cross[2])
        return right;
    else
        return cross;
}

std::vector<float> maxCrossSubarray(std::vector<float> A, float low, float mid, float high) {
    float maxleft = 0, maxright = 0, sum = 0;

    float leftsum = NINFINITY;
    for (int i = mid; i >= low; i--) {
        sum = sum + A[i];
        if (sum >= leftsum) {
            leftsum = sum;
            maxleft = i;
        }
    }
    
    sum = 0;
    float rightsum = NINFINITY;  
    for (int j = mid+1; j <= high; j++) {
        sum = sum + A[j];
        if (sum >= rightsum) {
            rightsum = sum;
            maxright = j;
        }
    }
    
    std::vector<float> results = {maxleft, maxright, leftsum + rightsum};
    return results;
}