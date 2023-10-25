class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(const string &s) {
        unordered_map<char,int> um;
        int res=0, cur=0, j=0;
        for(const char &c:s){
            um[c]++;
            cur++;
            while(um.size()>2){
                um[s[j]]--;
                cur--;
                if(um[s[j]]==0){
                    um.erase(s[j]);
                }
                j++;
            }
            res=max(res, cur);
        }
        return res;
    }
};