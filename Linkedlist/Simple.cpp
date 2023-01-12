#include <iostream>

using namespace std;

typedef struct Node
{
    int data;
    struct Node *pNext;
} Node;

class Linkedlist
{
private:
    Node *pHead, *pTall;
    int soluong;

public:
    Linkedlist()
    {
        pHead = NULL;
        pTall = NULL;
        soluong = 0;
    }

    ~Linkedlist()
    {
        for (Node *i = pHead; i != NULL; i = pHead)
        {
            pHead = i->pNext;
            delete i;
        }
        soluong = 0;
        cout << "Bo nho da duoc giai phong!";
    }

    void append(int x)
    {
        Node *p = new Node;
        p->data = x;
        p->pNext = NULL;
        if (pHead == NULL)
            pHead = pTall = p;
        else
        {
            pTall->pNext = p;
            pTall = p;
        }
        soluong += 1;
    }

    void insert(int x, int vitri = 1)
    {
        if (vitri == soluong + 1)
        {
            append(x);
            return;
        }
        else if (vitri == 1)
        {
            Node *p = new Node;
            p->data = x;
            p->pNext = NULL;
            if(pHead == NULL)
                pHead = pTall = p;
            else
            {
                p->pNext = pHead;
                pHead = p;
            }
        }
        else if (vitri > soluong + 1 || vitri <= 0)
        {
            cout << "\nerror: invalid argument\n";
            return;
        }
        else
        {
            Node *p = new Node;
            Node *temp = new Node;
            p->data = x;
            p->pNext = NULL;
            int dem = 1;
            for (Node *i = pHead; i != NULL; i = i->pNext)
            {
                if (dem == vitri)
                {
                    p->pNext = i;
                    temp->pNext = p;
                    break;
                }
                else
                {
                    dem += 1;
                    temp = i;
                }
            }
        }
        soluong += 1;
    }

    void pop(int vitri = 1)
    {
        if (vitri == 1)
        {
            Node *temp = new Node;
            temp = pHead;
            pHead = pHead->pNext;
            delete temp;
        }
        else if (vitri == soluong)
        {
            for(Node *i = pHead; i != NULL; i = i->pNext)
            {
                if (i->pNext == pTall)
                {
                    delete pTall;
                    i->pNext = NULL;
                    pTall = i;
                    break;
                }
            }
        }
        else if (vitri >= soluong + 1 || vitri <= 0)
        {
            cout << "\nerror: invalid argument\n";
            return;
        }
        else
        {
            Node *temp = new Node;
            int dem = 1;
            for(Node *i = pHead; i!=NULL ; i = i->pNext)
            {
                if (dem == vitri)
                {
                    temp->pNext = i->pNext;
                    delete i;
                    break;
                }
                else{
                    dem += 1;
                    temp = i;
                }
            }
        }
        soluong -= 1;
    }

    void remove(int x)
    {
        Node *temp = new Node;
        if (x == pHead->data)
        {
            temp = pHead;
            pHead = pHead->pNext;
            delete temp;
        }
        else if (x == pTall->data)
        {
            for (Node *i = pHead; i != NULL ; i = i->pNext)
            {
                if (i->pNext == pTall)
                {
                    delete pTall;
                    i->pNext = NULL;
                    pTall = i;
                    break;
                }
            }
        }
        else
        {
            for(Node *i = pHead ; i != NULL; i = i->pNext)
            {
                if (x==i->data)
                {
                    temp->pNext = i->pNext;
                    delete i;
                    break;
                }
                else
                    temp = i;
                
            }
        }
        soluong -= 1;
    }

    void print()
    {
        for (Node *i = pHead; i != NULL; i = i->pNext)
        {
            cout << i->data << "  ";
        }
        cout << "\n";
        system("pause");
    }
    
    int index() { return soluong; }
};

int main()
{
    Linkedlist a;
    while (69)
    {
        system("cls");
        cout << "\n\n\t\t\t====MENU====\n\n";
        cout << "\t1.Append.\n";
        cout << "\t2.insert.\n";
        cout << "\t3.Pop.\n";
        cout << "\t4.remove.\n";
        cout << "\t5.Print.\n";
        cout << "\t0.Ket Thuc.\n";
        cout << "\n\t\t\t=====END=====\n";
        int luachon;
        cout << "\nNhap Lua Chon: ";
        cin >> luachon;
        if (luachon == 1)
        {
            int n;
            cout<<"Phan tu muon them: ";cin>>n;
            a.append(n);
        }
        else if (luachon == 2)
        {
            int n,vt;
            cout<<"Phan tu muon chen: ";cin>>n;
            cout<<"Vi tri muon chen: ";cin>>vt;
            a.insert(n,vt);
        }
        else if (luachon == 3)
        {
            int vt;
            cout<<"Vi tri muon xoa: ";cin>>vt;
            a.pop(vt);
        }
        else if (luachon == 4)
        {
            int n,vt;
            cout<<"Phan tu muon xoa: ";cin>>n;
            a.remove(n);
        }
        else if (luachon == 5)
            a.print();
        else
            break;
    }
    return 0;
}