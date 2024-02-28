class Solution{
public:
    int maxLen(int arr[], int N)
    {
        unordered_map<int, int> mp{{0, -1}}; // Corrected map declaration
        int len = 0, sum = 0; // Corrected variable declaration

        for(int i = 0; i < N; i++){ // Corrected variable name from 'n' to 'N'
            if(arr[i] == 1){ // Corrected array name from 'a' to 'arr'
                sum += 1;
            }
            else{
                sum += -1;
            }
            
            if(mp.count(sum)){
                len = max(i - mp[sum], len);
            }
            else{
                mp[sum] = i;
            }
        }
        return len;
    }
};
