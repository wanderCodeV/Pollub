#include <iostream>
#include <cstdlib> 
#include <fstream>
#include <ctime>
using namespace std;

struct queue_elem
{
    char data;
    queue_elem* next;
};

struct queue
{
    queue_elem* head;
    queue_elem* tail;
    queue()
    {
        head = tail = nullptr;
    }
};

void push(queue &q, char value)
{
    queue_elem* new_el = new queue_elem();
    new_el->data = value;
    new_el->next = nullptr;
    if(q.tail != nullptr)
        q.tail->next = new_el;
    else
        q.head = new_el;
    q.tail = new_el;
}

bool isEmpty(queue q)
{ 
    return q.head == nullptr;
}

void pop(queue &q)
{
    if(!isEmpty(q))
    {
        queue_elem* temp = q.head;
        q.head = q.head->next;
        delete temp;
        if(q.head == nullptr)
            q.tail = nullptr;
    }
    else
        cout << "Kolejka jest pusta, nie mozemy usunac\n";
}

char first(queue q)
{
    char ans ='a';
    if(!isEmpty(q))
        ans = q.head->data;     
    return ans;
    
}


int main()
{
    srand(time(nullptr));
    queue q;
    int option;
    while(option != 7)
    {
        cout << "Podaj opcje: ";
        cin >> option;
        switch(option)
        {
            case 1:
            {
                if(isEmpty(q))
                    cout << "Kolejka jest pusta" << endl;
                else
                    cout << "Kolejka nie jest pusta" << endl;
                break;
            }
            case 2:
            {
                char letter = 'a' + rand() % 26;
                push(q, letter);
                break;
            }
            case 3:
            {
                pop(q);
                break;
            }
            case 4:
            {
                if(!isEmpty(q))
                    cout << "Pierwszy element: " << first(q) << endl;
                else
                {
                    cout << "Kolejka jest pusta, nie mozemy zwrocic ostatni element" << endl;
                }    
                break;
            }
            case 5:
            {
                while(!isEmpty(q))
                {
                    cout <<  first(q) << endl;
                    pop(q);
                }
                break;
            }
            case 6:
            {
                ifstream file("znaki2.txt");
                char temp;
                
                while(file.get(temp))
                {
                    if(temp >= 'A' && temp <= 'Z')
                        push(q, temp);
                }
                file.close();
                break;
            }
        }
    }
    
    
}