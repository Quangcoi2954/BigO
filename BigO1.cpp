#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void CreatLinklist(Node *&t)
{
    t = NULL;
}

void AddNode(Node *&t, int x)
{
    Node *p = new Node;
    p->data = x;
    p->next = NULL;

    if (t == NULL)
    {
        t = p;
    }
    else
    {
        Node *temp = t;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void Travel(Node *t)
{
    Node *p = t;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

bool Search(Node *t, int x)
{
    Node *p = t;
    while (p != NULL)
    {
        if (p->data == x)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

int generateRandomNumber(int min, int max)
{
    // Sinh số ngẫu nhiên trong phạm vi và trả về
    return min + rand() % (max - min + 1);
}

int main()
{
    Node *Linklist = NULL;

    int n;
    cin >> n;

    int minRange = 1; // Phạm vi nhỏ nhất
    int maxRange = 10000; // Phạm vi lớn nhất

    // Thiết lập seed cho hàm sinh số ngẫu nhiên
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        int randomNumber = generateRandomNumber(minRange, maxRange);
        AddNode(Linklist, randomNumber);
    }

    Travel(Linklist);
    cout << endl;

    int x;
    cout << "Nhap so can tim: ";
    cin >> x;
    cout << endl;

    if (Search(Linklist, x))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    return 0;
}
