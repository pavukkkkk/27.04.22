#include <iostream>
#include "Header.h"
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;
int main() {
    list <int>::iterator Iterl;
    vector <int>::iterator Iterv;
    vector<int> vec;
    queue<int> q1,q2;
    stack<int> s1,s2;
    list<int> l1;
    DoubleLinkedList<int> l;
    int n,a;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a;
        vec.push_back(a);
        l.Pushback(a);
        l1.push_back(a);
        q1.push(a);
        s1.push(a);
    }
    //LIST
    int flag=0;
    int b=0;
    for(int i: l1){
        
            if (i<b|| flag==0){
                flag=1;
                b=i;
            }
    
    }
    Iterl=l1.begin();
    Iterl++;
    l1.insert(Iterl, b);
    for(int i: l1){
        
        cout<<i<<" ";
    
    }
    cout<<endl;
    l.InsertRight(1, l.min());
    l.PrintLeftToRight();
    //LIST
    
    //VECTOR
    flag=0;
    for (int i=0;i<n;i++){
        if (i<b|| flag==0){
            b=vec[i];
            flag=1;
        }
    }
    Iterv=vec.begin();
    Iterv++;
    vec.insert(Iterv, b);
    for (int i=0;i<n+1;i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    //VECTOR
    
    //STACK
    flag=0;
    while (!s1.empty())
        {
            a= s1.top();
            if (a<b|| flag==0){
                b=a;
                flag=1;
            }
            s1.pop();
            s2.push(a);
        }
    s1.push(s2.top());
    s2.pop();
    s1.push(b);
    while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    while (!s2.empty())
        {
            cout << s2.top() << " ";
            s2.pop();
        }
    cout<<endl;
    //STACK
    
    
    //QUEUE
    flag=0;
    while (!q1.empty())
        {
            a= q1.front();
            if (a<b|| flag==0){
                b=a;
                flag=1;
            }
            q1.pop();
            q2.push(a);
        }
    q1.push(q2.front());
    q2.pop();
    q1.push(b);
    while (!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
    while (!q1.empty())
        {
            cout << q1.front() << " ";
            q1.pop();
        }
    
    //QUEUE
}
//2 3 4 -5 6 1
