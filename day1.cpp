#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <fstream>

std::pair<int, int> task1CPP()
{
    constexpr size_t input_size = 5;
    constexpr size_t space_size = 3;
    std::ifstream file("read.txt");
    std::string str; 

    std::priority_queue<int> Id1s;
    std::priority_queue<int> Id2s;

    std::unordered_map<int, int> mRightSimilarity;
    while (std::getline(file, str))
    {
        // Process str
        Id1s.push(std::atoi(str.substr(0, input_size).c_str()));
        Id2s.push(std::atoi(str.substr(input_size + space_size, input_size).c_str()));
        ++mRightSimilarity[std::atoi(str.substr(input_size + space_size, input_size).c_str())];
    }

    int sum = 0;
    int similarityScore = 0;
    while(!Id1s.empty() && !Id2s.empty())
    {
        if(mRightSimilarity.contains(Id1s.top()))
        {
            similarityScore += (mRightSimilarity[Id1s.top()] * Id1s.top());
        }
        sum += abs(Id1s.top() - Id2s.top());
        Id1s.pop();
        Id2s.pop();
    }
    return {sum, similarityScore};
}

int main()
{
    const auto [diffSum, similarity] = task1CPP();
    std::cout << diffSum << ", " <<  similarity << '\n';

    return 0;
}