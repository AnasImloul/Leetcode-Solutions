class list_node {
public:
    int key, val, cnt;
    list_node* next;
    list_node* prev;
    list_node(int k, int v, list_node* n, list_node* p) {
        key = k; val = v; cnt = 1;
        next = n; prev = p;
    }
};
class LFUCache {
public:
    int min_cnt;
    bool zero;
    unordered_map<int, list_node*> key2node;
    unordered_map<int, pair<list_node*, list_node*>> cnt2list;
    LFUCache(int capacity) {
        cin.tie(0); ios_base::sync_with_stdio(0);
        min_cnt = 0;
        c = capacity;
        zero = (c == 0);
    }
    
    int get(int key) {
        if(zero) return -1;
        auto it = key2node.find(key);
        if(it == key2node.end() || it->second == NULL) return -1;
        addcnt(key);
        return it->second->val;
    }
    
    void put(int key, int value) {
        if(zero) return;
        auto it = key2node.find(key);
        if(it != key2node.end() && it->second != NULL) {
            addcnt(key);
            it->second->val = value;
            return;
        }
        if(c) --c;
        else {
            key2node[cnt2list[min_cnt].first->key] = NULL;
            list_node* tmp = cnt2list[min_cnt].first;
            if(tmp->next) tmp->next->prev = NULL;
            cnt2list[min_cnt].first = tmp->next;
            if(cnt2list[min_cnt].second == tmp) cnt2list[min_cnt].second = NULL; 
        }

        min_cnt = 1;
        list_node* node = new list_node(key, value, NULL, NULL);
        key2node[key] = node;
        if(cnt2list.find(1) == cnt2list.end() || cnt2list[1].first == NULL) {
            cnt2list[1].first = cnt2list[1].second = node;
        }
        else {
            node->prev = cnt2list[1].second;
            cnt2list[1].second->next = node;
            cnt2list[1].second = node;
        }
    }
private:
    int c;
    void addcnt(int key) {
        if(cnt2list[key2node[key]->cnt].first == key2node[key]) 
            cnt2list[key2node[key]->cnt].first = key2node[key]->next;
        if(cnt2list[key2node[key]->cnt].second == key2node[key]) 
            cnt2list[key2node[key]->cnt].second = key2node[key]->prev;
        if(min_cnt == key2node[key]->cnt && cnt2list[key2node[key]->cnt].first == NULL) min_cnt++;
        key2node[key]->cnt++;
        if(key2node[key]->prev) key2node[key]->prev->next = key2node[key]->next;
        if(key2node[key]->next) key2node[key]->next->prev = key2node[key]->prev;
        key2node[key]->next = NULL;
        auto lit = cnt2list.find(key2node[key]->cnt);
        if(lit == cnt2list.end() || lit->second.first == NULL) {
            cnt2list[key2node[key]->cnt].first = cnt2list[key2node[key]->cnt].second = key2node[key];
            key2node[key]->prev = NULL;
        }
        else {
            key2node[key]->prev = cnt2list[key2node[key]->cnt].second;
            cnt2list[key2node[key]->cnt].second->next = key2node[key];
            cnt2list[key2node[key]->cnt].second = key2node[key];
        }
    }
};
