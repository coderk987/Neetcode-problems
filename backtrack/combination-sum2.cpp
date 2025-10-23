class Solution {
public:
    set<vector<int>> res;

    void make_sub(vector<int> &cd, int target,vector<int> &cur, int i, int sum){
        if(i>=cd.size() || sum >= target){
            if(target==sum) res.insert(cur);
            return;
        }
        cur.push_back(cd[i]);
        make_sub(cd,target,cur,i+1,sum+cd[i]);
        cur.pop_back();
        make_sub(cd,target,cur,i+1,sum);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        make_sub(candidates, target, tmp, 0, 0);
        /*vector<vector<int>> ans;
        for(auto i:res){
            ans.push_back(i);
        }*/
        return vector<vector<int>>(res.begin(), res.end());
    }
};