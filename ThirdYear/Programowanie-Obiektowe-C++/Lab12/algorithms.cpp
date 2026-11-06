#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    auto show = [](const vector<int> &numbers) {
        for_each(numbers.begin(), numbers.end(),
        [](int elem) { cout << elem << '|'; });
        cout << endl;
    };

    vector<int> numbers = {1,-22,30,4,-15,6,7,8,11};
    int n = numbers.size();
    show(numbers);

    int sum = 0;
    for_each(numbers.begin(), numbers.end(),
        [&sum](int elem) { sum += elem; });
    cout << "Srednia = " << ((n == 0) ? 0 : double(sum)/n) << endl;

    int cnt_even = 0;
    for_each(numbers.begin(), numbers.end(),
        [&cnt_even](int elem) { if (elem % 2 == 0) cnt_even++; });
    cout << "Liczba parzystych = " << cnt_even << endl;

    auto to_remove = remove_if(numbers.begin(), numbers.end(),
        [](int elem) { return elem < 0 ;});
    numbers.erase(to_remove, numbers.end());

    cout << "Po usunieciu ujemnych: ";
    show(numbers);

    sort(numbers.begin(), numbers.end(),
        [](int elem1, int elem2) { return abs(elem1 % 2) < abs(elem2 % 2); });
    cout << "Po sortowaniu: ";
    show(numbers);

    for_each(numbers.begin(), numbers.end(),
        [](int &elem) { elem = -elem;});
    cout << "Po modyfikacji: ";
    show(numbers);

    cout << "Podaj argument: ";
    int arg;
    cin >> arg;
    int cnt = count_if(numbers.begin(), numbers.end(), [arg](int elem) {
        return elem < arg;
    });
    // for_each(numbers.begin(), numbers.end(),
        // [arg, &cnt](int elem) { if (elem < arg) cnt++; });
    cout << "Liczba mniejszych od argumentu = " << cnt << endl;



}