// struct Trie{
//     // storing 26 english alphabets
//     vector<Trie*> arr;
//     // for storing address of all words with proper prefix
//     vector<const string *> startsWith;
//     Trie(){
//         arr.resize(26, NULL);
//     }
// };

// class TrieDs{
//     Trie *root;
// public:
//     TrieDs(vector<string> &arr){
//         root = new Trie();
//         for(int i=0; i<arr.size(); i++){
//             insert(arr[i]);
//         }
//     }
//     void insert(const string &key){
//         Trie *cur=root;
//         for(int i=0; i<key.size(); i++){
//             int ind = key[i] - 'a';
//             if(cur->arr[ind] == NULL){
//                 cur->arr[ind] = new Trie();
//             }
//             cur = cur->arr[ind];
//             // storing address of full word which start from 
//             cur->startsWith.push_back(&key);
//         }
//     }
//     vector<const string *> searchAllPrefix(const string &key){
//         vector<string> res;
//         Trie *cur=root;
//         for(int i=0; i<key.size(); i++){
//             int ind = key[i] - 'a';
//             if(cur->arr[ind] == NULL){
//                 return {};
//             }
//             cur = cur->arr[ind];
//         }
//         return cur->startsWith;
//     }
// };

// void dfs(TrieDs &ds, vector<vector<string>> &res, vector<string> &cur){
//     // base case if cur size is equal to max size return
//     if(cur.size() == cur[0].size()){
//         res.push_back(cur);
//         return;
//     }
    
//     // obtaing prefix for current allotment
//     string prefix = "";
//     int ind = cur.size();
//     for(const string &w:cur){
//         prefix.push_back(w[ind]);
//     }

//     // obtaining address of all words starts from prefix
//     vector<const string *> wordList = ds.searchAllPrefix(prefix);
    
//     // iterating and backtracking for every word
//     for(const string *s: wordList){
//         cur.push_back((*s));
//         dfs(ds, res, cur);
//         cur.pop_back();
//     }

// }

// vector<vector<string>> myWordSquares(vector<string>& words){
//     vector<vector<string>> res;
//     TrieDs ds(words);
//     vector<string> cur;

//     // consider every word as starting point one by one
//     for(int i=0; i<words.size(); i++){
//         cur.push_back(words[i]);
//         dfs(ds, res, cur);
//         cur.pop_back();
//     }
//     return res;
// }

void dfs(unordered_map<string, vector<int>> &um, vector<string>& words, vector<vector<string>> &res, vector<string> &cur){
    // base case if cur size is equal to max size return
    if(cur.size() == cur[0].size()){
        res.push_back(cur);
        return;
    }
    
    // obtaing prefix for current allotment
    string prefix = "";
    int ind = cur.size();
    for(const string &w:cur){
        prefix.push_back(w[ind]);
    }

    // obtaining indexes of all words starts from prefix
    vector<int> wordList = um[prefix];
    
    // iterating and backtracking for every word
    for(int i: wordList){
        cur.push_back(words[i]);
        dfs(um, words, res, cur);
        cur.pop_back();
    }

}

vector<vector<string>> myWordSquares(vector<string>& words){
    unordered_map<string, vector<int>> um;
    for(int i=0; i<words.size(); i++){
        string s="";
        for(int j=0; j<words[i].size(); j++){
            s.push_back(words[i][j]);
            um[s].push_back(i);
        }
    }
    vector<vector<string>> res;
    vector<string> cur;

    // consider every word as starting point one by one
    for(int i=0; i<words.size(); i++){
        cur.push_back(words[i]);
        dfs(um, words, res, cur);
        cur.pop_back();
    }
    return res;
}


class Solution {
public:
vector<vector<string>> wordSquares(vector<string>& words) {
    return myWordSquares(words);
}
};