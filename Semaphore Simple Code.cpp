#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// Dining Philosopher using Semaphore
int signal(int s){
    s=s+1;
    return s;
}
int wait(int s){
    while(s<1);
    s=s-1;
    return s;
}
int main()
{         
    int n;
    cin>>n;
    int p[n],c[n];
    for(int i=0;i<n;i++) p[i]=i;
    for(int i=0;i<n;i++) c[i]=1;
    for(int i=0;i<n-1;i++){
        cout << "Think P" << p[i] << endl;
        c[i]=wait(c[i]);        
    }
    cout << "waiting/trap: P" << n-1 << endl;
    for(int i=n-2;i>=0;i--){        
        cout << "Eat P" << p[i] << endl;
        c[i]=signal(c[i]);
    }
    cout << "Eat P"<< p[n-1] << endl;
}
