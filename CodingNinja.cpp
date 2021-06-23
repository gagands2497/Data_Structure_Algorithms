/************************************************************

    Following is the TreeNode class structure:

    template <typename T>

    class TreeNode {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/


vector<int> reverseLevelOrder(TreeNode<int> *root) {
    vector<int> ans;
    //level order traversal
    //It is a binary tree
    queue<TreeNode<int>*> waiting;

    waiting.push(root);
    while (waiting.empty() == false) {
        TreeNode<int> *curr = waiting.front();
        waiting.pop();
        ans.push_back(curr->val);
        //add left and right child of the node;

        if (curr->left) {
            waiting.push(curr->left);
        }
        if (curr->right) {
            waiting.push(curr->right);
        }
    }

    int start = 0, end = ans.size() - 1;

    while (satrt < end) {
        swap(ans[start++], ans[end--]);
    }

    return ans;

}