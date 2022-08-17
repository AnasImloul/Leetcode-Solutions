class SmallestInfiniteSet {
public:
    int cur;
    set<int> s;
    SmallestInfiniteSet() {
        cur=1;
    }
    
    int popSmallest() {
        if(s.size()){
            int res=*s.begin(); s.erase(res);
            return res;
        }else{
            cur+=1;
            return cur-1;
        }
    }
    
    void addBack(int num) {
        if(cur>num) s.insert(num);
    }
};
