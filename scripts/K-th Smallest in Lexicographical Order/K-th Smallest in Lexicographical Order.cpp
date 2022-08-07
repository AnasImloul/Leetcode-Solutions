class Node {
    private:
    Node* links[10];
    bool flag = false;
    public:
    bool containsKey(int digit) {
        return links[digit] != nullptr;
    }
    void put(int digit, Node* node) {
        links[digit] = node;
    }
    Node* get(int digit) {
        return links[digit];
    }
    bool isEnd() {
        return flag;
    }
    void setEnd() {
        flag = true;
    }
};

class Trie {
    private:
    Node* root;
    public:
    Trie() {
        root = new Node();
    }
    void insert(int num) {
        string str = to_string(num);
        Node* node = root;
        for(int i=0; i<str.length(); i++) {
            int digit = str[i] - '0';
            if(!node->containsKey(digit)) {
                node->put(digit, new Node());
            }
            node = node->get(digit);
        }
        node->setEnd();
        // stack<int> st;
        // while(num) {
        //     st.push(num%10);
        //     num /= 10;
        // }
        // Node* node = root;
        // while(!st.empty()) {
        //     int digit = st.top();
        //     st.pop();
        //     if(!node->containsKey(digit)) {
        //         node->put(digit, new Node());
        //     }
        //     node = node->get(digit);
        // }
        // node->setEnd();
    }
    int kthELE(int k) {
        int ans = 0;
        dfs(root, ans, k, 0);
        return ans;
    }
    void dfs(Node* root, int &ans, int &k, int num) {
        if(k == 0) return;
        if(root->isEnd()) {
            ans = num;
            k--;
        }
        for(int i=0; i<=9; i++) {
            if(root->containsKey(i)) {
                dfs(root->get(i), ans, k, num*10+i);
            }
        }
    }
};

class Solution {
public:
    int findKthNumber(int n, int k) {
        Trie trie;
        for(int i=1; i<=n; i++) trie.insert(i);
        return trie.kthELE(k);
    }
};
