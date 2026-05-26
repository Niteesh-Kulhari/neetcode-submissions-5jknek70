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
private:
    unordered_map<Node*, Node*> mp;

    void dfs(Node* node, Node* clone_node){
        if(node == NULL) return;

        for(auto it: node->neighbors){
            if(mp.find(it) == mp.end()){
                Node* clone = new Node(it->val);
                mp[it] = clone;
                //clone_node->neighbors.push_back(clone);
                dfs(it, clone);
            }

            clone_node->neighbors.push_back(mp[it]);
        }
    }

public:
    Node* cloneGraph(Node* node) {
        
        if(node == NULL) return NULL;

        Node* clone_node = new Node(node->val);
        mp[node] = clone_node;

        dfs(node, clone_node);

        return clone_node;
        
    }
};
