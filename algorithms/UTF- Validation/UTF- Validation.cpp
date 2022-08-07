class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i=0;
        while (i<data.size()) {
            int n=0;
            if ((data[i]>>7)==0) n=1;
            else if ((data[i]>>5)==6) n=2;
            else if ((data[i]>>4)==14) n=3;
            else if ((data[i]>>3)==30) n=4;
            else return false;
            for (int j=i+1; j<i+n; j++)
                if (j>=data.size() || data[j]>>6!=2)
                    return false;
           i += n;
        }
        return true;
    }
};
