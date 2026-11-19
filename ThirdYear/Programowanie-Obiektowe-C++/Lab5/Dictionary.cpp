#include "Dictionary.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

Dictionary::Dictionary() {}

void Dictionary::addWord(const string& word, const string& translation)
{
    if (words.count(word) > 0)
        cout << "Slowo '" << word << "' juz istnieje w slowniku." << endl;
    else
        words.insert(make_pair(word, translation));
}

void Dictionary::removeWord(const string& word)
{
    if (words.erase(word) > 0)
        cout << "Usunieto slowo: " << word << endl;
    else
        cout << "Nie znaleziono slowa do usuniecia: " << word << endl;
}

void Dictionary::showAll() const
{
    cout << "Zawartosc slownika:" << endl;
    for (const auto& entry : words)
        cout << entry.first << " -> " << entry.second << endl;
}

void Dictionary::showTranslation(const string& word) const
{
    auto it = words.find(word);
    if (it != words.end())
        cout << "Tlumaczenie dla '" << word << "': " << it->second << endl;
    else
        cout << "Brak slowa '" << word << "' w slowniku." << endl;
}

void Dictionary::sortAlphabetically(bool byTranslation) const
{
    vector<pair<string, string>> sortedEntries(words.begin(), words.end());

    if (!byTranslation)
        sort(sortedEntries.begin(), sortedEntries.end(), [](const pair<string, string>& a, const pair<string, string>& b)
        {
            return a.first < b.first;
        });
    else
        sort(sortedEntries.begin(), sortedEntries.end(), [](const pair<string, string>& a, const pair<string, string>& b)
        {
            return a.second < b.second;
        });

    cout << (byTranslation ? "Posortowane po tlumaczeniu:" : "Posortowane po slowie oryginalnym:") << endl;
    for (const auto& entry : sortedEntries)
        cout << entry.first << " -> " << entry.second << endl;
}