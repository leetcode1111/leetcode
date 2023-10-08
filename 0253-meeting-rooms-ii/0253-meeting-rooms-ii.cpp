class Solution {
public:
// int minMeetingRooms(vector<vector<int>>& intervals) {
//     vector<pair<int,int>> arr;
//     for(int i=0; i<intervals.size(); i++){
//         arr.push_back({intervals[i][0], 1});
//         arr.push_back({intervals[i][1], -1});
//     }
//     sort(arr.begin(), arr.end());
//     int ans=0, cur=0;
//     for(int i=0; i<2*intervals.size(); i++){
//         cur+=arr[i].second;
//         ans=max(ans,cur);
//     }
//     return ans;
// }
int minMeetingRooms(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int ans=1;
    pq.push({intervals[0][1], intervals[0][0]}); // (end time, start time);
    for(int i=1; i<intervals.size(); i++){
        if(pq.top().first <= intervals[i][0]){
            pq.pop();
        }
        pq.push({intervals[i][1], intervals[i][0]});
        ans=max(ans, (int)pq.size());
    }
    return ans;
}
};