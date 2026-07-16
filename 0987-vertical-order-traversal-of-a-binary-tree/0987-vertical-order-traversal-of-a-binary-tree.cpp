class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        if(root == nullptr) return {};

        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> nodes;

        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0,0}});

        while(!q.empty()){

            auto curr = q.front();
            q.pop();

            TreeNode* node = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            nodes[x][y].insert(node->val);

            if(node->left)
                q.push({node->left, {x-1, y+1}});

            if(node->right)
                q.push({node->right, {x+1, y+1}});
        }

        for(auto i : nodes){
            vector<int> col;
            for(auto j : i.second){
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};