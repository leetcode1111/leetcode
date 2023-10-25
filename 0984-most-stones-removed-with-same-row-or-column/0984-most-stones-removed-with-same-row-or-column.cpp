class DSU{
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n){
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
        rank.resize(n,0);
        size.resize(n,1);
    }
    int ultimateParent(int x){
        if(parent[x]==x){
            return x;
        }
        parent[x] = ultimateParent(parent[x]);
        return parent[x];
    }
    void unionByRank(int a, int b){
        int ulpa = ultimateParent(a);
        int ulpb = ultimateParent(b);
        if(ulpa==ulpb){
            return;
        }
        if(rank[ulpa]<rank[ulpb]){
            parent[ulpa] = ulpb;
        }else if(rank[ulpa]>rank[ulpb]){
            parent[ulpb] = ulpa;
        }else{
            parent[ulpb] = ulpa;
            rank[ulpa]++;
        }
    }
    void unionBySize(int a, int b){
        int ulpa = ultimateParent(a);
        int ulpb = ultimateParent(b);
        if(ulpa==ulpb){
            return;
        }
        if(size[ulpa]<size[ulpb]){
            parent[ulpa] = ulpb;
            size[ulpb]+=size[ulpa];
        }else{
            parent[ulpb] = ulpa;
            size[ulpa]+=size[ulpb];
        }
    }

};  

class Solution {
public:
int removeStones(vector<vector<int>>& stones) {
    int n=0, m=0;
    for(int i=0; i<stones.size(); i++){
        n = max(n, stones[i][0]);
        m = max(m, stones[i][1]);
    }
    n++; m++;
    DSU ds(n+m);

    for(int i=0; i<stones.size(); i++){
        int u = stones[i][0];
        int v = n+stones[i][1];
        ds.unionByRank(u, v);
    }
    unordered_set<int> us;
    for(int i=0; i<stones.size(); i++){
        int u = stones[i][0];
        int v = n+stones[i][1];
        us.insert(ds.ultimateParent(u));
        us.insert(ds.ultimateParent(v));
    }
    return stones.size() - us.size();
}
};
