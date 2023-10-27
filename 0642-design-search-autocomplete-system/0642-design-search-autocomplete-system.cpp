class AutocompleteSystem {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> leaves;
        // Stores the index of hot sentence
        vector<int> suggestions;
    };
    // Tracks the root of trie
    TrieNode* root_ = nullptr;
    // Trie iterator for a given query
    TrieNode* curr = nullptr;
    string prefix;
    const int TOP_K = 3;
    
    // Hot sentences 
    vector<string> sentences;
    // freq[i] = Frequency of ith hot sentence
    vector<int> freq;
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        // Root of trie
        root_ = new TrieNode();
        // Set the query iterator to the trie root
        curr = root_;
        // Save the initial list of sentences and their frequencies
        this->sentences = sentences;
        this->freq = times;
        
        for(int idx = 0; idx < sentences.size(); idx++) 
            insert(sentences[idx], idx);
    }
    
    void insert(string str, int idx) {
        // Trie Iterator 
        TrieNode* root = root_;
        
        // Add the word char by char
        for(char ch: str) {
            if(root->leaves.count(ch) == 0)
                root->leaves[ch] = new TrieNode();
            root = root->leaves[ch];
            
            // Check if the new string already exists in the hot sentences or not, if not add
            if(find(root->suggestions.begin(), root->suggestions.end(), idx) == root->suggestions.end())
                root->suggestions.push_back(idx);
            
            // Now sort the hot sentences based on the comparison metric
            sort(root->suggestions.begin(), root->suggestions.end(), [this](int idx1, int idx2) -> bool {
                if(freq[idx1] == freq[idx2]) 
                    return sentences[idx1] < sentences[idx2];
                return freq[idx1] > freq[idx2];
            });
            
            // Now if we have more than k suggestions, remove the extra
            if(root->suggestions.size() > TOP_K)
                root->suggestions.pop_back();
                
            
        }
    }    
    
    vector<string> search(char ch) {
        vector<string> suggestions;
        // Check if the trie iterator is not null and 
        // current char exists as well
        if(curr && curr->leaves.count(ch)) {
            curr = curr->leaves[ch];
            for(auto idx: curr->suggestions)
                suggestions.push_back(sentences[idx]);
        }
        // Current char doesn't exist, so there won't be any match for this
        // query onwards. So set the iterator to null
        else
            curr = nullptr;
        return suggestions;
    }
    
    vector<string> input(char c) {
        // End of query
        if(c == '#') {
            // Add the prefix to Trie
            // Check if the prefix is already added or not
            auto it = find(sentences.begin(), sentences.end(), prefix);
            // New sentence found, update its frequency
            if(it == sentences.end()) {
                sentences.push_back(prefix);
                freq.push_back(1);
                insert(prefix, sentences.size()-1);
            }
            // The prefix already exists
            else {
                int idx = it - sentences.begin();
                freq[idx] += 1;
                insert(prefix, idx);
            }
                
            // Now that query has ended, reset current iterator and query prefix
            curr = root_;
            prefix.clear();
            
            return vector<string>{};
        }
        // Add the current char to the ongoing query prefix
        prefix += c;
        // Get the suggestions for the prefix ending at current char
        return search(c);
    }
};
