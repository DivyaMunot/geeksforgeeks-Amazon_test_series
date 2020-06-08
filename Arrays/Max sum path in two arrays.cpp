/*
You are given two sorted arrays A and B, where elements of the arrays denote the prize you get on visiting the cell. You need to find the maximum prize you can get if you can start from the leftmost position of either of the arrays and end at rightmost position of the either of the arrays. The condition is you can only move towards the right cell and change the current array to another array by jumping to the first occurrence of the element having the same prize value as the current cell.
Note: The common jumping cells should be considered as one instead of two, i.e, add the value on jumping once not twice.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T cases follow.
Each test case contains 3 lines. The first line contains two space-separated integers l1 and l2 denoting the length of the two sorted array A and B. In the second line is the space-separated values of array A and in the third line are space-separated values of array B.

Output:
For each test case, the output is the max sum obtained in such a fashion.

User Task:
Complete the function max_path_sum that takes 4 arguments, the first two arguments represent the 2 arrays A[] and B[] and the last two arguments l1, l2 denotes the size of array A and B respectively. The function returns the sum of the maximum sum path to reach from the beginning of any array to end of any of the two arrays.

Expected Time Complexity: O(N + M).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= N, M <= 105
1 <= A[], B[] <= 106

Example:
2
5 4
2 3 7 10 12
1 5 7 8 
3 3
1 2 4
1 2 7

Output
35 
10

Explanation:
Testcase 1: For first test case the path will be 1+5+7+10+12 = 35.
Testcase 2: For the second test case the path will be 1+2 +7=10.
*/

#include<bits/stdc++.h>
using namespace std;


int max_path_sum(int [], int [], int , int );

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        int result = max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}

int max(int a, int b){
    return (a>b)? a : b;
}

 int max_path_sum(int A[], int B[], int l1, int l2)
{
    int result = 0, sum1 = 0, sum2 = 0;
    int i =0, j=0;
    
    while(i<l1 && j<l2){
        
        if(A[i] < B[j]){    
            sum1 += A[i];
            i++;
        }
        else if(A[i] > B[j]){
            sum2 += B[j];
            j++;
        }
        else{
            result += max(sum1, sum2);
            
            sum1 = sum2 = 0;
            
            while(i<l1 && j<l2 && A[i]==B[j]){
                result += A[i++];
                j++;
            }
        }
    }
    while (i < l1)
        sum1  +=  A[i++];

    while (j < l2)
        sum2 +=  B[j++];

    result +=  max(sum1, sum2);

    return result;
}
