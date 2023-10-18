struct Trie{
    Trie* arr[26];
    // vector<Trie*> arr;
    vector<const string *> startsWith;
    Trie(){
        for(int i=0; i<26; i++){
            arr[i] = NULL;
        }
        // arr.resize(26, NULL);
    }
};

class TrieDs{
    Trie *root;
public:
    TrieDs(vector<string> &arr){
        root = new Trie();
        for(int i=0; i<arr.size(); i++){
            insert(arr[i]);
        }
    }
    void insert(const string &key){
        Trie *cur=root;
        for(int i=0; i<key.size(); i++){
            int ind = key[i] - 'a';
            if(cur->arr[ind] == NULL){
                cur->arr[ind] = new Trie();
            }
            cur = cur->arr[ind];
            cur->startsWith.push_back(&key);
        }
    }

    vector<const string *> searchAllPrefix(const string &key){
        vector<string> res;
        Trie *cur=root;
        for(int i=0; i<key.size(); i++){
            int ind = key[i] - 'a';
            if(cur->arr[ind] == NULL){
                return {};
            }
            cur = cur->arr[ind];
        }
        return cur->startsWith;
    }
};

void dfs(TrieDs &ds, vector<vector<string>> &res, vector<string> &cur){
    if(cur.size() == cur[0].size()){
        res.push_back(cur);
        return;
    }
    
    string prefix = "";
    int ind = cur.size();
    for(const string &w:cur){
        prefix.push_back(w[ind]);
    }

    vector<const string *> wordList = ds.searchAllPrefix(prefix);
    
    for(const string *s: wordList){
        cur.push_back((*s));
        dfs(ds, res, cur);
        cur.pop_back();
    }

}
class Solution {
public:
vector<vector<string>> wordSquares(vector<string>& words) {
    vector<vector<string>> res;
    TrieDs ds(words);
    vector<string> cur;
    for(int i=0; i<words.size(); i++){
        cur.push_back(words[i]);
        dfs(ds, res, cur);
        cur.pop_back();
    }
    return res;
}
};