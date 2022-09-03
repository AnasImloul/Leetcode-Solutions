// Runtime: 48 ms (Top 93.64%) | Memory: 30 MB (Top 50.94%)
struct node{
    int end=0;
    node* adj[26];
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        auto root = new node();
        auto insert = [&](string&s, int ind){
            node* cur = root;
            int i;
            for(char&c:s){
                i=c - 'a';
                if(!cur->adj[i])cur->adj[i] = new node();
                cur=cur->adj[i];
            }
            cur->end=ind;
        };

        int ind = 0;
        for(string&s : words) insert(s,++ind);

        stack<node*> st;
        st.push(root);
        string ans = "";
        while(!st.empty()){
            node* cur = st.top();st.pop();
            if(cur->end>0 || cur==root){
                if(cur!=root){
                    string word = words[cur->end-1];
                    if(word.size()>ans.size() ||
                      (word.size()==ans.size() && word<ans)){ans = word;}
                }

                for(int j=0;j<26;j++)
                    if(cur->adj[j])st.push(cur->adj[j]);
            }
        }
        return ans;
    }
};