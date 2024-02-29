Given an array of numbers. Determine the largest sum that can be formed by any contiguous sub-array in the array.

  #include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int sum=0;
        int maxi=arr[0];
        for(int i=0;i<n;i++){
            sum+=arr[i];
            maxi=max(maxi, sum);
            if(sum<0) sum=0;
        }
        cout<<maxi<<endl;
    }
}
