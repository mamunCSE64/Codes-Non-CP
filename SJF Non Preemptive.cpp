#include <bits/stdc++.h>
#include <iostream>
#define ll long long int
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define gcd __gcd
#define int_string to_string
#define string_int stoi
#define mn(v) *min_element(v.begin(), v.end())
#define mx(v) *max_element(v.begin(), v.end())
#define index_character s.find('character')
#define countxchar count(s.begin(), s.end(), 'x')
#define index_ofX_vector find(v.begin(), v.end(), x) - v.begin()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define n1 cout << "-1" << endl
#define sorted is_sorted(v.begin(), v.end())
#define nl << endl
#define sp << " "
#define mp make_pair
#define fi first
#define se second
#define Mx LLONG_MAX
#define Mn LLONG_MIN
#define mod %1000000007
const ll N = 2e5+5;
// freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
// BesidesDuplicateCharacterEraseInString s.erase(unique(s.begin(), s.end()), s.end());
// Upper/lower-> transform(s.begin(), s.end(), s.begin(), ::toupper/tolower);
using namespace std;
ll i, j, k, n, m;
const ll e=1e+9;
bool comp(pair<long double,ll> a,pair<long double,ll> b){
    if(a.fi==b.fi) return (a.se<b.se); return (a.fi>b.fi);}
// Don't get stuck on a single approach for long, think of multiple ways
// You will destroy your dream if you stay in your comfort zone
// **********************|| Main Code ||********************************
//

int main()
{ 
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    ll test = 1;
    // cin >> test;    
    again:  
    while (test--)
    {         
        ll n,total=0,start=Mx;
        cin>>n;
        vector<pair<ll,pair<ll,ll>>> v;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,
        greater<pair<ll,ll>>> pq;

        for(i=1;i<=n;i++){
            ll x,y;
            cin>>x>>y; v.pb({x,{y,i}});
            start=min(start,x);
        }
        ll ct=start,count=0;     
        while(1) {          
            for(j=0;j<n;j++){
                if(v[j].fi>-1 and v[j].fi<=ct){
                    pq.push({v[j].se.fi,v[j].se.se});
                    v[j].fi=-1;            
                }               
            }     
            cout << ct sp;
            if(pq.empty()) { cout << "- ",ct++;continue; }    
            ll bt=pq.top().fi,p=pq.top().se;            
            cout  << "P" << p sp;
            ct+=bt;          
            pq.pop(),count++;
            if(count==n) break;         
        }      
        cout << ct nl; 
    }       
}
