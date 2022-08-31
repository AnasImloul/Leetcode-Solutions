// Runtime: 4 ms (Top 30.57%) | Memory: 6.9 MB (Top 35.57%)
class DSU {
    vector<int> parent, size;

    vector<int> Q{'q','w','e','r','t','y','u','i','o','p','Q','W','E','R','T','Y','U','I','O','P'};
    vector<int> A{'a','s','d','f','g','h','j','k','l','A','S','D','F','G','H','J','K','L'};
    vector<int> Z{'z','x','c','v','b','n','m','Z','X','C','V','B','N','M'};

public:
    DSU(){
        for(int i= 0;i<123;i++) parent.push_back(i),size.push_back(1);
        for(int i = 0; i<Q.size()-1;i++) findUnion(Q[i],Q[i+1]);
        for(int i = 0; i<A.size()-1;i++) findUnion(A[i],A[i+1]);
        for(int i = 0; i<Z.size()-1;i++) findUnion(Z[i],Z[i+1]);
    }

    int findParent(int x){
        if(x==parent[x]) return x;
        return parent[x] = findParent(parent[x]);
    }

    void findUnion(int a, int b){
        a = findParent(a);
        b = findParent(b);
        if(a!=b) if(size[b]>size[a]) swap(a,b);parent[b] = a,size[a]+=size[b];
    }
};

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int n = words.size();
        DSU dsu;
        vector<string> ans;
        for(int i = 0;i<n;i++){
            int ss = words[i].size();
            string s = words[i];
            if(ss==1) {ans.push_back(s);continue;}

            bool sameSet = true;
            for(int j = 0;j<ss-1;j++)
                if(dsu.findParent(s[j])!=dsu.findParent(s[j+1])){
                    sameSet = false;break;
                }
            if(sameSet)ans.push_back(s);
        }return ans;
    }
};