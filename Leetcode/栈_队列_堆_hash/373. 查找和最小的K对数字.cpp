// https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums/
// 373. 查找和最小的K对数字
// 给定两个以升序排列的整形数组 nums1 和 nums2, 以及一个整数 k。

// 定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2。

// 找到和最小的 k 对数字 (u1,v1), (u2,v2) ... (uk,vk)。

// 示例 1:

// 输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// 输出: [1,2],[1,4],[1,6]
// 解释: 返回序列中的前 3 对数：
//      [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
// 示例 2:

// 输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
// 输出: [1,1],[1,1]
// 解释: 返回序列中的前 2 对数：
//      [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
// 示例 3:

// 输入: nums1 = [1,2], nums2 = [3], k = 3 
// 输出: [1,3],[2,3]
// 解释: 也可能序列中所有的数对都被返回:[1,3],[2,3]

// 暴力解法： 大顶堆插入
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        using entry = pair<int, vector<int>>;
        auto cmp = [](entry a, entry b){ return a.first < b.first;};
        priority_queue<entry, vector<entry>, decltype(cmp)> pq(cmp);
        int sum = 0;
        vector<int> tmp(2, -1);
        for (int i = 0; i < nums1.size(); i++) {
            tmp[0] = nums1[i];
            sum = nums1[i];
            for (int j = 0; j < nums2.size(); j++) {
                tmp[1] = nums2[j];
                sum = tmp[0] + tmp[1];
                if (pq.size() < k) {
                    pq.push(entry(sum,tmp));
                } else {
                    if (sum < pq.top().first) {
                        pq.push(entry(sum,tmp));
                        pq.pop();
                    } 
                }
            }
        }

        vector<vector<int>> ret;
        while(!pq.empty()) {
            ret.emplace_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};