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
#include<unordered_set> // built in function for Hash_Table;
#include<unordered_map> // built in function for Hash_Table;
#include<numeric> // for GCD&&LCM;
using namespace std;
void Show_Unordered_Set(unordered_set<int>s)
{
    unordered_set<int>::iterator it;
    for(it=s.begin(); it!=s.end(); it++)
        cout << *it << " ";
    cout << "\n";
}
void Show_Unordered_Multi_Set(unordered_multiset<int>s)
{
    unordered_multiset<int>::iterator it;
    for(it=s.begin(); it!=s.end(); it++)
        cout << *it << " ";
    cout << "\n";
}
void Show_Unordered_Map(unordered_map<int,string>ma)
{
    unordered_map<int,string>::iterator it;
    {
        for(it=ma.begin(); it!=ma.end(); it++)
            cout << it->first << " " << it->second << "\n";
        cout << "\n";
    }
}
void Show_Unordered_Multi_Map(unordered_multimap<int,string>ma)
{
    unordered_multimap<int,string>::iterator it;
    {
        for(it=ma.begin(); it!=ma.end(); it++)
            cout << it->first << " " << it->second << "\n";
        cout << "\n";
    }
}
// traverse on graph using DFS(currentNode,searchedNode,graph,array visited):
void DFS(int currentNode,int searchedNode,vector<vector<int>>graph,bool visited[])
{
    visited[currentNode]=true;
    // Base Case:
    if(currentNode==searchedNode)
        return;
    cout << currentNode << "-> ";
    // Recursion:
    for(int i=0; i<graph[currentNode].size(); i++)
    {
        int child=graph[currentNode][i];
        if(!visited[child])
        {
            DFS(child,searchedNode,graph,visited);
        }
    }
}
// get shortest path algorithm:
void SPADFS(int currentNode,int searchedNode,vector<vector<int>>graph,bool visited[],int dist)
{
    visited[currentNode]=true;
    // Base Case:
    if(currentNode==searchedNode)
    {
        cout << "SPADFS: " << dist << "\n";
        return;
    }
    // Recursion:
    for(int i=0; i<graph[currentNode].size(); i++)
    {
        int child=graph[currentNode][i];
        if(!visited[child])
        {
            SPADFS(child,searchedNode,graph,visited,dist+1);
        }
    }
}
// traverse on graph using BFS(currentNode,searchedNode,graph,array visited):
void BFS(int currentNode,int searchedNode,vector<vector<int>>graph,bool visited[])
{
    visited[currentNode]=true;
    // Base Case:
    if(currentNode==searchedNode)
        return;
    // create Queue:
    queue<int>q;
    q.push(currentNode);
    while(!q.empty())
    {
        currentNode=q.front();
        cout << q.front() << "-> ";
        for(int i=0; i<graph[currentNode].size(); i++)
        {
            int child=graph[currentNode][i];
            if(!visited[child])
            {
                q.push(child);
                visited[child]=true;
            }
        }
        q.pop();
    }
}
// get shortest path algorithm:
// weighted graph << not using BFS << using  Dijkstra’s Algorithm;
void SPABFS(int currentNode,int searchedNode,vector<vector<int>>graph,bool visited[])
{
    int start =currentNode;
    visited[currentNode]=true;
    // create Queue:
    queue<pair<int,int>>q;
    q.push({currentNode,0});
    int dist,child;
    while(!q.empty())
    {
        currentNode=q.front().first;
        dist=q.front().second;
        if(currentNode==searchedNode)
        {
            cout << "SPABFS: " << dist << "\n";
            return;
        }
        for(int i=0; i<graph[currentNode].size(); i++)
        {
            child=graph[currentNode][i];
            if(!visited[child])
            {
                q.push({child,dist+1});
                visited[child]=true;
            }
        }
        q.pop();
    }
}
int main()
{
    // Graph Modeling:

    // Enter number of nodes && edges:
    cout << "Please Enter number of nodes && edges:\n";
    int nodes,edges;
    cin >> nodes >> edges;
    // Create 2D Vectors called Graph:
    // size of graph: nodes+1 << because ignore to zero;
    vector<vector<int>>graph(nodes+1);
    // here start of node && end of node:
    int node1,node2;
    for(int i=1; i<=edges; i++)
    {
        cout << "Enter start of node && end of node =" << i << "\n";
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    //print elements in graph:
    for(int i=1; i<=nodes; i++)
    {
        cout << "Row: " << i << "==>> ";
        for(int j=0; j<graph[i].size(); j++)
        {
            cout << graph[i][j] << "|";
        }
        cout << "\n";
    }

    // traverse on graph using DFS:
    // create array in heap:
    // must here initialize to false;
    bool*visited= new bool[nodes+1] {};
    DFS(1,-1,graph,visited);
    BFS(1,-1,graph,visited);
    SPABFS(1,6,graph,visited);
    SPADFS(1,6,graph,visited,0);

    // built in function for Hash Table:
    //unordered set:
    unordered_set<int>s;
    s.insert(10);
    s.insert(50);
    s.insert(30);
    s.insert(60);
    s.insert(70);
    s.insert(100);
    s.insert(105);
    s.insert(109);
    s.insert(10);
    s.insert(109);
    Show_Unordered_Set(s);
    cout << s.size() << "\n";
    s.erase(50);
    Show_Unordered_Set(s);
    // unordered multi set:
    unordered_multiset<int> ms;
    ms.insert(10);
    ms.insert(50);
    ms.insert(30);
    ms.insert(60);
    ms.insert(70);
    ms.insert(100);
    ms.insert(105);
    ms.insert(109);
    ms.insert(10);
    ms.insert(109);
    Show_Unordered_Multi_Set(ms);
    cout << ms.size() << "\n";
    ms.erase(50);
    Show_Unordered_Multi_Set(ms);
    // unordered map:
    unordered_map<int,string>ma;
    ma.insert(pair<int,string>(1,"MESSI"));
    ma.insert(pair<int,string>(2,"CR7"));
    ma.insert(pair<int,string>(3,"NYMAR"));
    ma.insert(pair<int,string>(4,"SALAH"));
    ma.insert(pair<int,string>(1,"MESSI"));
    Show_Unordered_Map(ma);
    ma.erase(4);
    Show_Unordered_Map(ma);
    // unordered multi map:
    unordered_multimap<int,string>maa;
    maa.insert(pair<int,string>(1,"MESSI"));
    maa.insert(pair<int,string>(2,"CR7"));
    maa.insert(pair<int,string>(3,"NYMAR"));
    maa.insert(pair<int,string>(4,"SALAH"));
    maa.insert(pair<int,string>(1,"MESSI"));
    Show_Unordered_Multi_Map(maa);
    maa.erase(4);
    Show_Unordered_Multi_Map(maa);
}
