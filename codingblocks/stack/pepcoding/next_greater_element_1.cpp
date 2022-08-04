//https://leetcode.com/problems/next-greater-element-i/


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        map<int, int> m;

        //stack ops to find greatest in right
        //when poping insert into map : poped element and its first greater right

        for (int i = 0; i < nums2.size(); i++) {
            if (st.empty())
                st.push(nums2[i]);
            else {
                while (!st.empty() and st.top() < nums2[i]) {
                    m[st.top()] = nums2[i];
                    st.pop();
                }
                st.push(nums2[i]);
            }
        }
        //pop remaining elements left in stack and -1 for them

        while (!st.empty()) {
            m[st.top()] = -1;
            st.pop();
        }

        //check great right for each element in nums1 from map

        for (int i = 0; i < nums1.size(); i++) {
            nums1[i] = m[nums1[i]];
        }

        return nums1;
    }
};