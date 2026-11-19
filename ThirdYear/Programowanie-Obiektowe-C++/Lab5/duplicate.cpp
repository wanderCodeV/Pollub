#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

pair<int, int> findDuplicateAndSum(const vector<int>& numbers)
{
    set<int> uniqueNumbers;
    int duplicate = 0;
    int uniqueSum = 0;

    for (int number : numbers)
    {
        auto result = uniqueNumbers.insert(number);
        if (!result.second)
            duplicate = number;
        else
            uniqueSum += number;
    }

    return make_pair(duplicate, uniqueSum);
}

int main()
{
    vector<int> sampleNumbers = {4, 7, 2, 9, 7, 1, 5};
    pair<int, int> analysisResult = findDuplicateAndSum(sampleNumbers);

    cout << "Zduplikowana wartosc: " << analysisResult.first << endl;
    cout << "Suma unikatowych elementow: " << analysisResult.second << endl;

    return 0;
}