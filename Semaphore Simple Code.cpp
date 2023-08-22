#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int signal(int s){
    s=s+1;
    return s;
}
int wait(int s){
    while(s<=0);
    s=s-1;
    return s;
}
int main()
{         
    int p[5],c[5],n=5;
    for(int i=0;i<5;i++) p[i]=i;
    for(int i=0;i<5;i++) c[i]=1;
    for(int i=0;i<n-1;i++){
        cout << "Think P: " << p[i] << endl;
        c[i]=wait(c[i]);        
    }
    for(int i=n-2;i>=0;i--){        
        cout << "Eat P: " << p[i] << endl;
        c[i]=signal(c[i]);
        if(i==n-2) cout << "Think P: " << n-1 << endl;
    }
    cout << "Eat P: "<< p[n-1] << endl;
}
