class Solution {
public:
int minMeetingRooms(vector<vector<int>>& intervals) {
    vector<pair<int,int>> arr;
    // 
    //  
    for(int i=0; i<intervals.size(); i++){
        arr.push_back({intervals[i][0], 1});
        arr.push_back({intervals[i][1], -1});
    }
    sort(arr.begin(), arr.end());
    int ans=0, cur=0;
    for(int i=0; i<2*intervals.size(); i++){
        cur+=arr[i].second;
        ans=max(ans,cur);
    }
    return ans;
}
};