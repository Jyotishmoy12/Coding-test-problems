Let's break down the problem "Summary Ranges" step by step, explaining the intuition and thought process behind the solution. Then we will provide the code and perform a dry run with a test case.

Problem Explanation:
You are given a sorted array of unique integers, and your task is to summarize consecutive ranges into a compact representation.

A range [a, b] contains all integers from a to b, inclusive. The output format varies:

If a equals b, output "a"
If a does not equal b, output "a->b"
Example Walkthrough:
Example 1:

Input: nums = [0, 1, 2, 4, 5, 7]

Output: ["0->2", "4->5", "7"]

Explanation:

The numbers 0, 1, and 2 are consecutive, forming the range 0->2.
The numbers 4 and 5 are consecutive, forming the range 4->5.
The number 7 stands alone, forming the range 7.
Example 2:

Input: nums = [0, 2, 3, 4, 6, 8, 9]
Output: ["0", "2->4", "6", "8->9"]
Thought Process:
Initialization: Start with an empty list to store ranges.
Iterate through the array: Use a loop to traverse the sorted array.
Identify ranges: Track the start of a range and check if the next number continues the range or if it breaks.
Finish the range: When a break in the range is identified, convert it to the appropriate string format and add it to the result list.
Edge Case: Handle the case when the array is empty by returning an empty list.
Complete Code:
cpp
Copy code
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        if (nums.empty()) return ranges; // Handle empty array

        int start = nums[0]; // Start of the current range
        
        for (int i = 1; i <= nums.size(); ++i) {
            // If we reach the end or the current number is not consecutive
            if (i == nums.size() || nums[i] != nums[i - 1] + 1) {
                // If start is the same as the last number, it's a single number range
                if (start == nums[i - 1]) {
                    ranges.push_back(to_string(start));
                } else {
                    ranges.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                }
                // Start a new range
                if (i < nums.size()) {
                    start = nums[i];
                }
            }
        }
        
        return ranges;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 2, 4, 5, 7}; // Test input
    vector<string> ranges = sol.summaryRanges(nums);
    
    cout << "Summary Ranges: ";
    for (const string& range : ranges) {
        cout << range << " ";
    }
    cout << endl;

    return 0;
}
Dry Run with Test Case:
Let's dry run the provided code using the input nums = [0, 1, 2, 4, 5, 7].

Initialization:
Input: nums = [0, 1, 2, 4, 5, 7]
Output: ranges = []
Start of the range: start = 0
Iteration Steps:
i = 1:

Check if nums[1] (1) == nums[0] (0) + 1 (True)
Continue to next index.
i = 2:

Check if nums[2] (2) == nums[1] (1) + 1 (True)
Continue to next index.
i = 3:

Check if nums[3] (4) == nums[2] (2) + 1 (False)
Now, we add the range:
start (0) == nums[2] (2): Not equal, so add 0->2 to ranges.
Update start = nums[3] (4).
i = 4:

Check if nums[4] (5) == nums[3] (4) + 1 (True)
Continue to next index.
i = 5:

Check if nums[5] (7) == nums[4] (5) + 1 (False)
Now, we add the range:
start (4) != nums[4] (5): Add 4->5 to ranges.
Update start = nums[5] (7).
i = 6:

We have reached the end of the array, add the last number:
start (7) == nums[5] (7): Add 7 to ranges.
Final Output:
Output List: ranges = ["0->2", "4->5", "7"]
Summary:
The function effectively identifies ranges from the sorted unique integers and returns them in the desired format. The dry run demonstrated how the logic correctly handles both consecutive ranges and single numbers. The output of the code with the provided test case will be:

rust
Copy code
Summary Ranges: 0->2 4->5 7 





