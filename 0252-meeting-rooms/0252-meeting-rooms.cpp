class Solution {
public:
static bool mycomp(const vector<int> &v1, const vector<int> &v2){
    return v1[1]<v2[1];
}
bool canAttendMeetings(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), mycomp);
    for(int i=1; i<intervals.size(); i++){
        if(intervals[i-1][1]>intervals[i][0]){
            return false;
        }
    }
    return true;
}

};