#include <iostream>
#include <cstdlib> 
#include <fstream>
using namespace std;

struct stack_elem
{
    char data;
    stack_elem* next;
};

void push(stack_elem* &stack, char elem)
{
    stack_elem* new_el = new stack_elem();
    new_el->data = elem;
    new_el->next = stack;
    stack = new_el;
}

bool isEmpty(stack_elem* stack)
{ 
    return stack == nullptr;
}

void pop(stack_elem* &stack)
{
    if(!isEmpty(stack))
    {
        stack_elem* temp = stack;
        stack = stack->next;
        delete temp;
    }
    else
        cout << "Stos jest pusty, nie mozemy usunac\n";
}

char top(stack_elem* stack)
{
    char elem='a';
    if(!isEmpty(stack))
        elem = stack->data;     
    return elem;
    
}

void reverse_text()
{
    ifstream file("znaki1.txt");
    stack_elem* text = nullptr;
    char temp;
    
    while(file.get(temp))
    {
        push(text, temp);
    }
    file.close();
    
    ofstream file_out("wynik.txt");
    
    while(!isEmpty(text))
    {
        file_out << top(text);
        pop(text);
    }
    file_out.close();
}


int main()
{
    srand(0);
    stack_elem* stack = nullptr;
    int option;
    while(option != 6)
    {
        cout << "Podaj opcje: ";
        cin >> option;
        switch(option)
        {
            case 1:
            {
                if(isEmpty(stack))
                    cout << "Stos jest pusty" << endl;
                else
                    cout << "Stos nie jest pusty" << endl;
                break;
            }
            case 2:
            {
            
                char letter = 'a' + rand() % 29;
                push(stack, letter);
                break;
            }
            case 3:
            {
                pop(stack);
                break;
            }
            case 4:
            {
                if(!isEmpty(stack))
                    cout << "Ostatni element: " << top(stack) << endl;
                else
                {
                    cout << "Stos jest pusty, nie mozemy zwrocic ostatni element";
                }    
                break;
            }
            case 5:
            {
                while(!isEmpty(stack))
                    pop(stack);
                break;
            }
        }
    }
    reverse_text();
    
}