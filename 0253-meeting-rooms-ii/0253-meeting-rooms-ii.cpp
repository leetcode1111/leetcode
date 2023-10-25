class Solution {
public:
int minMeetingRooms(vector<vector<int>>& intervals) {
    map<int,int> mp;
    for(const vector<int> &interval:intervals){
        mp[interval[0]]++;
        mp[interval[1]]--;
    }
    int res=0, c=0;
    for(const pair<int,int> &p:mp){
        c+=p.second;
        res=max(res,c);
    }
    return res;
}

};