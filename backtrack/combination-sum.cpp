class Solution {
public:
    vector<vector<int>> res;
    void make_sub(vector<int> &cd, int target, vector<int> &cur,int sum, int i){
        if(sum>=target){
            if(sum==target) res.push_back(cur);
            return;
        }
        for(int j=i;j<cd.size();j++){
            cur.push_back(cd[j]);
            make_sub(cd, target, cur, sum+cd[j],j);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        make_sub(candidates, target, tmp, 0, 0);
        return res;
    }
};