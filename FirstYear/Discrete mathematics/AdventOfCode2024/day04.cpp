#include <bits/stdc++.h>

using namespace std;

int countWord(string line, string word)
{
    int cnt = 0;
    size_t pos = line.find(word);
    while (pos != string::npos)
    {
        cnt++;
        pos = line.find(word, pos + 1);
    }
    return cnt;
}
int countOccurrences(string line)
{
    return countWord(line, "XMAS") + countWord(line, "SAMX");
}

void first_part(vector <string> grid)
{
    string word = "XMAS";
    int totalOccurrences = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    for (auto row : grid)
    {
        totalOccurrences += countOccurrences(row);
    }

    for (int col = 0; col < cols; ++col)
    {
        string temp;
        for (int row = 0; row < rows; ++row)
            temp += grid[row][col];
        totalOccurrences += countOccurrences(temp);
    }

    for (int d = 0; d < rows + cols - 1; ++d)
    {
        string temp;
        for (int row = 0; row < rows; ++row)
        {
            int col = d - row;
            if (col >= 0 && col < cols)
                temp += grid[row][col];
        }
        totalOccurrences += countOccurrences(temp);
    }

    for (int d = 0; d < rows + cols - 1; ++d)
    {
        string temp;
        for (int row = 0; row < rows; ++row)
        {
            int col = row - (rows - 1 - d);
            if (col >= 0 && col < cols)
                temp += grid[row][col];
        }
        totalOccurrences += countOccurrences(temp);
    }


    cout << totalOccurrences << endl;
}

void second_part(vector <string> grid)
{
    int rows = grid.size();
    if (rows < 3)
    {
        cout << 0;
        return;
    }
    int cols = grid[0].size();
    if (cols < 3)
    {
        cout << 0;
        return;
    }

    int cnt = 0;

    for (int row = 0; row < rows - 2; ++row)
    {
        for (int col = 0; col < cols - 2; ++col)
        {

            if (grid[row][col] == 'M' && grid[row][col + 2] == 'S' &&
                    grid[row + 1][col + 1] == 'A' &&
                    grid[row + 2][col] == 'M' && grid[row + 2][col + 2] == 'S')
            {
                cnt++;
            }
            else if (grid[row][col] == 'M' && grid[row][col + 2] == 'M' &&
                     grid[row + 1][col + 1] == 'A' &&
                     grid[row + 2][col] == 'S' && grid[row + 2][col + 2] == 'S')
            {
                cnt++;
            }
            else if (grid[row][col] == 'S' && grid[row][col + 2] == 'S' &&
                     grid[row + 1][col + 1] == 'A' &&
                     grid[row + 2][col] == 'M' && grid[row + 2][col + 2] == 'M')
            {
                cnt++;
            }
            else if (grid[row][col] == 'S' && grid[row][col + 2] == 'M' &&
                     grid[row + 1][col + 1] == 'A' &&
                     grid[row + 2][col] == 'S' && grid[row + 2][col + 2] == 'M')
            {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
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
    vector <string> input;
    while(myFile >> line)
    {
        input.push_back(line);
    }

    first_part(input);
    second_part(input);

}
