/*
You are given an integer N. You need to convert all zeroes of N to 5.

Input Format:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains a single integer N denoting the number.

Output Format:
For each test case, there will be a new line containing an integer where all zero's are converted to 5.

Your Task:
Your task is to complete the function convertFive() which takes an integer N as an argument and replaces all zeros in the number N with 5. Your function should return the converted number.
Expected Time Complexity: O(log10N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= n <= 10000

Example:
Input
2
1004
121
Output
1554
121

Explanation:
Test Case 1: There are two zeroes in "1004", on replacing all zeroes with "5", the new number will be "1554".
Test Case 2: Since there are no zeroes in "121", the number remains as "121".
*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

// Driver program to test above function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }
}// } Driver Code Ends
int zerotofive(int num){
    if(num ==0){
        return 0;
    }
    
    int digit = num % 10;
    if(digit == 0)
        digit = 5;
    
    return zerotofive(num/10) * 10+digit;
}
/*you are required to complete this method*/
int convertFive(int num) {
    // Your code here
    if(num == 0){
        return 5;
    }
    else{
        return zerotofive(num);
    }
    
}
