#include <iostream>
#include <list>
#include <random>
#include <algorithm>

using namespace std;

class Drukuj {
private:
    int elem;
public:
    Drukuj(int el) {
        elem = el;
    }
    void operator()(int elem) {
        cout << elem << " ";
    }
};
int main()
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, 20);
    uniform_int_distribution<int> dist2(-100, 100);

    int n = dist(mt);
    list<int> elements;

    for(int i = 0; i < n; ++i)
    {
        int val = dist2(mt);
        if(val >= 0)
            elements.push_front(val);
        else
            elements.push_back(val);
    }

    for(list<int>::iterator it = elements.begin(); it != elements.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // for_each(elements.begin(), elements.end(), [](int el) { cout << el << " "; });
    for_each(elements.begin(), elements.end(), Drukuj());
    cout << endl;

    for(auto el : elements)
        cout << el << " ";
    cout << endl;

    return 0;
}