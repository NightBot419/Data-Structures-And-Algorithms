#include <iostream>

using namespace std;

typedef struct Node{
    int data;
    struct Node *pNext;
    struct Node *pPrev;
}Node;

class Linkedlist{
    private:
        Node *pHead,*pTall;
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
            for(Node *i = pHead; i != NULL ; i = pHead)
            {
                pHead = i->pNext;
                delete i;
            }
        }
        int index(){ return soluong; }
        void print()
        {
            cout<<"\n";
            for(Node *i = pHead; i != NULL; i = i->pNext)
                cout<<i->data<<"  ";
            system("pause");
        }
        void print2()
        {
            cout<<"\n";
            for(Node *i = pTall; i != NULL; i = i->pPrev)
                cout<<i->data<<"  ";
            system("pause");
        }
        void append(int data)
        {
            Node *p = new Node;
            p->data = data;
            p->pNext = p->pPrev = NULL;
            if(pHead == NULL)
                pHead = pTall = p;
            else
            {
                pTall->pNext = p;
                p->pPrev = pTall;
                pTall = p;
            }
            soluong += 1;
        }
        void insert(int data,int vt = 1)
        {
            if (vt == soluong + 1)
                append(data);
            else if (vt > soluong + 1 || vt <= 0)
                cout<<"\nError: invalid argument.\n";
            else if (vt == 1)
            {
                Node *p = new Node;
                p->data = data;
                p->pPrev = NULL;
                p->pNext = pHead;
                pHead->pPrev = p;
                pHead = p;
                soluong += 1;
            }
            else
            {
                Node *p = new Node;
                p->data = data;
                int dem = 1;
                for(Node *i = pHead; i != NULL ; i = i->pNext)
                {
                    if (vt == dem)
                    {
                        p->pNext = i;
                        p->pPrev = i->pPrev;
                        i->pPrev->pNext = p; 
                        i->pPrev = p;
                        soluong += 1;
                        return;
                    }
                    else
                        dem += 1;
                } 
            }
        }
        void pop(int vt = 1)
        {
            if (vt == 1)
            {
                pHead = pHead->pNext;
                delete pHead->pPrev;
                pHead->pPrev = NULL;
                soluong -= 1;
            }
            else if (vt == soluong)
            {
                pTall = pTall->pPrev;
                delete pTall->pNext;
                pTall->pNext = NULL;
                soluong -= 1;

            }
            else if (vt <= 0 || vt > soluong)
                cout<<"\nError: invalid argument.\n";
            else
            {
                int dem = 1;
                for(Node *i = pHead; i != NULL; i = i->pNext)
                {
                    if (vt == dem)
                    {
                        i->pPrev->pNext = i->pNext;
                        i->pNext->pPrev = i->pPrev;
                        delete i;
                        soluong -= 1;
                        return;
                    }
                    else
                        dem += 1;
                }                
            }
        }
        void remove(int data)
        {
            if (data == pHead->data)
                pop();
            else if (data == pTall->data)
                pop(soluong);
            else
            {
                for(Node *i = pHead; i != NULL; i = i->pNext)
                {
                    if (data == i->data)
                    {
                        i->pPrev->pNext = i->pNext;
                        i->pNext->pPrev = i->pPrev;
                        delete i;
                        soluong -= 1;
                        return;
                    }
                }
            }
        }
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