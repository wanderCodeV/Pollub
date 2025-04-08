#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
struct Tstudent
{
    int points;
    string name;
    string surname;
};

void print_array(Tstudent* tab, int n)
{
    for(int i = 0; i < n; i++)
        cout << tab[i].name << " " << tab[i].surname << " " << tab[i].points << endl;
}
void read_from_file(int &n, Tstudent* &arr)
{
    ifstream file;
    file.open("studenci.csv");
    if(!file.is_open())
        cout << "bad";
    file >> n;
    cout << "Readed: " << n << endl;
    arr = new Tstudent[n];
    char bin;
    file >> bin;
    file >> bin;
    string point, line;
    for(int i = 0; i < n; i++)
    {
        file >> line;
        stringstream ss(line);
        getline(ss, arr[i].name, ';');
        getline(ss, arr[i].surname, ';');
        getline(ss, point, ';');
        arr[i].points = atoi(point.c_str());
    }
    file.close();
}
int linear_search(Tstudent* &tab, int n, int search)
{
    bool find = false;
    for(int i = 0 ; i < n; i++)
    {
        if(tab[i].points == search)
        {
            cout << tab[i].name << " " << tab[i].surname << endl;
            find = true;
        }
    }
    if(!find) cout << "No students with " << search << "points" << endl;
}

int binary_search(Tstudent* &tab, int search, int left, int right)
{
    if (left > right)
        return -1;
    int mid = (int) (left+right)/2;

    if(tab[mid].points == search)
        return mid;
    else if(tab[mid].points > search)
        return binary_search(tab, search, left, mid - 1);
    else
        return binary_search(tab, search, mid+1, right);

}

void print_binary_result(Tstudent* &arr, int n, int search)
{
    int id_mid_search = binary_search(arr, search, 0, n-1);
    if(id_mid_search == -1)
        cout << "No students with " << search << "points" << endl;
    else
    {
        ofstream file;
        file.open("wyniki.csv");

        for (int i = id_mid_search; i < n && arr[i].points == search; i++)
            file << arr[i].name << ';' << arr[i].surname << ";" << arr[i].points << endl;
        for (int i = id_mid_search - 1; i >= 0 && arr[i].points == search; i--)
            file << arr[i].name << ';' << arr[i].surname << ";" << arr[i].points << endl;
        file.close();
    }
}
bool cmp(Tstudent a, Tstudent b)
{
    return a.points < b.points;
}
int main()
{
    int n = 0;
    Tstudent* arr;
    read_from_file( n, arr);
    cout << "1) Linear search\n2) Binary search\n3) Exit\nEnter option: ";
    int option = 0;
    cin >> option;
    while(option != 3)
    {
        int search;
        cout << "Enter points: ";
        cin >> search;
        if(option == 1)
        {
            cout << "Students with " << search << " points: " << endl;
            linear_search(arr, n, search);
            break;
        }
        else if(option == 2)
        {
            sort(arr, arr+n, cmp);
            print_binary_result(arr, n, search);
            break;
        }
        else cout << "error!" << endl;
        cout << "1) Linear search\n2) Binary search\n3) Exit\nEnter option: ";
        cin >> option;
    }

    return 0;
}
