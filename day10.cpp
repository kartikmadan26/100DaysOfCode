// Question
// 1043. Partition Array for Maximum Sum
// Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.
// Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

// Example 1:
// Input: arr = [1,15,7,9,2,5,10], k = 3
// Output: 84
// Explanation: arr becomes [15,15,15,9,10,10,10]

// Example 2:
// Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
// Output: 83

// Example 3:
// Input: arr = [1], k = 1
// Output: 1

// Constraints:
// 1 <= arr.length <= 500
// 0 <= arr[i] <= 109
// 1 <= k <= arr.length
// Solution
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
         int n = arr.size();
        int* dp = new int[n];
        for(int i=0;i<n;i++){
            dp[i] = -1;
         }
        for(int i = n-1;i>=0;i--){
            int sum = INT_MIN;
            int max_ele = INT_MIN;
            for(int j = i;j<n && j<i+k;j++){
                max_ele = max(max_ele,arr[j]);
                int cand = j+1 < n ? dp[j+1] + max_ele*(j-i+1) : max_ele*(j-i+1); 
                sum = max(sum , cand);
            }
            dp[i] = sum;
        }
        return dp[0];
    }
};
