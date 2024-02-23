An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 

Constraints:

1 <= n <= 1690



  code-->class Solution {
public:
    int nthUglyNumber(int n) {
    vector<int>t(n+1);
    // 1 st ugly number will be 1
    t[1]=1;
    int i2;
    int i3;
    int i5;
    i2=i3=i5=1; // at first they all will point to 1
    // now run a loop from 2 to n
    for(int i=2;i<=n;i++){
        int i2th=t[i2]*2; // now it will be 2
        int i3th=t[i3]*3; // now it will be 3
        int i5th=t[i5]*5; // now it will be 5
        // now take minimum, which is the next ugly number
        t[i]=min({i2th, i3th, i5th});
        // if the current minimum is equal to the number then increase the pointer 
        // for eq in this case t[i]=2 and i2 is also points in the 2 so we need to increase the pointer right
        if(t[i]==i2th) i2++;
        if(t[i]==i3th) i3++;
        if(t[i]==i5th) i5++;
    }  
    return t[n]; 
    }
};
