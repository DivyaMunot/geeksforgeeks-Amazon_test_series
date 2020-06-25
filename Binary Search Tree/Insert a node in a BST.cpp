/*
Given a BST and a key. Insert a new Node with value equal to that key into the BST. 

Input:
The first line of input contains the number of test cases T. For each test case, there will two lines. The first line of input is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Second-line is an integer representing the key value which needs to be inserted

Output:
For each test case, in a new line, the inorder of the BST gets printed.

Your Task:
You don't need to read input or print anything. Your task is to complete the function insert() which takes the root of the BST and a Key as inputs and returns the root of the BST after inserting the Key value into it. 

Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 10
1 <= N <= 100000
1 <= K <= 1000000

Example:
Input:
2
2 1 3 
4
2 1 3 N N N 6 4
1
Output:
1 2 3 4
1 2 3 4 6

Explanation:
Testcase 1: After inserting the node 4 the tree will be
                                          2
                                      /        \
                                    1          3
                                                   \
                                                    4
Inorder traversal will be 1 2 3 4.
Testcase 2: After inserting the node 1 the tree will be 
                                         2
                                    /           \
                                  1            3
                                /     \       /     \
                              N     N     N     6
                                                   /
                                                 4
Inorder traversal of the above tree will be 1 2 3 4 6.

Note:
In case a node with value equal to the given Key is already present in the BST, you simply need to ignore the insertion, ie no insertion has to be made in that case. 
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node* insert(Node* root, int Key)
{
    // Your code here
    if(root == NULL){
        return new Node(Key);
    }
    else{
        Node* current = root;
        if(current->data == Key){
            return root;
        }
        else if(current->data < Key)
            current->right =  insert(current->right, Key);
        else if(current->data > Key)
            current->left = insert(current->left, Key);
    }
    return root;
}

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
   
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

       getline(cin, s);
        int k = stoi(s);

        insert(root, k);
        vector<int> v;
        inorder(root, v);
        for(int i=0;i<v.size();i++)
            cout << v[i] << " ";
        cout << endl;

       //cout<<"~"<<endl;
   }
   return 0;
}
