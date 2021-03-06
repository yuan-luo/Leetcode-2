// https://leetcode-cn.com/problems/subsets-ii/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.empty())
            return ret;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i <= nums.size(); i++) {
            vector<int> path;
            dfs(ret, nums, path, i, 0);
        }

         return ret;
    }


    void dfs(vector<vector<int>> &ret, vector<int>& nums,  vector<int> path, const int len, int start_pos) {
        if (path.size() == len) {
            ret.emplace_back(path);
            return;
        }

        for (int i = start_pos; i < nums.size(); i++) {
            if (i > start_pos && nums[i] == nums[i-1])
                continue;
            path.push_back(nums[i]);
            dfs(ret, nums, path, len, i + 1);
            path.pop_back();
        }
    }
};