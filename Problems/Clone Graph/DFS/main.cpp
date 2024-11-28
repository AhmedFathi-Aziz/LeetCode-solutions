/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node *node, unordered_map<Node*, Node*> &mp) {
        if (mp.find(node) != mp.end())
            return mp[node];
        mp[node] = new Node(node->val);
        for (auto neighbor : node->neighbors) {
            mp[node]->neighbors.push_back(dfs(neighbor, mp));
        }
        return mp[node];
    }
    Node* cloneGraph(Node* node) {
        if (!node)
            return node;
        unordered_map<Node*, Node*> mp;
        return dfs(node, mp);
    }
};
