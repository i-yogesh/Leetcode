//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

bool search(Node *root, int x);

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;

        cout << search(root, s);
        cout << endl;
    }
}

// } Driver Code Ends


// Function to search a node in BST.

void solve(Node* root, int x, int* ans)
{
    if(root == NULL) return;
    
    solve(root->left, x, ans);
    
    if(root->data == x){
        *ans = 1;
        return;
    }
    if(root->data > x)
        solve(root->left, x, ans);
        
    else if(root->data < x, ans)
        solve(root->right, x, ans);
}

bool search(Node* root, int x) {
    int ans = 0;
    solve(root, x, &ans);
    return ans;
}
