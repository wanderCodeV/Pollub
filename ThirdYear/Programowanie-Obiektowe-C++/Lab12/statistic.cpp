#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
tuple<int, double, string>  func(const vector<string> &words) {
    if (words.empty())
        return make_tuple(0,0,"");

    int min_len = min_element(words.begin(), words.end(),
        [](const string &a, const string &b) -> bool {
            return a.length() < b.length();
        }
    )->length();

    int n = words.size();
    double sum = 0;
    for_each(words.begin(), words.end(),
        [&sum](const string &word) {
            sum += word.length();
        });
    double avg = sum / n;

    string max_word = *max_element(words.begin(), words.end(),
        [](const string &a, const string &b) -> bool {
           return a.length() < b.length();
        });

    return make_tuple( min_len, avg, max_word);
}
int main() {
    
    vector<string> words = {"Mariia", "Kot", "Programowanie", "C++", "Ja"};
    auto res = func(words);

    cout << get<0>(res) << " " << get<1>(res) << " " << get<2>(res) << endl;
}