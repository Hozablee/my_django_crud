#include<iostream>
using namespace std;
struct node
{
    char value;
    struct node*next;
};
struct node*insert(struct node*head,char data)
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
void encode(struct node*head,struct node*head2,int sz)
{
    while(head != NULL && head2 != NULL)
    {
        if(sz%2==0)
        {
            cout << head->value;
        }
        head = head->next;
        sz--;
        if(sz%2 != 0)
        {
            cout << head2->value;
        }
        head2 = head2->next;
        sz--;
    }
    cout << endl;
}
int counts(struct node*head)
{
    int c = 0;
    struct node*tmp = head;
    while(tmp!=NULL)
    {
        c++;
        tmp = tmp->next;
    }
    return c;
}
void show(struct node*head)
{
    struct node*tmp = head;
    while(tmp!=NULL)
    {
        cout << tmp->value;
        tmp = tmp->next;
    }
    cout << endl;
}
int main()
{
    cout << endl;
    int sz=0;
    struct node*head = NULL;
    struct node*head2 = NULL;
    while(1)
    {
        cout << "1.insert"<<endl;
        cout << "2.encode"<<endl;
        cout << "3.show" << endl;
        int c;
        cin >> c;
        switch(c)
        {
            case 1:
                cout << "List 1:";
                char i;
                while(1)
                {
                    if(i=='/')
                    {
                        break;
                    }
                    else
                    {
                        cin >> i;
                        head = insert(head,i);

                    }
                }
                cout << "List 2:";
                char j;
                while(1)
                {
                    if(j=='/')
                    {
                        break;
                    }
                    else
                    {
                        cin >> j;
                        head2 = insert(head2,j);
                    }
                }
            break;
            case 2:
                sz = counts(head);
                encode(head,head2,sz);
            break;
            case 3:
                cout << "List1:";show(head);
                cout << "List2:";show(head2);
                cout << "Encode:";encode(head,head2,sz);
            break;
        }
    }
}
