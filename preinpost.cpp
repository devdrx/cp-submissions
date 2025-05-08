/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

 class Solution{
	public:
		vector<vector<int> > treeTraversal(TreeNode* root){
			//your code goes here
            stack<pair<TreeNode* , int>> st;
            st.push({root, 1});
            vector<int> pre, ino, post;
            if(root == NULL) return {{}};

            while(!st.empty()){
                auto it = st.top();
                st.pop();

                //algorithm
                if(it.second == 1){
                    pre.push_back(it.first);
                    it.second++;
                    st.push(it);
                    if(it.first->left){
                        st.push({it.first->left, 1});
                    }
                }
                else if(it.second == 2){
                    ino.push_back(it.first);
                    it.second++;
                    st.push(it);
                    if(it.first->right){
                        st.push({it.first->right, 1});
                    }
                }
                else{
                    post.push_back(it.first);
                    //its popped out and not pushed again
                }
            }
            vector<vector<int>> result;
            result.push_back(pre);
            result.push_back(ino);
            result.push_back(post);
            return result;
		}
};