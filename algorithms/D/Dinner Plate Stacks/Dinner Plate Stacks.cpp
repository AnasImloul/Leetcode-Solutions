class DinnerPlates {
public:
    map<int,stack<int>>mp;
    set<int>empty;
    int cap;
    DinnerPlates(int capacity) 
    {
        this->cap=capacity;
    }
    
    void push(int val) 
    {
        if(empty.size()==0)
        {
            empty.insert(mp.size());
        }
        mp[*empty.begin()].push(val);
        if(mp[*empty.begin()].size()==cap)
        {
            empty.erase(empty.begin());
        }
    }
    int pop() 
    {
        if(mp.size()==0)
        {
            return -1;
        }
        int index=mp.rbegin()->first;
        int val=mp[index].top();
        mp[index].pop();
        empty.insert(index);
        if(mp[index].size()==0)
        {
            mp.erase(index);
        }
        return val;
    }
    
    int popAtStack(int index) 
    {
        if(mp.size()==0||mp.find(index)==mp.end())
        {
            return -1;
        }
        int val=mp[index].top();
        mp[index].pop();
        empty.insert(index);
        if(mp[index].size()==0)
        {
            mp.erase(index);
        }
        return val;
    }
};


