#include<bits/stdc++.h>
using namespace std;

// topic: graph + bfs + map


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


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node *,Node *>mp;
        mp.reserve(200);
        Node * head=new Node(node->val);
        head->neighbors.reserve(node->neighbors.size());
        mp[node]=head;
        vector<Node *>q;
        q.reserve(100);
        int front=0;
        q.push_back(node);
        while(front!=q.size()){
            Node * cur=q[front];
            front++;
            Node *cloneNode=mp[cur];
            for(auto & adj:cur->neighbors){
                Node * cloneAdj;
                if(!mp.count(adj)){
                    cloneAdj=new Node(adj->val);
                    cloneAdj->neighbors.reserve(adj->neighbors.size());
                    mp[adj]=cloneAdj;
                    q.push_back(adj);
                }
                else cloneAdj=mp[adj];
                
                cloneNode->neighbors.push_back(cloneAdj);

            }
        }
        return head;
    }
};

