
const ll N=1e5+10;
vector<ll>PARENT(N);
vector<ll>SIZE(N);
void make(ll v){
    PARENT[v]=v;
    SIZE[v]=1;
}
ll find(ll v){
    if(PARENT[v]==v){
        return v;
    }
    // path compression
    return PARENT[v]=find(PARENT[v]);
}
void Union(ll a,ll b){
    a = find(a);
    b = find(b);
    if(a!=b){
        // Union by size (or we can also do By Rank)
        if(a<b){
            swap(a,b);
        }
        PARENT[b]=a;
        SIZE[a]+=SIZE[b];
    }

}
