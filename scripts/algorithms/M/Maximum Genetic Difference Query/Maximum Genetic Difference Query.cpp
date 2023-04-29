/* 
    Time: O(q+n)
    Space: O(q+n)
    Tag: Trie, N-ary Tree
    Difficulty: H
*/
struct Node {
    int count;
    vector<Node *> children;
    Node() {
        children.resize(2, NULL);
        count = 0;
    }
};

class Trie {
    Node *root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node *cur = root;
        for (int i = 18; i >= 0; i--) {
            bool bit = (num & (1 << i));
            if (!cur->children[bit]) cur->children[bit] = new Node();
            cur = cur->children[bit];
            cur->count++;
        }
    }

    void remove(int num) {
        Node *cur = root;
        for (int i = 18; i >= 0; i--) {
            bool bit = (num & (1 << i));
            cur = cur->children[bit];
            cur->count--;
        }
    }

    int search(int num) {
        int res = 0;
        Node *cur = root;
        for (int i = 18; i >= 0; i--) {
            bool bit = (num & (1 << i));
            if (cur->children[!bit] && cur->children[!bit]->count > 0) {
                res += (1 << i);
                cur = cur->children[!bit];
            } else {
                cur = cur->children[bit];
            }
        }
        return res;
    }
};

class Solution {

    vector<vector<pair<int, int>>> mp;
    Trie *t;
    vector<int> res;

    void dfs(vector<int> gr[], int cur) {
        t->insert(cur);
        for (auto &child : mp[cur]) {
            res[child.second] = t->search(child.first);
        }
        for (int &child : gr[cur]) {
            dfs(gr, child);
        }
        t->remove(cur);
    }

public:
    vector<int> maxGeneticDifference(vector<int> &parents, vector<vector<int>> &queries) {
        t = new Trie();

        int n = parents.size();
        vector<int> gr[n];
        res.resize(queries.size());

        int root = -1;

        for (int i = 0; i < n; i++) {
            if (parents[i] == -1)
                root = i;
            else
                gr[parents[i]].push_back(i);
        }
        mp.resize(n);
        for (int i = 0; i < queries.size(); i++) {
            mp[queries[i][0]].push_back({queries[i][1], i});
        }

        dfs(gr, root);

        return res;
    }
};