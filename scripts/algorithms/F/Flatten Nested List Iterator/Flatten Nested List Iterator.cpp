class NestedIterator {
    vector<int> v;
    int index;
    void helper(vector<NestedInteger> &nestedList, vector<int>& v)
    {
        for (int i = 0; i < nestedList.size(); i++)
        {
            if (nestedList[i].isInteger())
            {
                v.push_back(nestedList[i].getInteger());
            }
            else
            {
                helper(nestedList[i].getList(), v);
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList, v);
        index = 0;
    }
    
    int next() {
        return v[index++];
    }
    
    bool hasNext() {
        if (v.size() <= index)
        {
            return false;
        }
        return true;
    }
};