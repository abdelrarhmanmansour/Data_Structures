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
#include<set> // BST-Self Balance- Unique values; (set has multi set) << so i not to be include multi set;
#include<map> // BST-Self Balance-has (keys&&values)Unique keys; (map has multi map) << so i not to be include multi set;
#include<numeric> // for GCD&&LCM;
using namespace std;
// Binary Search Tree:
// create template:
template<class t>
// create Node: 1-value 2-two pointers;
class Node
{
    // Attributes:
public:
    t value;
    Node*left;
    Node*right;
    // height:
    int height;
    // Parametrized Constructor:
    Node(t value)
    {
        this->value=value;
        this->left=nullptr;
        this->right=nullptr;
        // leaf height=zero;
        this->height=0;
    }
};
// create template:
template<class t>
// Create class BST:
class BST
{
    // for simple:
    // Attributes:
private:
#define node Node<t>
    node*root;
    // to traverse on BST:
    // 1-DFS << leaf to root but in 3 methods;
    // 1-PREeOrder << left,right,root;
    // 2-INORDER << left,root,right(sort);
    // 3- POSTORDER << root,left,right;
    void DFS_Print(node*p)
    {
        if (p == nullptr) return; // Base case: if the node is null, return
        // INORDER:
        DFS_Print(p->left);
        cout << p->value << " -> ";
        DFS_Print(p->right);
    }
    void BFS_Print()
    {
        // using queue;
        queue<node*>q;
        q.push(root);
        while(!q.empty())
        {
            // print front then push left,right then pop;
            cout << q.front()->value << " -> ";
            if(q.front()->left!=nullptr)
                q.push(q.front()->left);
            if(q.front()->right!=nullptr)
                q.push(q.front()->right);
            q.pop();
        }
    }
    // if i want to traverse and insert:
    void DFS_copy_constructor(node*p)
    {
        // INORDER:
        DFS_copy_constructor(p->left);
        Insert(p->value);
        DFS_copy_constructor(p->right);
    }
public:
    // Default Constructor:
    BST()
    {
        this->root=nullptr;
    }
    // Parametrized Constructor:
    BST(node*root)
    {
        this->root=root;
    }
    // copy Constructor:
    BST(const BST&tree)
    {
        this->root=nullptr;
        DFS_copy_constructor(tree.root);
    }
    // Operator Overloading(=):
    void operator=(const BST&tree)
    {
        this->root=nullptr;
        while(!Empty())
        {
            Remove(root->value);
        }
        DFS_copy_constructor(tree.root);
    }
    // Destructor:
    ~BST()
    {
        while(!Empty())
        {
            Remove(root->value);
        }
    }
    // Keys:
    bool Empty()
    {
        return (root==nullptr);
    }
    // Methods:
    bool Search(t value)
    {
        // if i found any value exist should stop <<< because any value in BST is Unique;
        node*temp=root;
        while(temp!=nullptr)
        {
            if(temp->value==value)
            {
                return true;
            }
            if(value>temp->value)
            {
                temp=temp->right;
            }
            else
            {
                temp=temp->left;
            }
        }
        return false;
    }
    void Insert(t value)
    {
        if(Search(value)) return;
        if(Empty())
        {
            root=new node(value);
            return;
        }
        node*temp=root;
        while(true)
        {
            if(value>temp->value)
            {
                //check right not null;
                if(temp->right==nullptr) break;
                temp=temp->right;
            }
            else
            {
                //check left not null;
                if(temp->left==nullptr) break;
                temp=temp->left;
            }
        }
        if(value>temp->value)
            temp->right=new node(value);
        else
            temp->left=new node(value);
    }
    // Remove three cases:
    void Remove(t value)
    {
        if(Empty()) return;
        if(Search(value));
        else
            return;
        // create two pointer at root;
        node*p=root;
        node*parent=root;
        while(true)
        {
            if(value>p->value)
            {
                if(p->right!=nullptr)
                {
                    parent=p;
                    p=p->right;
                }
                else
                    return;
            }
            else if(value<p->value)
            {
                if(p->left!=nullptr)
                {
                    parent=p;
                    p=p->left;
                }
                else
                    return;
            }
            else
            {
                // from leaf(has no children):
                // i stands at leaf node:
                if(p->right==nullptr&&p->left==nullptr)
                {
                    // if leaf node is root:
                    if(root==p)
                    {
                        root=nullptr;
                        delete p;
                        return;
                    }
                    // we need to know where is p;
                    if(parent->left==p)
                        parent->left=nullptr;
                    else
                        parent->right=nullptr;
                    delete p;
                    return;
                }
                //(one child):
                else if(p->right==nullptr||p->left==nullptr)
                {
                    // if leaf node is root:
                    if(root==p)
                    {
                        root=((root->left!=nullptr)?root->left:root->right);
                        delete p;
                        return;
                    }
                    node*temp=((p->left!=nullptr)?p->left:p->right);
                    if(parent->left==p)
                        parent->left=temp;
                    else
                        parent->right=temp;
                    delete p;
                    return;
                }
                //(two children): important;
                else
                {
                    // i do not remove;
                    // swap;
                    node*SR=p->right;
                    while(SR->left!=nullptr)
                    {
                        SR=SR->left;
                    }
                    value=SR->value;
                    parent=p;
                    p=p->right;
                }
            }
        }
    }
    // to print BST:
    void Print_DFS()
    {
        DFS_Print(root);
    }
    // to print BST:
    void Print_BFS()
    {
        BFS_Print();
    }
};
// create template:
template<class t>
// create class AVL << BST << Balanced;
class AVL
{
    // Attributes:
private:
#define node Node<t>
    node*root;
public:
    // Default Constructor:
    AVL()
    {
        this->root=nullptr;
    }
    // Parametrized Constructor:
    AVL(node*root)
    {
        this->root=root;
    }
    // copy Constructor:
    // Operator Overloading(=):
    // Destructor:
    ~AVL()
    {
        while(!Empty())
        {
            Remove(root->value);
        }
    }
    // Keys:
    bool Empty()
    {
        return (root==nullptr);
    }
    // Methods:
    // this function return height of any node:
    int Get_Height(node*p)
    {
        // handle value << -1:
        if(p==nullptr)
            return -1;
        return p->height;
    }
    // this function height update of any node:
    void Height_Update(node*p)
    {
        // to use it in insert;
        p->height=1+max(Get_Height(p->left),Get_Height(p->right));
    }
    // this function return balance factor of any node:
    int Get_Balance_Factor(node*p)
    {
        return ((Get_Height(p->left))-(Get_Height(p->right)));
    }
    // Right Rotation(left left):
    node*Right_Rotation(node*p)
    {
        // steps:
        node*leftside=p->left;
        node*leftsideright=leftside->right;
        p->left=leftsideright;
        leftside->right=p;
        Height_Update(p);
        Height_Update(leftside);
        return leftside;
    }
    // Left Rotation(right right):
    node*Left_Rotation(node*p)
    {
        // steps:
        node*rightside=p->right;
        node*rightsideleft=rightside->left;
        p->right=rightsideleft;
        rightside->left=p;
        Height_Update(p);
        Height_Update(rightside);
        return rightside;
    }
    // insert using recursion: return node + has value,pointer;
    node*Insert(t value,node*p)
    {
        // Base case:
        if(p==nullptr) return new node(value);
        // Recursion:
        if(value>p->value)
            p->right=Insert(value,p->right);
        else if(value<p->value)
            p->left=Insert(value,p->left);
        else
            // value is found:
            return p;
        // Backtracking:
        // steps:
        Height_Update(p);
        // check balance factor:
        int bf= Get_Balance_Factor(p);
        // 4 cases:
        //  1- left left:
        if(bf>1&&value<p->left->value)
            return Right_Rotation(p);
        //  2- right right:
        if(bf<-1&&value>p->right->value)
            return Left_Rotation(p);
        //  3- left right:
        if(bf>1&&value>p->left->value)
        {
            p->left=Left_Rotation(p->left);
            return Right_Rotation(p);
        }
        //  4- right left:
        if(bf<-1&&value<p->right->value)
        {
            p->right=Right_Rotation(p->right);
            return Left_Rotation(p);
        }
        return p;
    }
    node*Insert(t value)
    {
        root=Insert(value,root);
        return root;
    }
    void Remove(t value)
    {
        root=Remove(value,root);
    }
    // remove using recursion: return node + has value,pointer;
    node*Remove(t value,node*p)
    {
        // Base case:
        if(p==nullptr) return nullptr;
        // Recursion:
        if(value>p->value)
            p->right=Remove(value,p->right);
        else if(value<p->value)
            p->left=Remove(value,p->left);
        else // value is found:
        {
            // three cases:
            // case no child && one child:
            if(p->left==nullptr || p->right==nullptr)
            {
                node*temp=((p->left!=nullptr)?p->left:p->right);
                delete p;
                return temp;
            }
            // case two child;
            node*SR=p->right;
            while(SR->left!=nullptr)
            {
                SR=SR->left;
            }
            p->value=SR->value;
            p->right=Remove(SR->value,p->right);
        }
        // Backtracking:
        // steps:
        Height_Update(p);
        // check balance factor:
        int bf= Get_Balance_Factor(p);
        // 4 cases:
        //  1- left left:
        if(bf>1&&Get_Balance_Factor(p->left)>=0)
            return Right_Rotation(p);
        //  2- right right:
        if(bf<-1&&Get_Balance_Factor(p->right)<=0)
            return Left_Rotation(p);
        //  3- left right:
        if(bf>1&&Get_Balance_Factor(p->left)<0)
        {
            p->left=Left_Rotation(p->left);
            return Right_Rotation(p);
        }
        //  4- right left:
        if(bf<-1&&Get_Balance_Factor(p->right)>0)
        {
            p->right=Right_Rotation(p->right);
            return Left_Rotation(p);
        }
        return p;
    }
    void DFS_Print(node*p)
    {
        if (p == nullptr) return; // Base case: if the node is null, return
        // INORDER:
        DFS_Print(p->left);
        cout << p->value << " -> " << Get_Balance_Factor(p) << "\n";
        DFS_Print(p->right);
    }
    void print()
    {
        DFS_Print(root);
    }
};

// function to traverse on set:
void Show_Set(set<int>s)
{
    set<int>::iterator it;
    for(it=s.begin(); it!=s.end(); it++)
        cout <<  *it << " ";
}

// function to traverse on multi set:
void Show_multi_Set(multiset<int>s)
{
    multiset<int>::iterator it;
    for(it=s.begin(); it!=s.end(); it++)
        cout <<  *it << " ";
}
// function to traverse on map:
void Show_Map(map<int,string>m)
{
    map<int,string>::iterator it;
    for(it=m.begin(); it!=m.end(); it++)
    {
        // i have pair so first << second;
        cout << it->first << " , " << it->second << "\n";
    }
}
// function to traverse on multi map:
void Show_Multi_Map(multimap<int,string>m)
{
    multimap<int,string>::iterator it;
    for(it=m.begin(); it!=m.end(); it++)
    {
        // i have pair so first << second;
        cout << it->first << " , " << it->second << "\n";
    }
}
int main()
{
    // For Binary Search Tree:
    BST<int>bst;
    bst.Insert(50);
    bst.Insert(30);
    bst.Insert(80);
    bst.Insert(20);
    bst.Insert(40);
    bst.Insert(70);
    bst.Insert(90);
    bst.Insert(10);
    bst.Insert(25);
    bst.Insert(35);
    bst.Insert(45);
    bst.Insert(60);
    bst.Insert(75);
    bst.Insert(85);
    bst.Insert(100);
    bst.Insert(55);
    bst.Insert(47);
    bst.Print_DFS();
    cout << "\n";
    bst.Print_BFS();
    cout << "\n";
    bst.Remove(100);
    bst.Print_DFS();

    // For AVL:
    //Check LL

    AVL<int> mytree;
    mytree.Insert(3000);
    mytree.Insert(2000);
    mytree.Insert(1000);

    //Check RR
    mytree.Insert(1000);
    mytree.Insert(2000);
    mytree.Insert(3000);

    //Check Insertion
    for (int i = 0; i <= 1000; i++)
        mytree.Insert(i);

    //Check Remove
    for (int i = 0; i <= 500; i++)
        mytree.Remove(i);

    mytree.print();

    // For set:
    set<int>s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(-10);
    s.insert(-100);
    s.insert(10);
    s.insert(154);
    Show_Set(s);
    cout << "\n";
    s.erase(-100);
    Show_Set(s);
    cout << "\n";


    // For multi set:
    multiset<int>ss;
    ss.insert(10);
    ss.insert(20);
    ss.insert(30);
    ss.insert(-10);
    ss.insert(-100);
    ss.insert(10);
    ss.insert(154);
    Show_multi_Set(ss);
    cout << "\n";
    ss.erase(-100);
    Show_multi_Set(ss);
    cout << "\n";

    // For map:
    map<int,string>m;
    m.insert(pair<int,string>(1,"messi"));
    m.insert(pair<int,string>(11,"salah"));
    m.insert(pair<int,string>(7,"CR7"));
    m.insert(pair<int,string>(10,"nymar"));
    m.insert(pair<int,string>(1,"treka"));
    Show_Map(m);
    cout << "\n";
    m.erase(10);
    Show_Map(m);

    // For multi map:
    multimap<int,string>mm;
    mm.insert(pair<int,string>(1,"messi"));
    mm.insert(pair<int,string>(11,"salah"));
    mm.insert(pair<int,string>(7,"CR7"));
    mm.insert(pair<int,string>(10,"nymar"));
    mm.insert(pair<int,string>(1,"treka"));
    Show_Multi_Map(mm);
    cout << "\n";
    mm.erase(10);
    Show_Multi_Map(mm);
}
