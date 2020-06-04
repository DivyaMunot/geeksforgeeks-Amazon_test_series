'''
Given an array of distinct elements. Find the third largest element in it. 

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case is N, size of the array. The second line of each test case contains N space separated values of the array a[].

Output:
Print the third largest element of the array. If the array has less than 3 elements print -1. 

Your Task:
You don't need to read input or print anything. Your task is to complete the function thirdLargest() which takes the array a[] and the size of the array as inputs and returns the third largest element in the array. Return -1 if there are less than 3 elements in the input.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 105
1 ≤ A[i] ≤ 105

Example:
Sample Input:
2
5
2 4 1 3 5
2
10 2

Sample Output:
3
-1

Explanation:
Test Case 1: Largest number is 5, followed by 4 and then 3. Hence, the answer is 3.
Test Case 2: Since there are less than 3 numbers, output is -1.
'''

import sys

def thirdLargest(arr, n):
    # code here
    if (n<3):
        return -1
    third = second = first = -sys.maxsize
    
    for i in range(0, n):
        if arr[i] > first:
            third = second
            second = first
            first = arr[i]
        elif arr[i] > second:
            third = second
            second = arr[i]
        elif arr[i] > third:
            third = arr[i]
            
    return third
    
{ 
#Driver Code Starts
#Your code goes here
if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        print(thirdLargest(arr, n))

} #Driver Code Ends
