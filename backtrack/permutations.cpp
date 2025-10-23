class Solution {
public:
    vector<vector<int>> res;

    void create(vector<int> &nums, vector<int> &cur, vector<bool> &done){
        if(cur.size()==nums.size()){
            res.push_back(cur);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!done[i]){
                cur.push_back(nums[i]);
                done[i]=true;
                create(nums, cur, done);
                cur.pop_back();
                done[i]=false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> done(nums.size(),0);
        vector<int> cur;
        create(nums, cur, done);
        return res;
    }
};