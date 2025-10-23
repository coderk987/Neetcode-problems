class Solution {
public:
    vector<vector<int>> res;
    void create(vector<int> &nums, vector<int> &cur,int i){
        if(i==nums.size()){
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);
        create(nums,cur,i+1);
        cur.pop_back();
        int ctr=0;
        while(i+ctr<nums.size() && nums[i+ctr]==nums[i]) ctr++;
        create(nums, cur, i+ctr);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        create(nums,tmp,0);
        return res;
    }
};