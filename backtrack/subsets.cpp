class Solution {
public:
    set<vector<int>> ss;
    void make_subset(vector<int> nums, vector<int> cur, int i){
        if(i==nums.size()){
            ss.insert(cur);
            return;
        }

        make_subset(nums,cur, i+1);
        cur.push_back(nums[i]);
        make_subset(nums, cur, i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        make_subset(nums, tmp, 0);
        vector<vector<int>> ans;
        for(auto i:ss){
            ans.push_back(i);
        }
        return ans;
    }
};