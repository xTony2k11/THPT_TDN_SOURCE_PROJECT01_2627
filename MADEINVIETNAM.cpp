#include <bits/stdc++.h>
#define ll long long
#define NAME "MADEINVIETNAM"
using namespace std;

struct DSU{
    vector<int> parent, sz;
    DSU(int N){
        parent.resize(N + 1);
        sz.resize(N + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int found(int u){
        if(parent[u] == u) return u;
        return parent[u] = found(parent[u]);
    }
    bool unite(int u, int v){
        u = found(u);
        v = found(v);
        if(u == v) return false;
        if(sz[u] < sz[v])
            swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

struct Edge{
    int u, v;
    ll w;
    bool operator <(const Edge &other)const{
        return w < other.w;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    FILE *in = fopen(NAME".INP", "r");
    if(in != NULL){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
        fclose(in);
    }
    int N, K, M;
    cin >> N >> K >> M;
    DSU dsu(N);
    ll ans = 0;
    int components = N;
    if(components == 1){
        cout << 0;
        return 0;
    }
    for(int i = 0; i < K; ++i){
        int u, v;
        cin >> u >> v;
        if(dsu.unite(u, v))
            --components;
    }
    vector<Edge> edges;
    for(int i = 0; i < M; ++i){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    sort(edges.begin(), edges.end());
    for(const Edge& e : edges){
        if(dsu.unite(e.u, e.v)){
            ans += e.w;
            --components;
            if(components == 1){
                cout << ans;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}
