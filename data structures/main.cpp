#include<iostream>
#include<cmath>
#include<string>
#include <vector>
#include<exception>
#include <algorithm>
using namespace std;
// 1- Vectors from scratch:
// size&&capacity;
// pointers;
// create template: to handle any type of elements;
template<class T>
class Vector
{
    // Attributes:
private:
    T*arr;
    int size,cap;
    void expand()
    {
        cap*=2;
        T*temp=new T[cap] {};
        for(int i=0; i<size; i++)
        {
            temp[i]=arr[i];
        }
        delete[]arr;
        arr=temp;
    }
public:
    // Constructor:
    Vector()
    {
        this->size=0;
        this->cap=2;
        this->arr=new T[cap];
    }
    // copy constructor:
    Vector(const Vector&v)
    {
        this->size=v.size;
        this->cap=v.cap;
        if(v.arr==nullptr)
        {
            this->arr=nullptr;
            return;
        }
        arr=new T[cap] {};
        for(int i=0; i<cap; i++)
        {
            arr[i]=v.arr[i];
        }
    }
    // assignment operator overloading
    void operator=(const Vector&v)
    {
        this->size=v.size;
        this->cap=v.cap;
        delete[]arr;
        if(v.arr==nullptr)
        {
            this->arr=nullptr;
            return;
        }
        arr=new T[cap] {};
        for(int i=0; i<cap; i++)
        {
            arr[i]=v.arr[i];
        }
    }
    // Keys:
    bool Full()
    {
        return (size==cap);
    }
    int Size()
    {
        return size;
    }
    int Cap()
    {
        return cap;
    }
    bool Empty()
    {
        return (size==0);
    }
    // Methods:
    void push_back(T value)
    {
        if(Full())
        {
            // expand;
            expand();
        }
        arr[size]=value;
        size++;
    }
    void pop_back()
    {
        if(Empty()) return;
        size--;
        if(size<cap/3) shrink_to_fit();
    }
    // push front :add from start;
    void push_front(T value)
    {
        if(Full())
        {
            expand();
        }
        if(Empty())
        {
            push_back(value);
            return;
        }
        for(int i=size-1; i>=0; i--)
        {
            arr[i+1]=arr[i];
        }
        arr[0]=value;
        size++;
    }
    // pop front: delete first element;
    void pop_front()
    {
        if(Empty()) return;
        if(size==1)
        {
            pop_back();
            return;
        }
        for(int i=0; i<size-1; i++)
        {
            arr[i]=arr[i+1];
        }
        pop_back();
    }
    void Traverse()
    {
        for(int i=0; i<size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    // to make size=cap;
    void shrink_to_fit()
    {
        cap=size;
        T*temp=new T[cap] {};
        for(int i=0; i<size; i++)
        {
            temp[i]=arr[i];
        }
        delete[]arr;
        arr=temp;
    }
    // Destructor:
    ~Vector()
    {
        delete[]arr;
    }
};
int main()
{
    Vector<int>v,v3;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    v.Traverse();
    v.pop_back();
    v.Traverse();
    v.push_front(100);
    v.Traverse();
    v.pop_front();
    v.Traverse();
    // copy constructor:
    Vector<int>v2=v;
    v2.Traverse();
    // assignment operator overloading:
    v3=v2;
    v3.Traverse();
}
