
#include <iostream>
#include "Header.h"
using namespace std;
int main() {
    int n,a;
    Stack<int> s1;
    Queue<int> q1,q2;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a;
        q1.Put(a);
    }
    while(!q1.Empty()){
        a=q1.Get();
        if (a%2==0){
            q2.Put(a);
        }
        else{
            s1.Push(a);
        }
    }
    while(!q2.Empty()){
        cout<<q2.Get()<<" ";
    }
    cout<<endl;
    while(!s1.Empty()){
        cout<<s1.Pop()<<" ";
    }
  
    return 0;
}
