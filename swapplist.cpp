#include<iostream>
using namespace std;
struct node
{
    int value;
    struct node*next;
};
struct node*insert(struct node*head,int data)
{
        if(head == NULL)
        {
            head = new node;
            head->value = data;
            head->next = NULL;
        }
        else
        {
            struct node*tmp = new node;
            tmp->value = data;
            struct node*p = head;
            while(p!=NULL)
            {
                if(p->next == NULL)
                {
                    p->next = tmp;
                    tmp->next = NULL;
                }
                p = p->next;
            }
        }
        return head;
}
int counts(struct node*head)
{
    int c=0;
    struct node*tmp = head;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
        c++;
    }
    return c;
}
void halflist(struct node*head,int c)
{
    struct node*p1 = head;
    struct node*p2 = head;
    int i =0;
    //int j = c;
    while(p2!=NULL)
    {
       if(i < c/2)
       {
           p2 = p2->next;
       }
       else
       {
           cout << p2->value << " ";
            p2 = p2->next;
       }
       i++;
    }
    i=0;
    while(p1!=NULL)
    {
       if(i < c/2)
       {
           cout << p1->value << " ";
           p1 = p1->next;
       }
       else
       {
           p1 = p1->next;
       }
        i++;
    }
    cout << endl;
}
int main()
{
    struct node*head = NULL;
    while(1)
    {
        cout << "1. insert:"<<endl;
        cout << "2. swaplist:" << endl;
        int c;
        cin >> c;
        switch(c)
        {
            case 1:
                cout << "insert:";
                int i;
                while(1)
                {
                    if(i == -99)
                    {
                        break;
                    }
                    else
                    {
                        cin >> i;
                        head = insert(head,i);
                    }
                }
            break;
            case 2:
                halflist(head,counts(head));
            break;
        }
    }
}
