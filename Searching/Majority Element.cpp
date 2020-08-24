/*
Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.

Example 1:

Input:
N = 5
A[] = {3,1,3,3,2}
Output: 3
Explanation: Since, each element in 
{1,2,3} appears only once so there 
is no majority element.
Example 2:

Input:
N = 3
A[] = {1,2,3}
Output: -1
Explanation: Since, 3 is present 
more than N/2 times, so it is 
the majority element.
Your Task:
The task is to complete the function findMajority() which returns the majority element in the array. If no majority exists, return -1.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 107
0 <= Ai <= 106
*/

#include<bits/stdc++.h>
using namespace std;

// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int a[], int size)
{
    if(size==1)
        return a[0];
        
    sort(a, a+size); 
      
    int count = 1, max_ele = -1, temp = a[0], ele, flag=0; 
      
    for(int i=1;i<n;i++){ 

        if(temp==a[i])
            count++;
        else{ 
            count = 1; 
            temp = a[i]; 
        }

        if(max_ele<count){ 
            max_ele = count; 
            ele = a[i]; 
              
            if(max_ele>(n/2)){ 
                flag = 1; 
                break; 
            }
        }
    }
    return (flag==1 ? ele : -1); 
}

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        cout << majorityElement(arr, n) << endl;
    }

    return 0;
}
