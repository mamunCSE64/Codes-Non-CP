#include <bits/stdc++.h>
#include <iostream>
#define fi first
#define se second
#define pb push_back
using namespace std;

int main()
{        
    int n,R1,R2,R3;
    cin>>n>>R1>>R2>>R3;
    vector<pair<pair<int,int>,int>> maxN,allocR,currentR,available;
    for(int i=0;i<n;i++){
        int a,b,c; cin>>a>>b>>c;
        maxN.pb({{a,b},c});
    }
    int r1=0,r2=0,r3=0;       
    for(int i=0;i<n;i++){
        int a,b,c; cin>>a>>b>>c;
        allocR.pb({{a,b},c});
        r1+=a,r2+=b,r3+=c;
    } 
    for(int i=0;i<n;i++){
        int x,y,z;
        x=maxN[i].fi.fi-allocR[i].fi.fi;
        y=maxN[i].fi.se-allocR[i].fi.se;
        z=maxN[i].se-allocR[i].se;
        currentR.pb({{x,y},z});
    }
    int nR1,nR2,nR3;
    nR1=R1-r1;
    nR2=R2-r2;
    nR3=R3-r3;
    int count=0;
    vector<int> a(n,1);    
    cout << R1 << " " << R2 << " " << R3 << endl;
    while(count<n){
        int x=1;
        for(int i=0;i<n;i++){
            if(a[i]){
                if(currentR[i].fi.fi<=nR1 and 
                    currentR[i].fi.se<=nR2 
                    and currentR[i].se<=nR3){

                    nR1+=allocR[i].fi.fi;
                    nR2+=allocR[i].fi.se;
                    nR3+=allocR[i].se;
                    a[i]=0,count++,x=0;
                    cout << "Safe State : P " << i << endl;
                }
            }
        }
        if(x){ cout << "DeadLock Created " << endl; return 0;}
    }  
    cout << nR1 << " " << nR2 << " " << nR3 << endl;    
}
