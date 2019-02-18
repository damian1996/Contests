/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int computeDepth(Node* root, int depth) {
        if(root->children.size() == 0) return depth;
        int maxDepth = depth;
        for(auto& child : root->children) {
            maxDepth = max(maxDepth, computeDepth(child, depth + 1));
        }
        return maxDepth;
    }
    
    int maxDepth(Node* root) {
        if(root == nullptr) return 0;
        int maxDepth = 1;
        for(auto& child : root->children) {
            maxDepth = max(maxDepth, computeDepth(child, 2));
        }
        return maxDepth;
    }
};