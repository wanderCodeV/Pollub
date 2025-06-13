#include <iostream>
using namespace std;

struct node
{
    int key;
    node* parent;
    node* left;
    node* right;
};

bool isEmpty(node* &tree)
{
    return tree == nullptr;
}

node* make_node(int value)
{
    node* tmp = new node();
    tmp->key = value;
    tmp->left = tmp->right = tmp->parent = nullptr;
    return tmp;
}

node* search(node* root, int value)
{
    while (root != nullptr && root->key != value)
    {
        if (value < root->key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return root;
}

void inorder(node* root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void preorder(node* root)
{
    if (root)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}

void add_node(node* &root, int value)
{
    node* newNode = make_node(value);

    if (isEmpty(root))
    {
        root = newNode;
    }
    else
    {
        node* tmp = root;
        node* parent = nullptr;

        while (tmp != nullptr)
        {
            parent = tmp;
            if (value < tmp->key)
            {
                tmp = tmp->left;
            }
            else
            {
                tmp = tmp->right;
            }
        }

        newNode->parent = parent;

        if (value < parent->key)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }
    }
}

node* minimum(node* root)
{
    while (root && root->left)
    {
        root = root->left;
    }
    return root;
}

void transplant(node* &root, node* u, node* v)
{
    if (u->parent == nullptr)
    {
        root = v;
    }
    else if (u == u->parent->left)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }

    if (v != nullptr)
    {
        v->parent = u->parent;
    }
}

void delete_node(node* &root, int value)
{
    node* target = search(root, value);
    if (!target)
    {
        return;
    }

    if (target->left == nullptr)
    {
        transplant(root, target, target->right);
    }
    else if (target->right == nullptr)
    {
        transplant(root, target, target->left);
    }
    else
    {
        node* succ = minimum(target->right);
        if (succ->parent != target)
        {
            transplant(root, succ, succ->right);
            succ->right = target->right;
            if (succ->right)
            {
                succ->right->parent = succ;
            }
        }
        transplant(root, target, succ);
        succ->left = target->left;
        if (succ->left)
        {
            succ->left->parent = succ;
        }
    }

    delete target;
}

void delete_tree(node* &root)
{
    if (root)
    {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
        root = nullptr;
    }
}

int main()
{
    node* root = nullptr;
    int option, value;

    cout << "\n--- MENU ---\n";
    cout << "1) Sprawdzenie czy drzewo jest puste\n";
    cout << "2) Dodanie nowego wezla do drzewa\n";
    cout     << "3) Sprawdzenie czy klucz znajduje sie w drzewie\n";
    cout << "4) Wyswietlenie drzewa – preorder\n";
    cout << "5) Wyswietleni6e drzewa – inorder\n";
    cout << "6) Wyswietlenie drzewa – postorder\n";
    cout << "7) Usuniecie wezla\n";
    cout << "8) Usuniecie calego drzewa\n";
    cout << "9) Wyjscie z programu\n";
    do
    {
        cout << "Twoj wybor: ";
        cin >> option;

        switch (option)
        {
            case 1:
                if (isEmpty(root))
                {
                    cout << "Drzewo jest puste.\n";
                }
                else
                {
                    cout << "Drzewo nie jest puste.\n";
                }
                break;

            case 2:
                cout << "Podaj wartosc klucza: ";
                cin >> value;

                cout << "Drzewo (inorder) przed dodaniem: ";
                inorder(root);
                cout << endl;

                if (search(root, value))
                {
                    cout << "Wezel o podanym kluczu juz istnieje.\n";
                }
                else
                {
                    add_node(root, value);
                    cout << "Dodano wezel.\n";
                }

                cout << "Drzewo (inorder) po dodaniu: ";
                inorder(root);
                cout << endl;
                break;

            case 3:
                cout << "Podaj wartosc klucza do wyszukania: ";
                cin >> value;
                if (search(root, value))
                {
                    cout << "Klucz znajduje sie w drzewie.\n";
                }
                else
                {
                    cout << "Klucz NIE znajduje sie w drzewie.\n";
                }
                break;

            case 4:
                cout << "Drzewo (preorder): ";
                preorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Drzewo (inorder): ";
                inorder(root);
                cout << endl;
                break;

            case 6:
                cout << "Drzewo (postorder): ";
                postorder(root);
                cout << endl;
                break;

            case 7:
                cout << "Podaj wartosc klucza do usuniecia: ";
                cin >> value;

                if (!search(root, value))
                {
                    cout << "Wezel o podanym kluczu nie istnieje.\n";
                }
                else
                {
                    cout << "Drzewo (inorder) przed usunieciem: ";
                    inorder(root);
                    cout << endl;

                    delete_node(root, value);

                    cout << "Usunieto wezel.\n";
                    cout << "Drzewo (inorder) po usunieciu: ";
                    inorder(root);
                    cout << endl;
                }
                break;

            case 8:
                delete_tree(root);
                cout << "Cale drzewo zostalo usuniete.\n";
                break;

            case 9:
                delete_tree(root);
                cout << "Zakonczono program.\n";
                break;

            default:
                cout << "Niepoprawna opcja.\n";
        }

    } while (option != 9);

    return 0;
}
