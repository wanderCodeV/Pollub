#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>

using namespace std;

int sumOfDigits(int value) {
    int sum = 0;
    value = abs(value);
    while (value > 0) {
        sum += value % 10;
        value /= 10;
    }
    return sum;
}

int countDigits(int value) {
    int count = 0;
    value = abs(value);
    if (value == 0)
        return 1;
    while (value > 0) {
        count++;
        value /= 10;
    }
    return count;
}

bool ascSumFunc(int first, int second) {
    return sumOfDigits(first) < sumOfDigits(second);
}

struct DescSumFunctor {
    bool operator()(int first, int second) const {
        return sumOfDigits(first) > sumOfDigits(second);
    }
};

void printElement(int value) {
    cout << value << " ";
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 10000);

    vector<int> numbers;
    for (int i = 0; i < 16; ++i)
        numbers.push_back(dist(gen));

    for_each(numbers.begin(), numbers.end(), printElement);
    cout << "\n\n";

    sort(numbers.begin(), numbers.end(), ascSumFunc);
    for_each(numbers.begin(), numbers.end(), printElement);
    cout << "\n\n";

    sort(numbers.begin(), numbers.end(), DescSumFunctor());
    for_each(numbers.begin(), numbers.end(), printElement);
    cout << "\n\n";

    auto ascCountLambda = [](int first, int second) {
        return countDigits(first) < countDigits(second);
    };
    sort(numbers.begin(), numbers.end(), ascCountLambda);
    for_each(numbers.begin(), numbers.end(), printElement);
    cout << "\n\n";

    sort(numbers.begin(), numbers.end(), [](int first, int second) { return countDigits(first) > countDigits(second); });
    for_each(numbers.begin(), numbers.end(), printElement);
    cout << "\n";

    return 0;
}