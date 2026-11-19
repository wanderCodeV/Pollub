#include <iostream>
#include "Dictionary.h"

using namespace std;

int main()
{
    Dictionary myDictionary;

    myDictionary.addWord("kot", "cat");
    myDictionary.addWord("pies", "dog");
    myDictionary.addWord("jablko", "apple");
    myDictionary.addWord("samochod", "car");
    myDictionary.addWord("kot", "kitty");

    cout << endl;
    myDictionary.showAll();

    cout << endl;
    myDictionary.showTranslation("pies");
    myDictionary.showTranslation("dom");

    cout << endl;
    myDictionary.sortAlphabetically(false);

    cout << endl;
    myDictionary.sortAlphabetically(true);

    cout << endl;
    myDictionary.removeWord("pies");
    myDictionary.showAll();

    return 0;
}