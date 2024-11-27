#include <iostream>
#include <vector>

using namespace std;

void printPermutations(vector<int>& nums, int l, int r) 
{
    if (l == r)
    {
        for (int num : nums) 
            cout << num << " ";
        cout << endl;
    } 
    else 
        for (int i = l; i <= r; ++i) 
        {
            swap(nums[l], nums[i]);
            printPermutations(nums, l + 1, r);
            swap(nums[l], nums[i]); 
        }
}

void generatePermutations(int n) 
{
    vector<int> numbers;
    for (int i = 0; i < n; ++i)
        numbers.push_back(i + 1);
    printPermutations(numbers, 0, n - 1);
}

int main() 
{
    int n;
    cout << "Wprowadź liczbę n: ";
    cin >> n;

    generatePermutations(n);
    return 0;
}
