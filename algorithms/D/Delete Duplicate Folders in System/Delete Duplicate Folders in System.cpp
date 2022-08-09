class node{
    public: 
        map<string, node*> child;
        bool end;
        bool exclude;
        string name;
        node(string fname){
            exclude = false;
            end = false;
            name = fname;
        }
};

class Solution {
public:
    node *root;
    unordered_map<string, vector<node*>> parentMap;
    vector<vector<string>> ans;
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        root = new node("/");
        for(int i = 0 ; i < paths.size(); i++) insert(root, paths[i], 0);
        dfs(root);
        for(auto &e : parentMap)
            if(e.second.size() > 1)
                for(auto &parent : e.second)
                    parent->exclude = true;
        vector<string> temp;
        getans(root, temp);
        return ans;
    }
    
    void getans(node *root, vector<string> &temp){
        if(root->exclude) return;
        if(root->name != "/") temp.push_back(root->name);
        if(root->end) ans.push_back(temp);
        for(auto &e : root->child)
            getans(e.second, temp);
        if(root->name != "/") temp.pop_back();
    }
    
    string dfs(node *root){
        string childPath = "";
        for(auto &e : root->child){
            childPath += dfs(e.second);
            childPath += "|";
        }
        if(childPath != "") parentMap[childPath].push_back(root);
        return root->name + "|" + childPath;
    }
    
    void insert(node *root, vector<string> &path, int pos){
        if(pos < path.size()){
            if(root->child.count(path[pos]) == 0) root->child[path[pos]] = new node(path[pos]);
            insert(root->child[path[pos]], path, pos+1);
        }
        else if(pos == path.size()) root->end = true;
    }
};
