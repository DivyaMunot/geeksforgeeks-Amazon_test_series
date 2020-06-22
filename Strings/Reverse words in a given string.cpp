/*
Given a String of length S, reverse the whole string without reversing the individual words in it. Words are separated by dots.

Input:
The first line contains T denoting the number of testcases. T testcases follow. Each case contains a string S containing characters.

Output:
For each test case, in a new line, output a single line containing the reversed String.

User Task:
The task is to complete the function reverseWords() which reverse words from the given string and prints the answer. The newline is automatically appended by the driver code.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(1)

Constraints:
1 <= T <= 100
1 <= |S| <= 2000

Example:
Input:
2
i.like.this.program.very.much
pqr.mno
Output:
much.very.program.this.like.i
mno.pqr

Explanation:
Testcase 1: After reversing the whole string(not individual words), the input string becomes much.very.program.this.like.i.
Testcase 2: After reversing the whole string , the input string becomes mno.pqr.
*/

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void reverseWords(char*);

/* Driver function to test above functions */
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[10000];
        cin >> s;
        reverseWords(s);
        cout<<endl;
    }
}

/*Function to reverse words*/
void reverseWords(char *s) {
    
    // Your code here
    
    int i = strlen(s)-1;
    int j=i;
    
    while(1){
        while(s[j]!='.' && j!=0){
            j--;
        }
        
        if(j==0){
            for(int k=j; k<=i; k++)
                cout<<s[k];
            break;
        }
        else{
            for(int k=j+1; k<=i; k++)
                cout<<s[k];
            cout << ".";
        }
        i = j-1;
        j = i;
    }
}
