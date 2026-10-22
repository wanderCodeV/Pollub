#include <algorithm>
#include <iostream>

template <typename T>
class Array {
private:
    T* arr;
    int max_size;
    int id_first_free;
public:
    Array() {
        arr = nullptr;
        max_size = 0;
        id_first_free = 0;
    }
    Array(int size) {
        max_size = size;
        arr = new T[max_size];
        id_first_free = 0;
    }
    ~Array() {
        delete[] arr;
    }
    void sort_asc() {
        if (id_first_free > 1) {
            std::sort(arr, arr + id_first_free);
        }
    }
    T max_element() {
        if (id_first_free != 0) {
            T max = arr[0];
            for (int i = 1; i < id_first_free; i++) {
                if (arr[i] > max) {
                    max = arr[i];
                }
            }
            return max;
        }
        else std::cout << "Err: Tablica pusta\n";
    }
    void show() {
        for (int i = 0; i < id_first_free; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
    void add_element(T element) {
        if (id_first_free < max_size) {
            arr[id_first_free] = element;
            id_first_free++;
        }
        else
            std::cout << "Err: Tablica jest pelna\n ";
    }
    T get_element(int id) {
        if (id < 0 || id >= id_first_free) {
            std::cout << "Err: Nie ma takiego elementu\n";
        }
        else
            return arr[id];
    }
    void show_type() {
        std::cout << "Typ: " << typeid(T).name() << "\n";
    }

};

bool cmp(std::string a, std::string b) {
    return a.size() < b.size();
}

template <>
class Array<std::string> {
private:
    std::string* arr;
    int max_size;
    int id_first_free;
public:
    Array() {
        arr = nullptr;
        max_size = 0;
        id_first_free = 0;
    }
    Array(int size) {
        max_size = size;
        arr = new std::string[max_size];
        id_first_free = 0;
    }
    ~Array() {
        delete[] arr;
    }
    void sort_asc() {
        if (id_first_free > 1) {
            std::sort(arr, arr + id_first_free, cmp);
        }
    }
    int max_element() {
        if (id_first_free != 0) {
            int max = arr[0].size();
            for (int i = 1; i < id_first_free; i++) {
                if (arr[i].size() > max) {
                    max = arr[i].size();
                }
            }
            return max;
        }
        else std::cout << "Err: Tablica pusta\n";
    }
    void show() {
        for (int i = 0; i < id_first_free; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
    void add_element(std::string element) {
        if (id_first_free < max_size) {
            arr[id_first_free] = element;
            id_first_free++;
        }
        else
            std::cout << "Err: Tablica jest pelna\n ";
    }
    std::string get_element(int id) {
        if (id < 0 || id >= id_first_free) {
            std::cout << "Err: Nie ma takiego elementu\n";
        }
        else
            return arr[id] ;
    }
    void show_type() {
        std::cout << "Typ: string"  << "\n";
    }

};

int main() {

    //int
    Array<int> tab(5);
    tab.show_type();
    tab.add_element(10);
    tab.add_element(3);
    tab.add_element(7);
    std::cout << "Przed sortowaniem: ";
    tab.show();
    tab.sort_asc();
    std::cout << "Po sortowaniu: ";
    tab.show();
    std::cout << "Max element: " << tab.max_element() << "\n";
    std::cout << "Element pod indeksem 1: " << tab.get_element(1) << "\n";

    //string
    Array<std::string> tabStr(5);
    tabStr.add_element("Kot");
    tabStr.add_element("Pies");
    tabStr.add_element("Szarik");
    tabStr.add_element("Tuzik");
    std::cout << "Przed sortowaniem: ";
    tabStr.show();
    tabStr.sort_asc();
    std::cout << "Po sortowaniu: ";
    tabStr.show();
    std::cout << "Dlugosc najdluzszego napisu: " << tabStr.max_element() << "\n";
    return 0;
}