#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>

using namespace std;

// Directions and their respective changes in row and column
const vector<pair<int, int>> directions =
{
    {-1, 0}, // Up
    {0, 1},  // Right
    {1, 0},  // Down
    {0, -1}  // Left
};

void findGuardStart(const vector<string>& input_map, int& startX, int& startY, int& startDir)
{
    for (int i = 0; i < input_map.size(); ++i)
    {
        for (int j = 0; j < input_map[i].size(); ++j)
        {
            if (input_map[i][j] == '^')
            {
                startX = i;
                startY = j;
                startDir = 0;
                return;
            }
            else if (input_map[i][j] == '>')
            {
                startX = i;
                startY = j;
                startDir = 1;
                return;
            }
            else if (input_map[i][j] == 'v')
            {
                startX = i;
                startY = j;
                startDir = 2;
                return;
            }
            else if (input_map[i][j] == '<')
            {
                startX = i;
                startY = j;
                startDir = 3;
                return;
            }
        }
    }
}

void first_part(vector<string> input_map)
{
    int startX = 0, startY = 0, dir = 0; // dir: 0 = up, 1 = right, 2 = down, 3 = left
    findGuardStart(input_map, startX, startY, dir);
    set<pair<int, int>> visited;
    int x = startX, y = startY;
    visited.insert({x, y});

    while (true)
    {
        int nextX = x + directions[dir].first;
        int nextY = y + directions[dir].second;
        if (nextX < 0 || nextX >= input_map.size() || nextY < 0 || nextY >= input_map[0].size() || input_map[nextX][nextY] == '#')
            dir = (dir + 1) % 4;
        else
        {
            x = nextX;
            y = nextY;
            visited.insert({x, y});
        }

        if (x <= 0 || x >= input_map.size() - 1 || y <= 0 || y > input_map[0].size() - 1)
            break;
    }

    cout << "Distinct positions visited: " << visited.size() << endl;
}
string encodeState(int x, int y, int dir)
{
    return to_string(x) + "," + to_string(y) + "," + to_string(dir);
}

bool causesLoop(vector<string> input_map, int startX, int startY, int startDir, int ox, int oy)
{
    input_map[ox][oy] = '#';

    set<string> seenStates;
    int x = startX, y = startY, dir = startDir;

    while (true)
    {

        string state = encodeState(x, y, dir);
        if (seenStates.count(state))
            return true;
        seenStates.insert(state);

        int nextX = x + directions[dir].first;
        int nextY = y + directions[dir].second;

        if (nextX < 0 || nextX >= input_map.size() || nextY < 0 || nextY >= input_map[0].size() || input_map[nextX][nextY] == '#')
            dir = (dir + 1) % 4;
        else
        {
            x = nextX;
            y = nextY;
        }

        if (x <= 0 || x >= input_map.size() - 1 || y < 0 || y >= input_map[0].size() - 1)
           break;

    }
    return false;
}

int findValidObstructionPositions(const vector<string>& input_map, int startX, int startY, int startDir)
{
    int loopCount = 0;
    for (int i = 0; i < input_map.size(); ++i)
    {
        for (int j = 0; j < input_map[i].size(); ++j)
        {
            if (input_map[i][j] == '.' && !(i == startX && j == startY))
            {
                if (causesLoop(input_map, startX, startY, startDir, i, j))
                {
                    cout << "Obstruction at (" << i << ", " << j << ") causes a loop." << endl;
                    loopCount++;
                }
            }
        }
    }
    return loopCount;
}

void second_part(vector<string> input_map)
{
    int startX = 0, startY = 0, startDir = 0;
    findGuardStart(input_map, startX, startY, startDir);
    int loopCount = findValidObstructionPositions(input_map, startX, startY, startDir);
    cout << "Number of valid obstruction positions: " << loopCount << endl;
}
int main()
{
    ifstream inputFile("input.txt");
    vector<string> input_map;
    string line;
    while (getline(inputFile, line))
    {
        input_map.push_back(line);
    }
    inputFile.close();
    first_part(input_map);
    second_part(input_map);

    return 0;
}
