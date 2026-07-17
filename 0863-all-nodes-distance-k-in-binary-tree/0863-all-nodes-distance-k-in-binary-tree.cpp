/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void mark_present(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parent){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr=q.front();q.pop();
        if(curr->left){
            parent[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right){
            parent[curr->right]=curr;
            q.push(curr->right);
        }
    }
}

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        unordered_map<TreeNode*,TreeNode*>parent;
        mark_present(root,parent);
        unordered_map<TreeNode*,bool>vis;

        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int curr_level=0;

        while(!q.empty()){
            int size=q.size();
            // curr_level++;
            if(curr_level==k){break;}
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();q.pop();
                if(node->left!=NULL && !vis[node->left]){
                    q.push(node->left);vis[node->left]=true;
                }
                  if(node->right!=NULL && !vis[node->right]){
                    q.push(node->right);vis[node->right]=true;
                  }
                  if(parent[node]&&!vis[parent[node]]){
                    q.push(parent[node]);
                    vis[parent[node]]=true;
                  }
            }
            curr_level++;
        }
        while(!q.empty()){
            TreeNode* curr=q.front();q.pop();
            ans.push_back(curr->val);
        }
        return ans;
        
    }
};