// 1291. Sequential Digits
// An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
// Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

// Example 1:
// Input: low = 100, high = 300
// Output: [123,234]

// Example 2:
// Input: low = 1000, high = 13000
// Output: [1234,2345,3456,4567,5678,6789,12345]
// Constraints:

// 10 <= low <= high <= 10^9

// Solution
class Solution {
public:
    void dfs(int low,int high,int i,int num,vector<int> &ans){
        if(num>=low && num<=high){
            ans.push_back(num);
        }
        if(num>high || i>9){
            return ;
        }
        if(i==6){
            cout<<num<<endl;
        }
        dfs(low,high,i+1,num*10+i,ans);
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
            dfs(low,high,i,0,ans);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
