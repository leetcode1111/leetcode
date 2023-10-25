class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, 
        int lower, int upper) {
        int n=nums.size();
        if(n==0){
            return {{lower, upper}};
        }
        vector<vector<int>> res;
        if(nums[0]-lower!=0){
            res.push_back({{lower, nums[0]-1}});
        }

        for(int i=1; i<n; i++){
            if(nums[i]-nums[i-1]>=2){
                res.push_back({nums[i-1]+1, nums[i]-1});
            }
        }

        if(upper-nums[n-1]!=0){
            res.push_back({{nums[n-1]+1, upper}});
        }
                
        return res;
    }
};