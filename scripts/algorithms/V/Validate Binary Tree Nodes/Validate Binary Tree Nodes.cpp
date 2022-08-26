// Runtime: 73 ms (Top 69.07%) | Memory: 31.8 MB (Top 95.34%)
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        vector<int> dsu(n, -1);
        for(int i = 0; i < n; i++)
        {
            if(leftChild[i] != -1)
            {
                if(dsu[leftChild[i]] != -1 || leftChild[i] == findParent(i, dsu))
                    return false;

                dsu[leftChild[i]] = i;
            }

            if(rightChild[i] != -1)
            {
                if(dsu[rightChild[i]] != -1 || rightChild[i] == findParent(i, dsu))
                    return false;

                dsu[rightChild[i]] = i;
            }
        }

        int cnt = 0;
        for(auto &i : dsu)
            if((cnt += i == -1) > 1)
                return false;

        return true;
    }

    int findParent(int i, vector<int> &dsu)
    {
        int a = i;
        while(dsu[a] >= 0)
            a = dsu[a];

        if(dsu[i] != -1)
            dsu[i] = a;

        return a;
    }
};