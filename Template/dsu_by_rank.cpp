class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); // Path Compression
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        // Union by Rank
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};