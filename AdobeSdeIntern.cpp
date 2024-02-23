Description
You are given an array of integers 
arr, containing the ID of 
N elements, that is, 
arr i is ID of the ith element. Besides, you have the power to perform some number of operations. In one operation, you can remove any one element from arr. You need to find the minimum number of unique IDs left in 
arr after performing atmost m number of operations as explained above.



Sample Input 1
1
6 3
2 2 1 3 3 3

Sample Output 1
1
Sample Input 2
1
8 2
2 4 1 5 3 5 1 3

Sample Output 2
3
Sample Input 3
1
3 2
4 4 4
Sample Output 3
1



dry run--> for this test case-->
  6 3
2 2 1 3 3 3--> store the element and the count in the map--> [(2,2),(1,1), (3,3)]-> store them in an array and sort it so the array becomes
->arr[i].first->counts and arr[i].second->element--> [(1,1),(2,2),(3,3)]-> now check if(m>=arr[i].first) here 3>=1 so decrease so it will be now 2
  and again check so m=1 and check again so m=0, now i will be at 2 index now come to else condition--> arr.size()-i--> 3-2=1 so 1 is the answer


code-->


  #include<bits/stdc++.h>
using namespace std;

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n>> m;

        vector<int> arr(n);
        unordered_map<int, int> countMap;

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            countMap[arr[i]]++;
        }

        vector<pair<int, int>> counts; // pair<Count, ID>
        for (auto it : countMap) {
            counts.push_back({it.second, it.first});
        }

        sort(counts.begin(), counts.end());

        int result = 0;
        for (int i = 0; i < counts.size(); ++i) {
            if (m>= counts[i].first) {
                m -= counts[i].first;
            } else {
                result = counts.size() - i;
                break;
            }
        }

        cout << result << endl;
    }

    return 0;
}
