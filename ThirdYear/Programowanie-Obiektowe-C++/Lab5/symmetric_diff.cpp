#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename T>
void printSymmetricDifferenceSum(const set<T>& firstSet, const set<T>& secondSet)
{
    set<T> exclusiveElements;
    set_symmetric_difference(
        firstSet.begin(), firstSet.end(),
        secondSet.begin(), secondSet.end(),
        inserter(exclusiveElements, exclusiveElements.begin())
    );

    T totalSum = T();
    for (const T& element : exclusiveElements)
        totalSum += element;

    cout << "Suma elementow wykluczajacych: " << totalSum << endl;
}

int main()
{
    set<int> firstIntSet = {1, 2, 3, 7};
    set<int> secondIntSet = {-2, 1, 4, 6, 7};
    printSymmetricDifferenceSum(firstIntSet, secondIntSet);

    set<double> firstDoubleSet = {1.5, 2.5, 4.0};
    set<double> secondDoubleSet = {2.5, 3.0};
    printSymmetricDifferenceSum(firstDoubleSet, secondDoubleSet);

    return 0;
}