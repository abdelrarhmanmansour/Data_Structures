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
#include<unordered_set> // built in function for Hash Table;
#include<unordered_map> // built in function for Hash Table;
#include<numeric> // for GCD&&LCM;
using namespace std;
// Fib using Recursion:
int Fib(int number)
{
    // Base Case:
    if(number==0)
        return 0;
    if(number==1||number==2)
        return 1;
    return (Fib(number-1)+Fib(number-2));
}
// Fib using Dynamic Programming,save last result:
int Fib(int number,int*arr)
{
    // Base Case:
    if(arr[number]!=-1)
        return arr[number];
    arr[number]= (Fib(number-1,arr)+Fib(number-2,arr));
    return arr[number];
}
// Algorithms:
// 1- Bubble Sort: Brute Force
// BestCase: O(n) , AverageCase: O(n^2) , WorstCase: O(n^2);
void Bubble_Sort(int *arr,int size_)
{
    for(int i=0; i<size_; i++)
    {
        for(int j=0; j<size_-1; j++)
        {
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}
// 2- Insertion Sort: Brute Force
// BestCase: O(n) , AverageCase: O(n^2) , WorstCase: O(n^2);
void Insertion_Sort(int *arr,int size_)
{
    for(int i=0; i<size_-1; i++)
    {
        for(int j=i; j>=0&&(arr[j]>arr[j+1]); j--)
            swap(arr[j],arr[j+1]);
    }
}
// 3- Selection Sort: Brute Force
// BestCase: O(n^2) , AverageCase: O(n^2) , WorstCase: O(n^2); // bad one
void Selection_Sort(int *arr,int size_)
{
    for(int i=0; i<size_-1; i++)
    {
        int mi=i;
        for(int j=i+1; j<size_; j++)
        {
            if(arr[mi]>arr[j])
            {
                mi=j;
            }
        }
        if(mi!=i)
            swap(arr[i],arr[mi]);
    }
}
// 4- Merge Sort: Divide&&Conquer Recursion; Best one in time not memory;
// BestCase: O(n log(n)) , AverageCase: O(n log(n)) , WorstCase: O(n log(n));
// Mid = left+(right-left)/2;
// left arr size= Mid-left+1;
// right arr size= right-Mid;
// base case: left=right;
void Merge_Sort(int *arr,int left,int right,int mid)
{
    // Divide:
    // size of left&&right using formula:
    int leftsize= mid-left+1;
    int rightsize= right-mid;
    // create two array:
    int *leftarr=new int[leftsize];
    int *rightarr=new int[rightsize];
    for(int i=0; i<leftsize; i++)
        leftarr[i]= arr[left+i];
    for(int i=0; i<rightsize; i++)
        rightarr[i]= arr[mid+1+i];
    // Merge:
    // create three integers : left,right,k: big arr;
    int i=0,j=0,k=left; // k=left : recursion
    while(i<leftsize&&j<rightsize)
    {
        if(leftarr[i]<rightarr[j])
        {
            arr[k]=leftarr[i];
            k++;
            i++;
        }
        else
        {
            arr[k]=rightarr[j];
            k++;
            j++;
        }
    }
    // Remaining:
    while(i<leftsize)
    {
        arr[k]=leftarr[i];
        k++;
        i++;
    }
    while(j<rightsize)
    {
        arr[k]=rightarr[j];
        k++;
        j++;
    }
}
// recursion in merge sort:
void Merge_Algorithm(int*arr,int left,int right)
{
    // Base Case:
    if(left>=right) return;
    int mid=left+(right-left)/2;
    Merge_Algorithm(arr,left,mid);
    Merge_Algorithm(arr,mid+1,right);
    Merge_Sort(arr,left,right,mid);
}
// 5- Binary Search: Divide&&Conquer must be array sorted;
// BestCase: O(1) , AverageCase: O(log(n)) , WorstCase: O(log(n));
// Mid = left+(right-left)/2;
int Binary_Search(int*arr,int left,int right,int search_element)
{
    // Base Case:
    while(left<=right)
    {
        int mid =left+(right-left)/2;
        if(arr[mid]==search_element)
            return mid;
        if(arr[mid]<search_element)
            left=mid+1;
        if(arr[mid]>search_element)
            right=mid-1;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int*arr=new int[n];
    arr[0]=0;
    arr[1]=1;
    arr[2]=1;
    for(int i=3; i<=n; i++)
        arr[i] =-1;
    cout << "Fib(" << n << ")= " << Fib(n) << "\n";
    cout << "Fib(" << n << ")= " << Fib(n,arr);
    // Array:
    int size_=6;
    int *arr=new int[6];
    for(int i=0; i<6; i++)
    {
        cin >> arr[i];
    }
    Bubble_Sort(arr,6);
    Insertion_Sort(arr,6);
    Selection_Sort(arr,6);
    Merge_Algorithm(arr,0,5);
    // Built in function:
    sort(arr,arr+6);
    int result =Binary_Search(arr,0,5,100);
    if(result!=-1)
        cout << "Exist\n";
    else
        cout << "Not Exist";
    //  Built in function in search:
    if(binary_search(arr,arr+6,100))
        cout << "Exist\n";
    else
    {
        cout << "Not Exist";
    }
    for(int i=0; i<6; i++)
    {
        cout << arr[i] << " ";
    }
}
