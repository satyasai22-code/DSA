#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent;
    vector<int> rank, size;
    public:
    DisjointSet(int n){
        parent.resize(n);   
        rank.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }
    int findParent(int u){
        if(u == parent[u]){
            return u;
        }
        return parent[u] = findParent(parent[u]);
    }
    void unionByRank(int u, int v){
        int pu = findParent[u];
        int pv = findParent[v];
        if(pu == pv) return;
        int pu_rank = rank[pu], pv_rank = rank[pv];
        if(pu_rank > pv_rank){
            parent[pv] = pu;
        }else if(pv_rank > pu_rank){
            parent[pu] = pv; 
        }else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    void unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return;
        int pv_size = size[pv], pu_size = size[pu];
        if(pv_size < pu_size){
            parent[pv] = pu;
            size[pu] += size[pv];
        }else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};