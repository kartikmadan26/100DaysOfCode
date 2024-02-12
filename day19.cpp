// Question
// 169. Majority Element
// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Example 1:
// Input: nums = [3,2,3]
// Output: 3

// Example 2:
// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

// Constraints:
// n == nums.length
// 1 <= n <= 5 * 104
// -109 <= nums[i] <= 109
// Solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int ele=nums[0];
        for(int i=0;i<n;i++){
            if(count==0){
                ele=nums[i];
            }
            if(ele==nums[i]){
                count++;
            }
            else if(ele!=nums[i]){
                count--;
            }
        }
        return ele;
    }
};
