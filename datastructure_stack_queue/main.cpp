#include<iostream>
#include<cmath>
#include<string>
#include <vector>
#include<exception>
#include <algorithm>
#include<vector>
#include<forward_list>
#include<list>
#include<stack>
#include<queue>
#include<numeric> // for GCD&&LCM;
using namespace std;
// create Node for stack&&queue;
// this Node: 1- value 2- two pointer;
// create template:
template<class t>
class Node
{
    // Attributes:
public:
    Node*prev;
    t value;
    Node*next;
    // Default Constructor:
    Node()
    {
        this->value=0;
        this->next=nullptr;
        this->prev=nullptr;
    }
    // Parametrized Constructor:
    Node(t value,Node*prev,Node*next)
    {
        this->prev=prev;
        this->value=value;
        this->next=next;
    }
};
// create class Stack from scratch:
// create template:
template<class t>
// push&&pop<<< same direction;
class Stack
{
    // Attributes:
private:
    // for more simple:
#define node Node<t>
    t size_; // size of stack;
    node*head;
    node*tail;
public:
    // Default Constructor:
    Stack()
    {
        this->tail=nullptr;
        this->size_=0;
        this->head=nullptr;
    }
    // Parametrized Constructor:
    Stack(node*head,node*tail)
    {
        this->head=head;
        this->tail=tail;
    }
    // Keys:
    int top()
    {
        cout << "The Top of Stack: ";
        return tail->value;
    }
    int Size()
    {
        cout << "The Size of Stack: ";
        return this->size_;
    }
    bool Empty()
    {
        return (head==nullptr||tail==nullptr);
    }
    // Methods:
    void push(t value)
    {
        if(Empty())
        {
            tail=head=new node(value,nullptr,nullptr);
            size_++;
            return;
        }
        tail=tail->next= new node(value,tail,nullptr);
        size_++;
    }
    void pop()
    {
        if(Empty()) return;
        if(size_==1)
        {
            delete head;
            head=tail=nullptr;
            size_--;
            return;
        }
        node*temp=tail->prev;
        delete tail;
        tail=temp;
        tail->next=nullptr;
        size_--;
    }
    void print()
    {
        cout << "The Result is:\n";
        node* current = tail; // Start from the top of the stack
        while (current)  // pointer is not null pointer[nullptr];
        {
            cout << current->value << " ";
            current = current->prev; // Move to the previous node
        }
        cout << "\n";
    }
    void Reverse() // same print of Queue;
    {
        cout << "The Reverse is:\n";
        node* current = head;
        while (current)
        {
            cout << current->value << " ";
            current = current->next; // Move to the previous node
        }
        cout << "\n";
    }
};
// create class Queue from Scratch:
// create template:
template<class t>
class Queue
// push << back  && pop << front;
{
    // Attributes:
private:
    // for more simple:
#define node Node<t>
    t size_; // size of stack;
    node*head;
    node*tail;
public:
    // Default Constructor:
    Queue()
    {
        this->tail=nullptr;
        this->size_=0;
        this->head=nullptr;
    }
    // Parametrized Constructor:
    Queue(node*head,node*tail)
    {
        this->head=head;
        this->tail=tail;
    }
    // Keys:
    bool IsEmpty()
    {
        return (head==nullptr || tail==nullptr);
    }
    int SizeofQueue()
    {
        cout << "The Size of Queue: ";
        return this->size_;
    }
    int Front()
    {
        cout << "The Top of Queue: ";
        return head->value;
    }
    // Methods:
    void push(t value)
    {
        if(IsEmpty())
        {
            tail=head=new node(value,nullptr,nullptr);
            size_++;
            return;
        }
        tail=tail->next= new node(value,tail,nullptr);
        size_++;
    }
    void pop()
    {
        if(IsEmpty()) return;
        if(size_==1)
        {
            delete head;
            head=tail=nullptr;
            size_--;
            return;
        }
        node*temp=head->next;
        delete head;
        head=temp;
        head->prev=nullptr;
        size_--;
    }
    void print()
    {
        cout << "The Result is:\n";
        node* current = head; // Start from the top of the queue;
        while (current)  // pointer is not null pointer[nullptr];
        {
            cout << current->value << " ";
            current = current->next; // Move to the previous node
        }
        cout << "\n";
    }
    void Reverse() // same print Stack;
    {
        cout << "The Reverse is:\n";
        node* current = tail;
        while (current)
        {
            cout << current->value << " ";
            current = current->prev;
        }
        cout << "\n";
    }
};
int main()
{
    // For Stack:
    Stack<int>mystack;
    cout << "The Result Operation about Stack:\n";
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    mystack.push(4);
    mystack.push(5);
    mystack.push(8);
    mystack.pop();
    cout << mystack.top() << "\n";
    cout << mystack.Size() << "\n";
    mystack.print();
    mystack.push(20);
    mystack.print();
    mystack.pop();
    mystack.print();
    mystack.Reverse();
//########################################################
    // For Queue:
    Queue<int>myqueue;
    cout << "The Result Operation about Queue:\n";
    myqueue.push(10);
    myqueue.push(20);
    myqueue.push(30);
    myqueue.push(40);
    myqueue.push(50);
    myqueue.print();
    myqueue.pop();
    myqueue.print();
    cout << myqueue.Front() << "\n";
    cout << myqueue.SizeofQueue() << "\n";
    myqueue.Reverse();
}
