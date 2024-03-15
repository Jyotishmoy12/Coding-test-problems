You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)


class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
    int mod=1e9+7;
    int n=nums.size();
    int ans=0;
    sort(nums.begin(), nums.end());
    int left=0;
    int right=n-1;
    //calculate power vector for example in this test case-->
    // [3,5,6,7] in first iteration nums[left]+nums[right]=10>9 so move the right pointer hence it will be now at 6 and left will be at 3
    // now nums[left]+nums[right]=9-> equals to the target so the range in which the answer lies is [3-->6]-> so in 3 to 6 there are 4 subsequnces which [3], [3,5],[3,6],[3,5,6] -> so that's why we need power
    vector<int>pow(n,1);
    for(int i=1;i<n;i++){
        pow[i]=pow[i-1]*2%mod;
    }
    while(left<=right){
        if(nums[left]+nums[right]>target){
            right--;
        }
        else{
              ans=(ans+(pow[right-left]%mod))%mod;
              left++;
        }
    } 
    return ans%mod;   
    }
};
