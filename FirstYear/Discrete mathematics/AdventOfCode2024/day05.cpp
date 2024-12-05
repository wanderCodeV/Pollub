#include <bits/stdc++.h>

using namespace std;

void first_part(const vector<pair<int, int>>& input, const vector<string>& check)
{
    int sum = 0;
    for (const auto& line : check)
    {
        //cout << line << endl;
        int num, i = 1;
        istringstream line_stream(line);
        unordered_map<int, int> dict;
        vector<int> update_elem;

        while (line_stream >> num)
        {
            dict[num] = i;
            update_elem.push_back(num);
            i++;
        }

        bool flag = true;
        for (const auto& elem : input)
        {
            // cout << dict[elem.first] << " " << dict[elem.second] << endl;
            if(dict[elem.first] != 0 && dict[elem.second] != 0)
            {
                if (!(dict[elem.second] > dict[elem.first]))
                {
                    flag = false;
                    break;
                }
            }
        }

        if (flag)
        {
            int mid = update_elem.size() / 2;
            sum += update_elem[mid];
        }
    }
    cout << sum << endl;
}

void second_part(const vector<pair<int, int>>& input, const vector<string>& check)
{
    int sum = 0;
    for (const auto& line : check)
    {
        int num, i = 1;
        istringstream line_stream(line);
        unordered_map<int, int> dict;
        vector<int> update_elem;

        while (line_stream >> num)
        {
            dict[num] = i;
            update_elem.push_back(num);
            i++;
        }

        bool flag = true;
        unordered_map<int, int> curr_dict;
        for (const auto& elem : input)
        {
            if(dict[elem.first] != 0 && dict[elem.second] != 0)
            {
                curr_dict[elem.second]++;
                if (!(dict[elem.second] > dict[elem.first]))
                {
                    flag = false;
                }
            }
        }

        if (!flag)
        {
            int mid = update_elem.size() / 2;
            for (auto it = curr_dict.begin(); it != curr_dict.end(); ++it)
            {
                if(it->second == mid)
                    sum += it->first;
                //cout << "Key: " << it->first << ", Value: " << it->second << endl;
            }
        }
    }
    cout << sum << endl;
}
int main()
{
    ifstream myFile("input.txt");

    if (!myFile.is_open())
    {
        cout << "Unable to open file" << endl;
        return 1;
    }

    string line;
    vector<pair<int, int>> input;
    vector<string> check;
    bool reading_constraints = true;

    while (getline(myFile, line))
    {
        if (line.empty())
        {
            reading_constraints = false;
            continue;
        }

        if (reading_constraints)
        {
            // Replace '|' with space and parse the constraints
            replace(line.begin(), line.end(), '|', ' ');
            istringstream line_stream(line);
            int first, second;
            line_stream >> first >> second;
            input.emplace_back(first, second);
        }
        else
        {
            // Replace ',' with space and parse the sequences
            replace(line.begin(), line.end(), ',', ' ');
            check.push_back(line);
        }
    }

    myFile.close();
    //first_part(input, check);
    second_part(input, check);

    return 0;
}
