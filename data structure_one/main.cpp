#include<iostream>
#include<cmath>
#include<string>
#include <vector>
#include<exception>
#include <algorithm>
#include<vector>
using namespace std;
// create single linked list <<< forward;
// 1- create Node << value&&pointer from Node;
template<class t>
class NodeSingle
{
public:
    // Attributes:
    t value;
    NodeSingle*next;
    // constructor:
    NodeSingle()
    {
        this->value= {};
        this->next=nullptr;
    }
    NodeSingle(t value,NodeSingle*next)
    {
        this->next=next;
        this->value=value;
    }
};
// class Forward linked list:
template<class t>
class Forward_List
{
    // Attributes:
private:
#define node NodeSingle<t>
    node*head;
    node*tail;
public:
    // constructor:
    Forward_List()
    {
        this->head=nullptr;
        this->tail=nullptr;
    }
    Forward_List(node*head,node*tail)
    {
        this->head=head;
        this->tail=tail;
    }
    // keys:
    bool Empty()
    {
        return (head==nullptr);
    }
    // Destructor:
    ~Forward_List()
    {
        while(!Empty())
        {
            pop_front();
        }
    }
    // copy constructor:
    Forward_List(const Forward_List&l)
    {
        head=tail=nullptr;
        node*p=l.head;
        while(p!=nullptr)
        {
            push_back(p->value);
            p=p->next;
        }
    }
    // assignment operator overloading:
    void operator=(const Forward_List&l)
    {
        head=tail=nullptr;
        while(!Empty())
        {
            pop_front();
        }
        node*p=l.head;
        while(p!=nullptr)
        {
            push_back(p->value);
            p=p->next;
        }
    }
    // Methods:
    void push_front(t value)
    {
        if(Empty())
        {
            tail=head=new node(value,nullptr);
            return;
        }
        head=new node(value,head);
    }
    void pop_front()
    {
        if(Empty()) return;
        // if i have only one node:
        if(head==tail)
        {
            delete head;
            head=tail=nullptr;
            return;
        }
        // 1-create pointer points to head;
        // 2- head=head->next;
        // 3- delete pointer;
        node*temp=head;
        head=head->next;
        delete temp;
    }
    void push_back(t value)
    {
        if(Empty())
        {
            push_front(value);
            return;
        }
        tail=tail->next=new node(value,nullptr);
    }
    void pop_back()
    {
        if(Empty())
        {
            return;
        }
        if(head==tail)
        {
            delete head;
            head=tail=nullptr;
            return;
        }
        node*p=head;
        while(p->next->next!=nullptr)
        {
            p=p->next;
        }
        tail=p;
        delete p->next;
        p->next=nullptr;
    }
    void push_After(int rank_,t value)
    {
        if(rank_<0) return;
        node*p=head;
        for(int i=1; i<=rank_&&p!=nullptr; i++)
        {
            p=p->next;
        }
        if(p==nullptr)
        {
            return;
        }
        if(p->next==nullptr)
        {
            push_back(value);
            return;
        }
        p->next=new node(value,p->next);
    }
    void push_At(int rank_,t value)
    {
        if(rank_==0)
        {
            push_front(value);
            return;
        }
        push_After(rank_-1,value);
    }
    void pop_At(int rank_)
    {
        if(rank_==0)
        {
            pop_front();
            return;
        }
        node*p=head;
        for(int i=1; i<rank_&&p->next!=nullptr; i++)
        {
            p=p->next;
        }
        if(p->next==nullptr) return;
        if(p->next==tail)
        {
            pop_back();
            return;
        }
        node*temp=p->next;
        p->next=p->next->next;
        delete temp;
    }
    void print()
    {
        node*p=head;
        while(p!=nullptr)
        {
            cout << p->value << " -> ";
            p=p->next;
        }
        cout << " -> nullptr" << "\n";
    }
};
int main()
{
    Forward_List<int>l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    Forward_List<int>l2=l;
    l.print();
    l2.print();
    l.push_front(100);
    l.push_front(200);
    l.push_front(300);
    l.print();
    l.push_After(2,600);
    l.print();
    l.push_At(3,800);
    l.print();
    l.pop_At(1);
    l.print();
}
