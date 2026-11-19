#include <iostream>
#include <string>
#include <map>

using namespace std;

char findAddedCharacter(const string& firstText, const string& secondText)
{
    map<char, int> charCounts;

    for (char ch : firstText)
        charCounts[ch]++;

    for (char ch : secondText)
    {
        if (charCounts.count(ch) == 0 || charCounts[ch] == 0)
            return ch;

        charCounts[ch]--;
    }

    return '\0';
}

int main()
{
    string firstSample = "programowanie";
    string secondSample = "gramowaniekpro";

    char addedChar = findAddedCharacter(firstSample, secondSample);
    cout << "Dodany znak: " << addedChar << endl;

    string firstRepeatSample = "aabbcc";
    string secondRepeatSample = "abcabcb";

    char addedRepeatChar = findAddedCharacter(firstRepeatSample, secondRepeatSample);
    cout << "Dodany znak (z powtorzeniami): " << addedRepeatChar << endl;

    return 0;
}