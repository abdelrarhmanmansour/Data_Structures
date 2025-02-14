#include<iostream>
#include<cmath>
#include<string>
#include <vector>
#include<exception>
#include <algorithm>
#include<vector>
#include<forward_list>
#include<list>
using namespace std;
// create Double linked list <<< list;
// 1- create Node << pointer from Node&value&&pointer from Node;
template<class t>
class NodeDouble
{
public:
    // Attributes:
    NodeDouble*prev;
    t value;
    NodeDouble*next;
    // constructor:
    NodeDouble()
    {
        this->prev=nullptr;
        this->value= {};
        this->next=nullptr;
    }
    NodeDouble(NodeDouble*prev,t value,NodeDouble*next)
    {
        this->prev=prev;
        this->next=next;
        this->value=value;
    }
};
// class Double Linked List:
template<class t>
class List
{
    // Attributes:
private:
#define node NodeDouble<t>
    node*head;
    node*tail;
public:
    // constructor:
    List()
    {
        this->head=nullptr;
        this->tail=nullptr;
    }
    List(node*head,node*tail)
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
    ~List()
    {
        while(!Empty())
        {
            pop_front();
        }
    }
    // copy constructor:
    List(const List&l)
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
    void operator=(const List&l)
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
            tail=head=new node(nullptr,value,nullptr);
            return;
        }
        head=head->prev=new node(nullptr,value,head);
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
        // 1- head=head->next;
        // 2- delete head->next;
        head=head->next;
        delete head->prev;
        head->prev=nullptr;
    }
    void push_back(t value)
    {
        if(Empty())
        {
            push_front(value);
            return;
        }
        tail=tail->next=new node(tail,value,nullptr);
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
        tail=tail->prev;
        delete tail->next;
        tail->next=nullptr;
    }
    void push_After(int rank_,t value)
    {
        if(rank_==0)
        {
            push_front(value);
            return;
        }
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
        p->next=p->next->prev=new node(p,value,p->next);
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
        p->next=p->next->next;
        delete p->next;
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
    // this is function to traverse in Forward List;
// create iterator;
// start from begin to end;
// important: it is pointer so we make *it to return values;
// or using for each;
    void Show_List(list<int>l)
    {
        list<int>::iterator it;
        for(it=l.begin(); it!=l.end(); it++)
        {
            cout << *it << " -> ";
        }
    }
};
int main()
{
    List<int>l;
    l.push_front(10);
    l.push_front(20);
    l.push_front(30);
    l.push_front(40);
    l.print();
    l.push_back(50);
    l.print();
    l.push_After(2,100);
    l.print();
    l.push_At(0,200);
    l.print();
    l.pop_At(0);
    l.print();
}

