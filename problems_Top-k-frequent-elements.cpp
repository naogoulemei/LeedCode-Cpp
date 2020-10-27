//用C++语言和hashmap data structure写的,使用一个最大堆来按照映射次数从大到小排列
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        priority_queue<pair<int,int>>q;
        vector<int> res;
        for(auto a: nums) ++m[a];
        for(auto it :m) q.push({it.second,it.first});
        for(int i=0;i<k;i++)
        {
            res.push_back(q.top().second); q.pop();
        }
        return res;
    }
};
