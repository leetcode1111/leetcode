class Solution {
public:
bool isStrobogrammatic(const string &num) {
    int n=num.length();
    unordered_map<char, char> um;
    um['0']='0';
    um['1']='1';
    um['6']='9';
    um['8']='8';
    um['9']='6';
    if(n%2!=0){
        if(!(num[n/2]=='0' || num[n/2]=='1' || num[n/2]=='8')){
            return false;
        }
    }
    for(int i=0; i<(n/2); i++){
        if(um[num[i]]!=num[n-1-i]){
            return false;
        }
    }
    return true;
}

};