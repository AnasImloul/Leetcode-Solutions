class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        curr_king = kingName;
    }
    
    void birth(string parentName, string childName) {
        children[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    void rec(string parent) {
        if (!dead.count(parent)) inheritance.push_back(parent);
        for (auto child : children[parent])
            rec(child);
    }
    
    vector<string> getInheritanceOrder() {
        inheritance = {};
        rec(curr_king);
        return inheritance;
    }
    
private:
    unordered_map<string, vector<string>> children;
    vector<string> inheritance;
    unordered_set<string> dead;
    string curr_king;
};
