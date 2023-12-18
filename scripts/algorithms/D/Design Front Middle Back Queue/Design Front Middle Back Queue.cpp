// Runtime: 39 ms (Top 12.5%) | Memory: 21.10 MB (Top 19.7%)

class FrontMiddleBackQueue {
public:
    deque<int> list1;
    deque<int> list2;
    int size;
    
    FrontMiddleBackQueue() {
        size = 0;        
    }
    
    void pushFront(int val) {
        
        if(list1.size()- list2.size() == 0)
        {
            list1.push_front(val);
        }
        else
        {
            list1.push_front(val);
            list2.push_front(list1.back());
            list1.pop_back();
        }
        
        size++;
    }
    
    void pushMiddle(int val) {
        
        if(list1.size() - list2.size() == 0)
        {
            list1.push_back(val);
        }
        else
        {
            list2.push_front(list1.back());
            list1.pop_back();
            list1.push_back(val);
        }
        
        size++;
    }
    
    void pushBack(int val) {
            
        if(list1.size() - list2.size() == 0)
        {
            list2.push_back(val);
            list1.push_back(list2.front());
            list2.pop_front();
        }
        else
        {
            list2.push_back(val);
        }
        
        size++;
    }
    
    int popFront() {

        if(size ==0) return -1;
        
        int val = list1.front();
        list1.pop_front();
        
        if(list1.size()<list2.size())
        {
            list1.push_back(list2.front());
            list2.pop_front();
        }
        
        size--;
        return val;
    }
    
    int popMiddle() {
        
        if(size ==0) return -1;
        
        int val = list1.back();
        list1.pop_back();

        if(list1.size() < list2.size())
        {
            list1.push_back(list2.front());
            list2.pop_front();
        }
        
        size--;
        return val;
        
    }
    
    int popBack() {
        
        if(size ==0) return -1;
        
        int val;
        if(size==1)
        {
            val = list1.front();
            list1.pop_front();
        }
        else
        {
            val = list2.back();
            list2.pop_back();

            int s1 = list1.size();
            int s2 = list2.size();

            if(list1.size() - list2.size() > 1)
            {
                list2.push_front(list1.back());
                list1.pop_back();
            }                   
        }
        
        size--;
        return val;       
    }
};
