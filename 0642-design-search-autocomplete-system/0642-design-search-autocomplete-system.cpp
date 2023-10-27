struct Node{
    Node * child[128];
    vector<int> suggestion;
    Node(){
        for(int i=0; i<128; i++){
            child[i]=NULL;
        }
    }
};

class AutocompleteSystem {

    vector<string> sentences;
    vector<int> freq;
    string prefix;
    Node *root;
    Node *cur;
    const int TOP_K = 3;

public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        this->sentences = sentences;
        this->freq = times;
        prefix = "";
        root = new Node();
        cur = root;
        for(int i=0; i<sentences.size(); i++){
            insert(sentences[i], i);
        }
    }
    vector<string> input(char c) {
        if(c=='#'){
            auto it = find(sentences.begin(), sentences.end(), prefix);
            if(it==sentences.end()){
                sentences.push_back(prefix);
                freq.push_back(1);
                insert(prefix, sentences.size()-1);
            }else{
                int ind = it-sentences.begin();
                freq[ind]++;
                insert(prefix, ind);
            }
            prefix = "";
            cur=root;
            return {};
        }
        prefix.push_back(c);
        return search(c);
    }
    void insert(string &sentence, int ind){
        Node *temp=root;
        for(const char &c:sentence){
            if(temp->child[c]==NULL){
                temp->child[c] = new Node();
            }
            temp = temp->child[c];
            // check weather ind already exist if it exist then it means 
            // we call this function for sorting purpose based on freq
            auto it = find(temp->suggestion.begin(), temp->suggestion.end(), ind);
            if(it == temp->suggestion.end()){
                temp->suggestion.push_back(ind);
            }
            sort(temp->suggestion.begin(), temp->suggestion.end(), 
                    [this](int ind1, int ind2) -> bool {
                        if(freq[ind1]==freq[ind2]){
                            return sentences[ind1] < sentences[ind2]; 
                        }
                        return  freq[ind1] > freq[ind2];
            });
            if(temp->suggestion.size() > TOP_K){
                temp->suggestion.pop_back();
            }
        }
    }
    vector<string> search(char c){
        vector<string> res;
        if(cur!=NULL && cur->child[c]!=NULL){
            cur = cur->child[c];
            for(int ind:cur->suggestion){
                res.push_back(sentences[ind]);
            }
        }else{
            cur=NULL;
        }
        return res;
    }
};