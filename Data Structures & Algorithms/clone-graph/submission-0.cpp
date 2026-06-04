class Solution {
    unordered_map<Node*, Node*> mp;

public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;

        // already cloned
        if (mp.count(node)) 
            return mp[node];

        // clone current node
        Node* copy = new Node(node->val);
        mp[node] = copy;

        // clone neighbors
        for (auto nei : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(nei));
        }

        return copy;
    }
};
