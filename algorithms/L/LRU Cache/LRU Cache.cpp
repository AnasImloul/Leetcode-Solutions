class LRUCache {
public:
    int mx;
    class node{
        public:
        node *prev,*next;
        int key,val;
        node(int k,int v){
            key=k,val=v;
        }
    };
    unordered_map<int,node*> mp;
        node *head=new node(-1,-1);
        node *tail=new node(-1,-1);
    LRUCache(int capacity) {
        mx=capacity;
        mp.reserve(1024);
        mp.max_load_factor(0.25);

        head->next=tail;tail->prev=head;
    }
    
    void addnode(node *temp){
        node *temp1=head->next;
        head->next=temp;temp->prev=head;
        temp->next=temp1;temp1->prev=temp;
    }
    
    void deletenode(node *temp){
        node *temp1=temp->prev;
        node *temp2=temp->next;
        temp1->next=temp2;
        temp2->prev=temp1;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node *temp=mp[key];
            int res=temp->val;
            mp.erase(key);
            deletenode(temp);
            addnode(temp);
            mp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node *temp=mp[key];
            mp.erase(key);
            deletenode(temp);
        }
        if(mp.size()==mx){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        mp[key]=head->next;
    }
};
