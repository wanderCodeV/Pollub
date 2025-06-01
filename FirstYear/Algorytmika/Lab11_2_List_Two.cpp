#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct ElemList {
    ElemList* next;
    ElemList* prev;
    int data;

    ElemList(int elem) {
        next = nullptr;
        prev = nullptr;
        data = elem;
    }
};

struct DoubleList {
    ElemList* head;
    ElemList* tail;
    int cnt;

    DoubleList() {
        head = tail = nullptr;
        cnt = 0;
    }
};

bool isEmpty(DoubleList myLista) {
    return myLista.head == nullptr;
}

void add_to_back(DoubleList& myLista, int elem) {
    ElemList* newElem = new ElemList(elem);
    if (isEmpty(myLista)) {
        myLista.head = myLista.tail = newElem;
    } else {
        newElem->prev = myLista.tail;
        myLista.tail->next = newElem;
        myLista.tail = newElem;
    }
    myLista.cnt++;
}

void add_to_front(DoubleList& myLista, int elem) {
    ElemList* newElem = new ElemList(elem);
    if (isEmpty(myLista)) {
        myLista.head = myLista.tail = newElem;
    } else {
        newElem->next = myLista.head;
        myLista.head->prev = newElem;
        myLista.head = newElem;
    }
    myLista.cnt++;
}

void add_to_position(DoubleList& myLista, int elem, int pos) {
    if (pos < 1 || pos > myLista.cnt + 1)
        cout << "Bledna pozycja\n";
    else if (pos == 1)
        add_to_front(myLista, elem);
    else if (pos == myLista.cnt + 1)
        add_to_back(myLista, elem);
    else {
        ElemList* newElem = new ElemList(elem);
        ElemList* current = myLista.head;
        for (int i = 1; i < pos - 1; i++)
            current = current->next;
        newElem->next = current->next;
        newElem->prev = current;
        current->next->prev = newElem;
        current->next = newElem;
        myLista.cnt++;
    }
}

void remove_from_back(DoubleList& myLista) {
    if (isEmpty(myLista))
        cout << "Lista jest pusta.\n";
    else if (myLista.head == myLista.tail) {
        delete myLista.head;
        myLista.head = myLista.tail = nullptr;
    } else {
        ElemList* toDelete = myLista.tail;
        myLista.tail = myLista.tail->prev;
        myLista.tail->next = nullptr;
        delete toDelete;
    }
    myLista.cnt--;
}

void remove_from_front(DoubleList& myLista) {
    if (isEmpty(myLista)) {
        cout << "Lista jest pusta.\n";
        return;
    }
    ElemList* temp = myLista.head;
    myLista.head = myLista.head->next;
    if (myLista.head)
        myLista.head->prev = nullptr;
    else
        myLista.tail = nullptr;
    delete temp;
    myLista.cnt--;
}

void remove_at_position(DoubleList& myLista, int pos) {
    if (isEmpty(myLista))
        cout << "Lista pusta\n";
    else if (pos < 1 || pos > myLista.cnt)
        cout << "Bledna pozycja\n";
    else if (pos == 1)
        remove_from_front(myLista);
    else if (pos == myLista.cnt)
        remove_from_back(myLista);
    else {
        ElemList* current = myLista.head;
        for (int i = 1; i < pos; i++)
            current = current->next;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        myLista.cnt--;
    }
}

void show_list_forward(DoubleList& myLista) {
    if (isEmpty(myLista))
        cout << "Lista pusta\n";
    else {
        ElemList* current = myLista.head;
        cout << "Lista od poczatku: ";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
}

void show_list_backward(DoubleList& myLista) {
    if (isEmpty(myLista))
        cout << "Lista pusta\n";
    else {
        ElemList* current = myLista.tail;
        cout << "Lista od konca: ";
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << "\n";
    }
}

void find_min(DoubleList& myLista) {
    if (isEmpty(myLista))
        cout << "Lista jest pusta.\n";
    else {
        int minVal = myLista.head->data;
        int minPos = 1;
        int i = 1;
        ElemList* current = myLista.head;
        while (current) {
            if (current->data < minVal) {
                minVal = current->data;
                minPos = i;
            }
            current = current->next;
            i++;
        }
        cout << "Minimalna wartosc: " << minVal << ", na pozycji: " << minPos << endl;
    }
}

void clear_list(DoubleList& myLista) {
    while (!isEmpty(myLista))
        remove_from_front(myLista);
    cout << "Lista zostala wyczyszczona.\n";
}

int main() {
    srand(time(NULL));
    DoubleList myList;
    int choice;

    cout << "\n--- MENU ---\n";
    cout << "1. Sprawdz, czy lista jest pusta\n";
    cout << "2. Dodaj element na koniec listy\n";
    cout << "3. Dodaj element na poczatek listy\n";
    cout << "4. Dodaj element na okreslona pozycje\n";
    cout << "5. Usun element z konca listy\n";
    cout << "6. Usun element z poczatku listy\n";
    cout << "7. Usun element z okreslonej pozycji\n";
    cout << "8. Wyswietl liste od poczatku\n";
    cout << "9. Wyswietl liste od konca\n";
    cout << "10. Znajdz minimalny element\n";
    cout << "11. Usun cala liste\n";
    cout << "12. Wyjscie\n";

    do {
        cout << "Podaj opcje: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << (isEmpty(myList) ? "Lista jest pusta.\n" : "Lista nie jest pusta.\n");
                break;
            case 2:
                add_to_back(myList, rand() % 50 + 1);
                break;
            case 3:
                add_to_front(myList, rand() % 50 + 1);
                break;
            case 4: {
                int pos;
                cout << "Podaj pozycje (1 - " << myList.cnt + 1 << "): ";
                cin >> pos;
                add_to_position(myList, rand() % 50 + 1, pos);
                break;
            }
            case 5:
                remove_from_back(myList);
                break;
            case 6:
                remove_from_front(myList);
                break;
            case 7: {
                int pos;
                cout << "Podaj pozycje (1 - " << myList.cnt << "): ";
                cin >> pos;
                remove_at_position(myList, pos);
                break;
            }
            case 8:
                show_list_forward(myList);
                break;
            case 9:
                show_list_backward(myList);
                break;
            case 10:
                find_min(myList);
                break;
            case 11:
                clear_list(myList);
                break;
            case 12:
                cout << "Koniec programu.\n";
                break;
            default:
                cout << "Nieprawidlowa opcja.\n";
        }
    } while (choice != 12);

    return 0;
}
