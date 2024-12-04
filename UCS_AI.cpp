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
#define point cout << fixed << setprecision(10)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define n1 cout << "-1" << endl
#define ok cout << "ok" nl
#define sorted is_sorted(v.begin(), v.end())
#define nl << endl
#define sp << " "
#define mp make_pair
#define fi first
#define se second
#define Mx LLONG_MAX
#define Mn LLONG_MIN
#define mod %1000000007
// ordered_set
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
// bitsize-> ll size=log2(n)+1 (last set bit=size-1;/ /Last bit->__lg(value); )
// first bit-> name._Find_First()
// next bit after x-> name._Find_next()
// freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
// BesidesDuplicateCharacterEraseInString s.erase(unique(s.begin(), s.end()), s.end());
// Upper/lower-> transform(s.begin(), s.end(), s.begin(), ::toupper/tolower);
using namespace std;
ll i, j, k, n, m;
const ll N = 2e7+5;
const ll e=1e9;
const double pi=acos(-1);
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    if(a.fi==b.fi) return (a.se>b.se); return (a.fi>b.fi);}

//
// Don't get stuck on a single approach for long, think of multiple ways
// You will destroy your dream if you stay in your comfort zone
// **********************|| Main Code ||********************************
//
// vector<int> parent(10);
// int find(int node){
//     int p=parent[node];
//     if(node!=p){
//         parent[node]=find(parent[node]);
//     }
//     return parent[node];
// }
 
int main()
{ 
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    // point;
    ll test = 1; 
    // cin >> test;    
    again: 
    while (test--)
    {   
        ll node,edge;
        cin>>node>>edge;
        map<pair<char,char>,ll> edge_edge_cost;
        map<char,ll> node_cost;
        map<char,vector<char>> connected;
        for(i=0;i<edge;i++){
            char x,y; ll cost;
            cin>>x>>y>>cost;
            if(x>y) swap(x,y);
            edge_edge_cost[{x,y}]=cost;
            connected[x].pb(y);
            connected[y].pb(x);
            node_cost[x]=Mx;
            node_cost[y]=Mx;
        }
        char start,goal;
        cin>>start>>goal;    
        set<pair<ll,char>> pq;
        map<char,ll> visited;
        pq.insert({0,start});
        while(pq.size()){
            char parent=pq.begin()->se;
            if(parent==goal) break;
            ll valu=pq.begin()->fi;
            visited[parent]=1;
            pq.erase(pq.begin());
            for(auto child: connected[parent]){
                if(visited[child]) continue;
                char x=parent,y=child;
                if(x>y) swap(x,y);
                ll valu_now=valu+edge_edge_cost[{x,y}];
                if(valu_now<node_cost[child]){
                    node_cost[child]=valu_now;
                    pq.erase({node_cost[child],child});
                    pq.insert({valu_now,child});
                }
            }
        }
        cout << node_cost[goal] nl;
    }
}
