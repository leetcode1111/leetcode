class Solution {
public:
vector<string> findStrobogrammatic(int n, bool isOuterMost=true) {
    if(n==0){
        return {""};
    }
    if(n==1){
        return {"0","1","8"};
    }
    
    vector<string> prevRes = findStrobogrammatic(n-2, false);
    vector<string> res;
    for(const string &str:prevRes){
        if(!isOuterMost){
            res.push_back("0"+str+"0");
        }
        res.push_back("1"+str+"1");
        res.push_back("8"+str+"8");
        res.push_back("6"+str+"9");
        res.push_back("9"+str+"6");
    }
    return res;
}

};