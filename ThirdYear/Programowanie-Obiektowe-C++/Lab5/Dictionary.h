#ifndef LAB5_DICTIONARY_H
#define LAB5_DICTIONARY_H

#include <string>
#include <map>

using namespace std;

class Dictionary
{
private:
    map<string, string> words;

public:
    Dictionary();
    void addWord(const string& word, const string& translation);
    void removeWord(const string& word);
    void showAll() const;
    void showTranslation(const string& word) const;
    void sortAlphabetically(bool byTranslation = false) const;
};

#endif //LAB5_DICTIONARY_H
