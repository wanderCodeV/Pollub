#include <iostream>
#include <cstdlib>  
#include <ctime> 

using namespace std;

struct ElemList
{
    ElemList* next;
    int data;
    ElemList(int elem)
    {
        next = nullptr;
        data = elem;
    }
};

struct SingleList
{
    ElemList* head;
    ElemList* tail;
    int cnt;
    SingleList()
    {
        head = tail = nullptr;
        cnt = 0;
    }
};

bool isEmpty(SingleList myLista)
{
    return myLista.head == nullptr;
}


void add_to_back(SingleList& myLista, int elem)
{
    ElemList* newElem = new ElemList(elem);
    if(isEmpty(myLista))
    {
        myLista.head = myLista.tail = newElem;
    }
    else
    {
        myLista.tail->next = newElem;
        myLista.tail = newElem;
    }
    myLista.cnt++;
}
void add_to_front(SingleList& myLista, int elem)
{
    ElemList* newElem = new ElemList(elem);
    if(isEmpty(myLista))
    {
        myLista.head = myLista.tail = newElem;
    }
    else
    {
        newElem->next = myLista.head;
        myLista.head = newElem;
    }
    myLista.cnt++;
}
void add_to_position(SingleList& myLista, int elem, int pos)
{
    if (pos < 1 || pos > myLista.cnt + 1)
        cout << "Bledna pozycja\n";
    else if (pos == 1)
        add_to_front(myLista, elem);
    else if (pos == myLista.cnt + 1) 
        add_to_back(myLista, elem);
    else 
    {
        pos--;
        ElemList* newElem = new ElemList(elem);
        ElemList* current = myLista.head;
        for (int i = 1; i < pos; i++)
            current = current->next;
        newElem->next = current->next;
        current->next = newElem;
        myLista.cnt++;
    }
}

void remove_from_back(SingleList& myLista) 
{
    if (isEmpty(myLista)) 
        cout << "Lista jest pusta.\n";
    else if (myLista.head == myLista.tail)
    {
        delete myLista.head;
        myLista.head = myLista.tail = nullptr;
    } 
    else 
    {
        ElemList* current = myLista.head;
        while (current->next != myLista.tail) 
            current = current->next;
        delete myLista.tail;
        current->next = nullptr;
        myLista.tail = current;
    }
    myLista.cnt--;
}

void remove_from_front(SingleList& myLista) 
{
    if (isEmpty(myLista)) {
        cout << "Lista jest pusta.\n";
        return;
    }
    ElemList* temp = myLista.head;
    myLista.head = myLista.head->next;
    delete temp;
    if (myLista.head == nullptr) 
        myLista.tail = nullptr;
    myLista.cnt--;
}
void show_list(SingleList& myLista) 
{
    if(isEmpty(myLista))
        cout << "Lista pusta\n";
    else
    {
        ElemList* current = myLista.head;
        cout << "Zawartość listy: ";
        while (current != nullptr) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
    
}

void remove_at_position(SingleList& myLista, int pos) {
    if(isEmpty(myLista))
        cout << "Lista pusta\n";
    else if (pos < 1 || pos > myLista.cnt + 1)
        cout << "Bledna pozycja\n";
    else if (pos == 1) 
    {
        remove_from_front(myLista);
    }
    else if (pos == myLista.cnt) 
        remove_from_back(myLista);
    else
    {
        pos--;
        ElemList* current = myLista.head;
        for (int i = 1; i < pos; i++) 
            current = current->next;
        ElemList* toDelete = current->next;
        current->next = toDelete->next;
        if (toDelete == myLista.tail)
            myLista.tail = current;
        delete toDelete;
        myLista.cnt--;
    }
}

void get_first(SingleList& myLista) 
{
    if (!isEmpty(myLista)) 
        cout << "Pierwszy element: " << myLista.head->data << endl;
    else 
        cout << "Lista jest pusta.\n";
}

void get_last(SingleList& myLista) {
    if (!isEmpty(myLista))
        cout << "Ostatni element: " << myLista.tail->data << endl;
    else 
        cout << "Lista jest pusta.\n";
}

void average(SingleList& myLista) {
    if (isEmpty(myLista)) {
        cout << "Lista jest pusta.\n";
    }
    else
    {
        int sum = 0;
        ElemList* current = myLista.head;
        while (current) 
        {
            sum += current->data;
            current = current->next;
        }
        cout << "Średnia arytmetyczna: " << (double)sum / myLista.cnt << endl;
    }
    
}

void find_max(SingleList& myLista) {
    if (isEmpty(myLista)) 
        cout << "Lista jest pusta.\n";
    else
    {
        int maxVal = myLista.head->data;
        int maxPos = 0;
        int i = 0;
        ElemList* current = myLista.head;
        while (current) 
        {
            if (current->data > maxVal) 
            {
                maxVal = current->data;
                maxPos = i;
            }
            current = current->next;
            i++;
        }
        cout << "Maksymalna wartość: " << maxVal << ", na pozycji: " << maxPos << endl;
    }
    
}

void clear_list(SingleList& myLista) 
{
    while (!isEmpty(myLista)) 
        remove_from_front(myLista);
    cout << "Lista została wyczyszczona.\n";
}


int main() {
    srand(time(NULL));
    SingleList myList;
    int choice;

    cout << "\n--- MENU ---\n";
    cout << "1. Sprawdz, czy lista jest pusta\n";
    cout << "2. Dodaj element na koniec listy\n";
    cout << "3. Dodaj element na poczatek listy\n";
    cout << "4. Dodaj element na okresloną pozycje\n";
    cout << "5. Usun element z konca listy\n";
    cout << "6. Usun element z poczatku listy\n";
    cout << "7. Usun element z okreslonej pozycji\n";
    cout << "8. Pobierz pierwszy element\n";
    cout << "9. Pobierz ostatni element\n";
    cout << "10. Oblicz srednia arytmetyczną\n";
    cout << "11. Znajdz maksymalny element\n";
    cout << "12. Wyswietl cala liste\n";
    cout << "13. Usun cala liste\n";
    cout << "14. Wyjscie z programu\n";
    do { 
        cout << "Podaj opcje: ";     
        cin >> choice;
        switch (choice) {
            case 1:
            {
                if(isEmpty(myList))
                    cout << "Lista jest pusta." << endl;
                else
                    cout << "Lista nie jest pusta." << endl;
                break;
            }
                
            case 2: {
                int num = rand() % 50 + 1;
                add_to_back(myList, num);
                break;
            }
            case 3: {
                int num = rand() % 50 + 1;
                add_to_front(myList, num);
                break;
            }
            case 4: {
                int num = rand() % 50 + 1;
                int pos;
                cout << "Podaj pozycję (1 - " << myList.cnt + 1 << "): ";
                cin >> pos;
                add_to_position(myList, num, pos);
                break;
            }
            case 5:
                remove_from_back(myList);
                break;
            case 6:
                remove_from_front(myList);
                break;
            case 7: 
            {
                int pos;
                cout << "Podaj pozycję (1 - " << myList.cnt << "): ";
                cin >> pos;
                remove_at_position(myList, pos);
                break;
            }
            case 8:
                get_first(myList);
                break;
            case 9:
                get_last(myList);
                break;
            case 10:
                average(myList);
                break;
            case 11:
                find_max(myList);
                break;
            case 12:
                show_list(myList);
                break;
            case 13:
                clear_list(myList);
                break;
            case 14:
                cout << "Koniec programu.\n";
                break;
            default:
                cout << "Nieprawidłowa opcja.\n";
        }

    } while (choice != 14);
                                          
    return 0;
}