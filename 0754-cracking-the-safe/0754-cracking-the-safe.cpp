class Solution {
public:

bool dfs(unordered_set<string> &us, const int &totalPassword, const int n,
            const int k, string &cur){
    if(cur.size()>=n){
        if(us.find(cur.substr(cur.size()-n, cur.size()))!=us.end()){
            return false;
        }else{
            us.insert(cur.substr(cur.size()-n, cur.size()));
        }
    }
    if(us.size()==totalPassword){
        return true;
    }
    for(int i=0; i<k; i++){
        cur.push_back(i+'0');
        if(dfs(us, totalPassword, n, k, cur)){
            return true;
        }
        cur.pop_back();
    }
    if(cur.size()>=n){
        us.erase(cur.substr(cur.size()-n, cur.size()));
    }
    return false;
}
string crackSafe(int n, int k) {
    string cur="";
    int totalPassword = pow(k,n);
    unordered_set<string> us;
    dfs(us, totalPassword, n, k, cur);
    return cur;
}

};