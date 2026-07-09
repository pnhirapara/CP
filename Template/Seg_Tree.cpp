#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <pn_logger.h>
/* https://pastebin.com/ZJv9HqFh */
#else
#define logger(x...) /* DEBUG */
#define debug(x)     /* DEBUG */
#endif

// TYPES
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
#define maxpq(T) priority_queue<T>
#define minpq(T) priority_queue<T, vector<T>, greater<T>>
#define endl '\n'

// CONSTANTS
const lld pi = 3.141592653589793238;
const ll INF = 1e9;
const ll inf = 1e18;

// Comparators (ascending and descending by second)
auto sorta = [](auto &a, auto &b){ return a.second < b.second; };
auto sortd = [](auto &a, auto &b){ return a.second > b.second; };
vector<pair<ll, ll>> pair_sort_wrt_second(vector<pair<ll, ll>>v){
    sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });
    return v;
}
void printbinary(ll n){
    for(int i=6;i>=0;i--){
        cout << ((n>>i) & 1);
    }
    cout << endl; 
}
vector<ll> SegTree;
void build(ll start,ll end,ll index,vector<ll>&v){// O(n)
    if(start==end){
        SegTree[index]=v[start];
        return;
    }
    ll leftchild=2*index;
    ll rightchild=(2*index) + 1;
    ll mid=(start + end)/2;

    build(start,mid,leftchild,v);
    build(mid+1,end,rightchild,v);

    SegTree[index]=SegTree[leftchild] + SegTree[rightchild]; 
    return;


}
void update(ll start,ll end,ll index,ll pos,ll val,vector<ll>&v){// logn
    if(start==end){
        v[pos]=val;
        SegTree[index]=v[pos];
        return;
    }
    ll mid=(start+end)/2;
    if(pos<=mid){
        update(start,mid,2*index,pos,val,v);
    }
    else{
        update(mid+1,end,2*index + 1, pos ,val , v);
    }
    SegTree[index]=SegTree[2*index] + SegTree[2*index + 1];
}
ll query(ll l,ll r,ll start,ll end, ll index){//logn
    ll mid=(start + end) /2 ;
    // complete overlap
    if(l<=start && end<=r){
        return SegTree[index];
    }
    // disjoint
    if(r<start || l>end){
        return 0;
    }
    // partially overlap
    ll leftAnswer=query(l,r,start,mid,2*index);
    ll rightAnswer=query(l,r,mid+1,end,(2*index) + 1);
    return leftAnswer+rightAnswer;

}
void solve()
{
    ll n;
    cin >> n;
    SegTree.assign(2*n,0);
    vector<ll>v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    build(0,n-1,1,v);
    logger(SegTree);
    update(0,n-1,1,2,3,v);
    cout << query(2,4,0,n-1,1);
}

int main()
{
    #ifdef LOCAL
        freopen("/Users/preethirapara/Documents/cp_sublime/input.txt", "r", stdin);
        freopen("/Users/preethirapara/Documents/cp_sublime/output.txt", "w", stdout);
        freopen("/Users/preethirapara/Documents/cp_sublime/error.txt", "w", stderr);
    #endif

    // ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    // std::cin.ignore(); // must be there when using getline(std::cin, s)

    int64_t tc = 1;
    std::cin >> tc;
    while (tc--){
        solve();
    }
    return 0;
}
