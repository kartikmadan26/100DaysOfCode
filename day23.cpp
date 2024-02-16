// Question
// 1481. Least Number of Unique Integers after K Removals
// Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

// Example 1:
// Input: arr = [5,5,4], k = 1
// Output: 1
// Explanation: Remove the single 4, only 5 is left.

// Example 2:
// Input: arr = [4,3,1,1,3,3,2], k = 3
// Output: 2
// Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
 
// Constraints:
// 1 <= arr.length <= 10^5
// 1 <= arr[i] <= 10^9
// 0 <= k <= arr.length
// Solution
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (auto i : arr) {
            mp[i]++;
        }
        int n = mp.size();
        vector<pair<int, int>> temp(n);
        int j = 0;
        for (auto i : mp) {
            temp[j].first = i.second;
            temp[j].second = i.first;
            j++;
        }

        sort(temp.begin(), temp.end());

        j = 0;
        int ans = temp.size();
        while (k > 0) {
            while (temp[j].first > 0 && k > 0) {
                temp[j].first--;
                k--;
            }
            if (temp[j].first == 0) {
                j++;
                ans--;
            }
        }
        return ans;
    }
};
