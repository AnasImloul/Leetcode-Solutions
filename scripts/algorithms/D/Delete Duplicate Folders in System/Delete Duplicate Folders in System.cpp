struct Trie {
    void insert(const vector<string>& path) {
        auto node = this;
        for (auto& p: path) {
            if (!node->children.count(p)) {
                node->children[p] = make_unique<Trie>();
            }
            node = node->children[p].get();
        }
    }
    map<string, unique_ptr<Trie>> children;    
};

class Solution {
    Trie root;
    
    map<string, Trie*> seen;
    unordered_set<Trie*> toDelete;
    
    string deduplicate(Trie* node) {
        
        string path;        
        for (auto& [s, n]: node->children) {   
            path += s + deduplicate(n.get());
        }        
        if (path.empty()) return "";
        
        if (seen.count(path)) {
            toDelete.insert(seen[path]);
            toDelete.insert(node);
        } else seen[path] = node;     
        
        return "(" + path + ")";
    }
    
    void getPaths(Trie* node, vector<vector<string>>& paths, vector<string>& path) {
        for (auto& [s, n]: node->children) {
            if (toDelete.count(n.get())) continue;
            path.push_back(s);
            getPaths(n.get(), paths, path);
            path.pop_back();
        }
        
        if (!path.empty()) paths.push_back(path);
    }
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        for (auto& path: paths) root.insert(path);
        paths.clear();
        deduplicate(&root);
        getPaths(&root, paths, vector<string>() = {});
        return paths;
    }
};