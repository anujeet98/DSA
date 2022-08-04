//https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k==nums.size())
            return nums;
        map<int,int> freq_count;
        for(int i=0;i<nums.size();i++){
            freq_count[nums[i]]++;
        }
        
        auto comparator = [&freq_count](int a, int b) {
            return freq_count[a] > freq_count[b];
        };
        priority_queue <int, vector<int>, decltype(comparator)> freq_max_heap(comparator);
        
        for(pair <int,int>p:freq_count){
            freq_max_heap.push(p.first);
            if(freq_max_heap.size()>k)
                freq_max_heap.pop();
        }
        
        vector<int> result;
        while(freq_max_heap.size()>0){
            result.push_back(freq_max_heap.top());
            freq_max_heap.pop();
        }
        return result;
    }
};