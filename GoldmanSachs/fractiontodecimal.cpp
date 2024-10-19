Problem Explanation
You're given two integers, numerator and denominator, and need to return the result of their division in the form of a string. If the division results in a recurring decimal, the recurring part must be enclosed in parentheses.

For example:

Numerator = 1, Denominator = 2 ➔ 1 / 2 = 0.5 ➔ return "0.5"
Numerator = 2, Denominator = 1 ➔ 2 / 1 = 2 ➔ return "2"
Numerator = 4, Denominator = 333 ➔ 4 / 333 = 0.012012... (where 012 repeats) ➔ return "0.(012)"
Thought Process and Intuition
Integer Division: First, handle the integer part of the division (numerator // denominator), which can easily be computed using integer division.

Handling Signs: If either numerator or denominator is negative but not both, the result is negative. So handle the sign at the beginning.

Handling the Fractional Part: After computing the integer part, deal with the remainder. The remainder determines the fractional part. If the remainder becomes zero at any point, the division is complete, and there is no repeating part.

Detecting Repeating Decimals: If the remainder starts repeating during the long division process, that means the decimal part will start repeating. You need to detect this by using a map to track each remainder and its corresponding index in the result. When the same remainder appears again, you enclose the repeating part in parentheses.

Handling Edge Cases:

If the numerator is divisible by the denominator without a remainder, the result is just the integer part (no fractional part).
If the denominator is zero, it would throw an error, but here it's guaranteed that the denominator is non-zero.
Detailed Steps:
Calculate the integer part of the division.
If there’s no remainder, return the integer part as a string.
Otherwise, proceed with long division:
Start calculating the decimal digits by multiplying the remainder by 10, dividing it by the denominator to get the next digit, and updating the remainder.
Track the remainders using a map. If the same remainder appears again, it means the decimal starts repeating from that point.
Insert parentheses around the repeating part.
C++ Code Implementation
cpp
Copy code
#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdlib> // for abs()
using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    // Handle the case when numerator is zero
    if (numerator == 0) return "0";
    
    string result;
    
    // Determine the sign of the result
    if ((numerator < 0) ^ (denominator < 0)) {
        result += "-";
    }
    
    // Convert both to positive long long to prevent overflow
    long long n = llabs(numerator);
    long long d = llabs(denominator);
    
    // Append the integer part
    result += to_string(n / d);
    
    // Calculate the remainder
    long long remainder = n % d;
    
    // If there is no remainder, return the result (integer division)
    if (remainder == 0) return result;
    
    // Otherwise, we deal with the fractional part
    result += ".";
    
    // Use a map to remember each remainder and its corresponding position in the result
    unordered_map<long long, int> remainderMap;
    
    while (remainder != 0) {
        // If we have seen this remainder before, it means a repeating cycle
        if (remainderMap.find(remainder) != remainderMap.end()) {
            // Insert parentheses at the beginning of the repeating part
            result.insert(remainderMap[remainder], "(");
            result += ")";
            break;
        }
        
        // Remember the position of this remainder
        remainderMap[remainder] = result.length();
        
        // Perform the division step: multiply remainder by 10 and get next digit
        remainder *= 10;
        result += to_string(remainder / d);
        
        // Update remainder
        remainder %= d;
    }
    
    return result;
}


Let’s go step by step in greater depth with a dry run of the code for Input:

Numerator = 4
Denominator = 333
Initial Setup
We are solving for:

4
333
333
4
​
 
Step 1: Handle Zero Numerator
cpp
Copy code
if (numerator == 0) return "0";
Numerator is not 0, so we skip this.
Step 2: Determine the Sign
cpp
Copy code
if ((numerator < 0) ^ (denominator < 0)) {
    result += "-";
}
Neither numerator (4) nor denominator (333) is negative, so no negative sign is added to result. We continue with an empty result string.
Step 3: Calculate Integer Part and Initial Setup
cpp
Copy code
long long n = llabs(numerator); // n = 4
long long d = llabs(denominator); // d = 333
result += to_string(n / d); // Integer part = 4 / 333 = 0
long long remainder = n % d; // remainder = 4 % 333 = 4
n = 4, d = 333
Integer part of division is 0, so the result becomes "0".
Remainder is 4. Since the remainder is not zero, we have a fractional part.
cpp
Copy code
if (remainder == 0) return result; // remainder is not 0, so continue
result += "."; // Add decimal point
Result becomes "0.".
Step 4: Start Long Division for Fractional Part
We now perform long division, tracking remainders using a hash map (remainderMap) to detect when a repeating decimal starts.

The idea is that for each iteration:

We multiply the remainder by 10.
Divide it by the denominator to get the next decimal digit.
Update the remainder and store its position in remainderMap to track if the remainder repeats.
First Iteration:
Current remainder = 4

cpp
Copy code
remainderMap[4] = result.length(); // remainderMap[4] = 2 (current length of "0." is 2)
The remainder 4 is stored in the map with the value 2, representing the current index in the result where the decimal part starts.
cpp
Copy code
remainder *= 10; // remainder = 4 * 10 = 40
result += to_string(remainder / d); // result += to_string(40 / 333) = "0.0"
remainder = remainder % d; // remainder = 40 % 333 = 40
Multiply the remainder by 10: 4 * 10 = 40
Perform the division: 40 / 333 = 0, so we append "0" to result.
Result becomes "0.0".
Update remainder: 40 % 333 = 40
Second Iteration:
Current remainder = 40

cpp
Copy code
remainderMap[40] = result.length(); // remainderMap[40] = 3 (current length of "0.0" is 3)
The remainder 40 is stored in the map with the value 3, representing the index in the result where this part of the decimal starts.
cpp
Copy code
remainder *= 10; // remainder = 40 * 10 = 400
result += to_string(remainder / d); // result += to_string(400 / 333) = "0.01"
remainder = remainder % d; // remainder = 400 % 333 = 67
Multiply the remainder by 10: 40 * 10 = 400
Perform the division: 400 / 333 = 1, so we append "1" to result.
Result becomes "0.01".
Update remainder: 400 % 333 = 67
Third Iteration:
Current remainder = 67

cpp
Copy code
remainderMap[67] = result.length(); // remainderMap[67] = 4 (current length of "0.01" is 4)
The remainder 67 is stored in the map with the value 4, representing the index in the result where this part of the decimal starts.
cpp
Copy code
remainder *= 10; // remainder = 67 * 10 = 670
result += to_string(remainder / d); // result += to_string(670 / 333) = "0.012"
remainder = remainder % d; // remainder = 670 % 333 = 4
Multiply the remainder by 10: 67 * 10 = 670
Perform the division: 670 / 333 = 2, so we append "2" to result.
Result becomes "0.012".
Update remainder: 670 % 333 = 4
Fourth Iteration:
Current remainder = 4

Now, we encounter the remainder 4 again, which is already in remainderMap. This means we have found the start of a repeating decimal.
cpp
Copy code
if (remainderMap.find(remainder) != remainderMap.end()) {
    result.insert(remainderMap[remainder], "("); // Insert "(" at index 2
    result += ")"; // Append ")" at the end
    break;
}
Remainder 4 is already in remainderMap at index 2, so we insert a ( at index 2.

We then append ) at the end.

Result becomes "0.(012)".

Step 5: Return Final Result
cpp
Copy code
return result; // returns "0.(012)"
The final output is "0.(012)".

Summary of the Result Formation
At each step, the remainder is multiplied by 10 and divided by the denominator, generating the digits of the fractional part:

First iteration:

Remainder 4 becomes 40.
Divide 40 / 333 = 0 ➔ result = "0.0".
Second iteration:

Remainder 40 becomes 400.
Divide 400 / 333 = 1 ➔ result = "0.01".
Third iteration:

Remainder 67 becomes 670.
Divide 670 / 333 = 2 ➔ result = "0.012".
Fourth iteration:

Remainder 4 repeats, indicating the start of a repeating cycle (012).
The repeating part "012" is enclosed in parentheses, giving the final result "0.(012)".

Complexity Analysis
Time Complexity: O(Q), where Q is the number of digits in the fractional part before the decimal either terminates or repeats. Each remainder is processed once, and checking/adding a remainder to the map is O(1).

Space Complexity: O(Q), as we store remainders and their positions in the map, and the result string grows proportional to the number of digits in the fractional part.






