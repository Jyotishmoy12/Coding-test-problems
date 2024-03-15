question-->You are given an array of integers and bucket capacity k(sum of the elements in the bucket should not exceed k), return minimum buckets required to hold all the elements in the array. You are required to return list of buckets not number of buckets.

Example.
Arr = [7,3,5,4,1] and bucket size is 9.
return --> [ [7,1],[5,4],[3]]. if multiple answer is possible with same number of buckets then return any of them.


explanantion-->Initial: i = 0, j = 4, sum = 0, temp = []
i = 0, j = 4, sum = 0, temp = []

Add arr[j] = 7 to temp: temp = [7], sum = 7, j = 3
Add arr[i] = 1 to temp: temp = [7, 1], sum = 8, i = 1
Break inner loop
Push temp into ans: ans = [[7, 1]]
Clear temp: temp = [], sum = 0
i = 1, j = 3, sum = 0, temp = []

Add arr[j] = 5 to temp: temp = [5], sum = 5, j = 2
Add arr[i] = 3 to temp: temp = [5, 3], sum = 8, i = 2
Break inner loop
Push temp into ans: ans = [[7, 1], [5, 3]]
Clear temp: temp = [], sum = 0
i = 2, j = 2, sum = 0, temp = []

Add arr[j] = 4 to temp: temp = [4], sum = 4, j = 1
Break inner loop
Push temp into ans: ans = [[7, 1], [5, 3], [4]]
Clear temp: temp = [], sum = 0
Finally, ans = [[7, 1], [5, 3], [4]] is returned.


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> guessBuckets(vector<int> &arr, int maxCap) {
    sort(arr.begin(), arr.end());
    int i = 0, j = arr.size() - 1, sum = 0;
    vector<int> temp;
    vector<vector<int>> ans;
    
    while (i <= j) {
        while (i <= j) {
            // pick the bigger number
            if (sum + arr[j] <= maxCap) {
                temp.push_back(arr[j]);
                sum += arr[j];
                j--;
            }
            // pick the smaller number
            if (i <= j && sum + arr[i] <= maxCap) {
                temp.push_back(arr[i]);
                sum += arr[i];
                i++;
            } else {
                break; // can't add anymore
            }
        }
        ans.push_back(temp);
        temp.clear();
        sum = 0;
    }
    return ans;
}

int main() {
    vector<int> arr = {7, 3, 5, 4, 1};
    int maxCap = 9;

    vector<vector<int>> result = guessBuckets(arr, maxCap);
    
    // Print the result
    for (const auto &bucket : result) {
        cout << "[";
        for (int i = 0; i < bucket.size(); ++i) {
            cout << bucket[i];
            if (i < bucket.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
