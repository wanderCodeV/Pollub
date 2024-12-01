#include <bits/stdc++.h>

using namespace std;
struct Tdist{
    int st;
    int fn;
};

bool cmp(Tdist a, Tdist b)
{
    if(a.st == b.st)
        return a.fn < b.fn;
    return a.st < b.st;
}

void first_part(vector <int> first_list, vector <int> second_list)
{
    sort(first_list.begin(), first_list.end());
    sort(second_list.begin(), second_list.end());
    int len_list = first_list.size();
    int sum_dist = 0;
    for(int i = 0; i < len_list; i++)
    {
        sum_dist += abs(second_list[i] - first_list[i]);
        //cout << second_list[i] << " " << first_list[i] << " -> " << abs(second_list[i] - first_list[i])<< endl;
    }
    cout << sum_dist << endl;
}

void second_part(vector <int> first_list, vector <int> second_list)
{
    int len_list = first_list.size();
    int sum_dist = 0;
    for(int elem: first_list)
    {
        int cnt = 0;
        for(int target: second_list)
        {
            if(elem == target)
                cnt++;
        }
        sum_dist += elem*cnt;
        //cout << elem << "->" <<cnt << endl;
    }
    cout << sum_dist << endl;
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
    int st, fn;
    vector <int> first_list;
    vector <int> second_list;
    while(myFile >> st >> fn)
    {
        first_list.push_back(st);
        second_list.push_back(fn);
    }

    first_part(first_list, second_list);
    second_part(first_list, second_list);
}
