#include<iostream>
using namespace std;

struct Node
{
    int info;
    Node *next;
} *start1, *start2, *newptr, *ptr, *save;

Node *Create_New_Node(int inf)
{
    ptr = new Node;
    ptr->info = inf;
    ptr->next = NULL;
    return ptr;
}

Node* Insert_End(Node *np, Node *start)
{
    if (start == NULL)
        start = np;
    else
    {
        save = start;
        while (save->next != NULL)
        {
            save = save->next;
        }
        save->next = np;
    }
    return start;
}

void Display(Node *np)
{
    while (np != NULL)
    {
        cout << np->info << " -> ";
        np = np->next;
    }
    cout << "!!!\n";
}

void Merge(Node *first, Node *second)
{
    while(first->next != NULL)
    {
        first = first->next;
    }
    first->next = second;
}

int main()
{
    start1 = NULL;
    start2 = NULL;
    int inf, c = 1;
    char ch = 'y';
    while (ch == 'y' || ch == 'Y')
    {
        system("cls");
        cout << "\nEnter 1 to add value or 2 to insert in respective list or 3 to merge the two list\n";
        cin >> c;
        if (c == 1)
        {
            cout << "\nEnter Information for the new node...";
            cin >> inf;
            cout << "\nCreating New Node!!";
            newptr = Create_New_Node(inf);
            if (newptr != NULL)
            {
                cout << "\n\nNew Node Created Successfully.\n";
            }
            else
            {
                cout << "\nCannot create New Node!!! Aborting!!\n";
                exit(0);
            }
            cout << "\n\nNow Inserting this Node in the beginning of the list///\n";
            start1 = Insert_End(newptr, start1);
            cout << "\nNow the list is: \n";
            Display(start1);
        }
        else if (c == 2)
        {
            cout << "\nEnter Information for the new node...";
            cin >> inf;
            cout << "\nCreating New Node!!";
            newptr = Create_New_Node(inf);
            if (newptr != NULL)
            {
                cout << "\n\nNew Node Created Successfully.\n";
            }
            else
            {
                cout << "\nCannot create New Node!!! Aborting!!\n";
                exit(0);
            }
            cout << "\n\nNow Inserting this Node in the beginning of the list///\n";
            start2 = Insert_End(newptr, start2);
            cout << "\nNow the list is: \n";
            Display(start2);
        }
        else if(c == 3)
        {
            Merge(start1, start2);  
            Display(start1);
        }
        cout << "\nPress Y to continue, N to exit...\n";
        cin >> ch;
    }
}