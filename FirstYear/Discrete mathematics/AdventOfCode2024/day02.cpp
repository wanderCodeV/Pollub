#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

bool check_vector(const vector<int>& numbers)
{
    int n = numbers.size();
    if (n < 2)
        return true;
    if(numbers[1] == numbers[0])
        return false;

    int sign = (numbers[1] - numbers[0]) / abs(numbers[1] - numbers[0]);
    for (int i = 1; i < n; i++)
    {
        int diff = numbers[i] - numbers[i - 1];
        int curr_sign = diff / abs(diff);
        if (!(abs(diff) >= 1 && abs(diff) <= 3 && curr_sign == sign))
            return false;
    }
    return true;
}
void first_part(vector <string> input)
{
    int cnt = 0;
    for(auto line: input)
    {
        stringstream ss(line);
        vector<int> numbers;
        int num;
        while (ss >> num)
            numbers.push_back(num);
        int n = numbers.size();
        if (check_vector(numbers))
            cnt++;

    }
    cout << cnt << endl;
}



void second_part(vector <string> input)
{
    int cnt = 0;
    for(auto line: input)
    {
        stringstream ss(line);
        vector<int> numbers;
        int num;
        while (ss >> num)
            numbers.push_back(num);
        if (check_vector(numbers))
        {
            cnt++;
            continue;
        }

        bool fixed = false;
        for (size_t i = 0; i < numbers.size() && !fixed; i++)
        {
            vector<int> modified = numbers;
            modified.erase(modified.begin() + i);
            if (check_vector(modified))
            {
                fixed = true;
                break;
            }
        }

        if (fixed)
            cnt++;


    }
    cout << cnt;
}

int main()
{
    ifstream myFile;

    myFile.open("input.txt");

    if (!myFile.is_open())
    {
        cout << "Unable to open file" << endl;
        return 1;
    }

    string line;
    vector<string> input;
    while (getline(myFile, line))
    {
        input.push_back(line);
    }

    first_part(input);
    second_part(input);
}
