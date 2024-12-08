#include <bits/stdc++.h>
typedef unsigned long long ll;

using namespace std;

bool evaluate(ll index, ll currentValue, const vector<ll>& numbers, ll target) {
    if (index == numbers.size())
        return currentValue == target;

    if (evaluate(index + 1, currentValue + numbers[index], numbers, target))
        return true;

    if (evaluate(index + 1, currentValue * numbers[index], numbers, target))
        return true;

    return false;
}

void first_part(vector <ll> results, vector<vector<ll>> numbers)
{
    ll sum = 0;
    for(ll i = 0; i < results.size(); i++)
    {
        if(evaluate(1, numbers[i][0], numbers[i], results[i]))
            sum += results[i];
    }
    cout << sum << endl;
}
ll concatenate(ll a, ll b)
{
    string concatenated = to_string(a) + to_string(b);
    return stoll(concatenated);
}
bool evaluate_with_conc(ll index, ll currentValue, const vector<ll>& numbers, ll target) {
   // cout << index << " " << numbers.size() << " " << currentValue << " " << target << endl;

    if (index == numbers.size())
        return currentValue == target;

    if (evaluate_with_conc(index + 1, currentValue + numbers[index], numbers, target))
        return true;

    if (evaluate_with_conc(index + 1, currentValue * numbers[index], numbers, target))
        return true;

    ll concatenated = concatenate(currentValue, numbers[index]);
    if (concatenated != ULLONG_MAX && evaluate_with_conc(index + 1, concatenated, numbers, target)) {
        return true;
    }

    return false;
}


void second_part(vector <ll> results, vector<vector<ll>> numbers)
{
    ll sum = 0;
    for(ll i = 0; i < results.size(); i++)
    {
        if(evaluate_with_conc(1, numbers[i][0], numbers[i], results[i]))
             sum += results[i];
    }
    cout << sum << endl;
}
int main()
{
    ifstream inputFile("input.txt");
    string line;
    vector <ll> results;
    vector<vector<ll>> numbers;
    ll i = 0;
    while (getline(inputFile, line))
    {

        numbers.resize(i + 1);
        stringstream ss(line);
        string testValueStr;
        getline(ss, testValueStr, ':');
        ll target = stoll(testValueStr);
        results.push_back(target);
         string numbersStr;
        getline(ss, numbersStr);
        stringstream nums(numbersStr);

        ll num;
        while (nums >> num) {
            numbers[i].push_back(num);
        }
        i++;
    }
    first_part(results, numbers);
    second_part(results, numbers);

    return 0;
}

/*
7887555990494
348360680516005
*/
