// User function Template for C++
class Solution {
  public:
class DSU{
    private:
        vector<int> parent, rank, size;
    public:
        DSU(int n){
            parent.resize(n);
            for(int i=0; i<n; i++){
                parent[i]=i;
            }
            rank.resize(n, 0);
            size.resize(n, 1);
        }
        int findUltimateParent(int node){
            if(parent[node] == node){
                return node;
            }
            parent[node] = findUltimateParent(parent[node]);
            return parent[node];
        }
        void unionByRank(int u, int v){
            int u_ulp = findUltimateParent(u);
            int v_ulp = findUltimateParent(v);
            if(u_ulp == v_ulp){
                return;
            }
            if(rank[u_ulp] > rank[v_ulp]){
                parent[v_ulp] = u_ulp;
            }else if(rank[u_ulp] < rank[v_ulp]){
                parent[u_ulp] = v_ulp;
            }else{// rank[u_ulp] == rank[v_ulp (here we can take any)
                parent[u_ulp] = v_ulp;
                rank[v_ulp]++;
            }
        }
        void unionBySize(int u, int v){
            int u_ulp = findUltimateParent(u);
            int v_ulp = findUltimateParent(v);
            if(u_ulp == v_ulp){
                return;
            }
            if(size[u_ulp] > size[v_ulp]){
                parent[v_ulp] = u_ulp;
                size[u_ulp]+=size[v_ulp];
            }else{ //(size[u_ulp] < size[v_ulp])
            // size[u_ulp] == size[v_ulp (here we can take any)
                parent[u_ulp] = v_ulp;
                size[v_ulp]+=size[u_ulp];
            }
        }
};

int encode(int i, int j, int colSize){
    return (i*colSize) + j; 
}

vector<int> numIslands2(int n, int m, vector<vector<int>> &querry) {
    vector<vector<bool>> grid(n, vector<bool>(m, false));
    int ar[4] = {0,0,1,-1};
    int ac[4] = {1,-1,0,0};
    DSU ds(n*m);
    vector<int> res(querry.size());
    int count = 0;
    for(int q=0; q<querry.size(); q++){
        int i = querry[q][0];
        int j = querry[q][1];
        if(grid[i][j] == true){
            res[q] = count;
            continue;
        }
        grid[i][j] = true;
        count++;
        int u = encode(i, j, m);
        for(int k=0; k<4; k++){
            int fi = i+ar[k];
            int fj = j+ac[k];
            if(fi>=0 && fj>=0 && fi<n && fj<m && grid[fi][fj]==true){
                int v = encode(fi, fj, m);
                if(ds.findUltimateParent(u)!=ds.findUltimateParent(v)){
                    count--;
                    ds.unionByRank(u,v);
                }
            }
        }
        res[q] = count;
    }
    return res;
}

};