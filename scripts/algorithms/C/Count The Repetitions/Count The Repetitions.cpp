// Runtime: 3 ms (Top 77.01%) | Memory: 6.3 MB (Top 49.43%)
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int> countr(s2.size(),-1), indexr(s2.size(),-1);
        int count = 0;
        vector<int> seqIndex;
        for (int i=0, j2=0; i<n1; i++) {
            if (indexr[j2] > -1) {
                int repC = count-countr[j2];
                int repN = i - indexr[j2];
                int remainingN = n1 - i;
                //the times that the pattern repeated
                count += remainingN/repN * repC;
                //the residue at the end of str1, but still might form valid s2
                int j2_ = seqIndex[indexr[j2]+remainingN%repN];
                count += countr[j2_] - countr[j2];
                break;
            } else {
                countr[j2] = count;
                indexr[j2] = i;
                seqIndex.push_back(j2);
            }

            for (int j1=0; j1<s1.size(); j1++) {
                if (s1[j1] == s2[j2]) {
                    j2++;
                    if (j2 == s2.size()) {
                        j2 = 0;
                        count++;
                    }
                }
            }
        }
        return count/n2;
    }
};