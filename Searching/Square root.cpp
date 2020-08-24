/*
Given an integer x. The task is to find the square root of x. If x is not a perfect square, then return floor(√x).

Example 1:

Input:
x = 5
Output: 2
Explanation: Since, 5 is not perfect 
square, so floor of square_root of 
5 is 2.
Example 2:

Input:
x = 4
Output: 2
Explanation: Since, 4 is a perfect 
square, so its square root is 2.
Your Task:
The task is to complete the function floorSqrt() which should return the square root of given number x.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ x ≤ 107
*/

# include<bits/stdc++.h>
using namespace std;

long long int floorSqrt(long long int x);

// Function to find square root
// x: element to find square root
long long int floorSqrt(long long int x) 
{
    return sqrt(x);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		cout << floorSqrt(n) << endl;
	}
    return 0;   
}
