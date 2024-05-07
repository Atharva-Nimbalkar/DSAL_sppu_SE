
#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

struct node
{
    char Title[10];
    int chapter_count;
    struct node *child[10];
} *root;

class Book
{
public:
    void create_tree();
    void display(node *r1);

    Book()
    {
        root = NULL;
    }
};

void Book::create_tree()
{
    int tbooks, tchapters, i, j, k;
    root = new node;
    cout << "Enter name of book :";
    cin >> root->Title;

    cout << "Enter no. of chapters in book :";
    cin >> tchapters;

    root->chapter_count = tchapters;
    for (i = 0; i < tchapters; i++)
    {
        root->child[i] = new node;
        cout << "Enter Chapter name :\n";
        cin >> root->child[i]->Title;

        cout << "Enter no. of sections in  Chapter :" << root->child[i]->Title;
        cin >> root->child[i]->chapter_count;

        for (j = 0; j < root->child[i]->chapter_count; j++)
        {
            root->child[i]->child[j] = new node;
            cout << "Enter Section " << j + 1 << "name\n";
            cin >> root->child[i]->child[j]->Title;
        }
    }
}

void Book::display(node *r1)
{
    int i, j, k, tchapters;
    if (r1 != NULL)
    {
        cout << "\n-----Book Hierarchy---";

        cout << "\n Book title : " << r1->Title;
        tchapters = r1->chapter_count;
        for (i = 0; i < tchapters; i++)
        {

            cout << "\n Chapter " << i + 1;
            cout << " " << r1->child[i]->Title;
            cout << "\n Chapter's Sections";
            for (j = 0; j < r1->child[i]->chapter_count; j++)
            {
                cout << "\n  " << r1->child[i]->child[j]->Title;
            }
        }
    }
}

int main()
{
    int choice;
    Book obj;
    while (1)
    {
        cout << "\n-----------------" << endl;
        cout << "Book Tree Creation" << endl;
        cout << "-----------------" << endl;
        cout << "1.Create" << endl;
        cout << "2.Display" << endl;
        cout << "3.Quit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.create_tree();
        case 2:
            obj.display(root);
            break;
        case 3:
            exit(1);
        default:
            cout << "Wrong choice" << endl;
        }
    }
}