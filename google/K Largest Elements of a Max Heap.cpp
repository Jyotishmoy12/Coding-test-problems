
Given a max heap as an array, implement List<Integer> peekTopK(int[] arr, int k) to find the top k elements. Do not modify the heap or copy entire heap to a different data structure. Example:

           15
       /        \ 
     13         12
   /   \       / 
 10     8     9
Input: [15, 13, 12, 10, 8, 9], k = 5
Output: [15, 13, 12, 10, 9]

#include<bits/stdc++.h>
using namespace std;

vector<int>getKlargest(vector<int>&arr, int k){
    priority_queue<int>pq;
    for(int i=0; i<arr.size();i++){
        pq.push(arr[i]);
    }
    vector<int>ans;
    while(k--){
      ans.push_back(pq.top());
      pq.pop();
    }
    return ans;
}

int main(){
   vector<int>arr={15, 13, 12, 10, 8, 9};
   int k=5;
   vector<int>ans=getKlargest(arr, k);
   for(int i=0; i<ans.size();i++){
    cout<<ans[i]<<" ";
   }
}
