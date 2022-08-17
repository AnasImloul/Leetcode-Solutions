class FreqStack {
public:
    unordered_map<int,int> ump;
    unordered_map<int,stack<int>> ump_st;
    
    int cap=1;
    
    FreqStack() {
        ump.clear();
        ump_st.clear();
    }
    
    void push(int val) {
	
		//increasing the count
        if(ump.find(val)!=ump.end())
        {
            ump[val]++;
        }
        else
        {
            ump[val]=1;
        }
        
		//update the highest level
        if(cap<ump[val])
        {
            cap = ump[val];
        }
		
        //push the elements in the stack where it belongs as per height
        ump_st[ump[val]].push(val);
    }
    
    int pop() {
        int val = ump_st[cap].top();
        ump_st[cap].pop();
        
        if(ump_st[cap].size()==0)
        {
            cap--;
        }
        
        ump[val]--;
        
        if(ump[val]==0)
        {
            ump.erase(val);
        }
        
        return val;
    }
};

