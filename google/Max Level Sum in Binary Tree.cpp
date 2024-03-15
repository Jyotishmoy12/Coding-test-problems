Given a Binary Tree having positive and negative nodes. Find the maximum sum of a level in the given Binary Tree.

Example 1:

Input :               
             4
          /    \
         2     -5
        / \    / \
      -1   3  -2  6

Output: 6

Explanation :
Sum of all nodes of 0'th level is 4
Sum of all nodes of 1'th level is -3
Sum of all nodes of 2'th level is 6
Hence maximum sum is 6


The idea is to do a level order traversal of the tree. 
While doing traversal, process nodes of different levels separately. 
For every level being processed, compute the sum of nodes in the level and keep track of the maximum sum.


class Solution{
  public:
    /*You are required to complete below method */
    int maxLevelSum(Node* root) {
        // Your code here
    if(root==NULL) return 0;
    int result=root->data;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        int sum=0;
        while(size--){
            Node*temp=q.front();
            q.pop();
            sum+=temp->data; 
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
        result=max(result,sum);
    }
     return result;
    }
};
