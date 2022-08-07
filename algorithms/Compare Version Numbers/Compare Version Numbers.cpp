class Solution {
private:
     int countDots(string &s){
        int ans=0;
        for(char c:s){
            if(c=='.'){
                ans++;
            }
        }
        return ans;
    }
    //adds more revisions to the shorter one
    void elongate(string &s,int remainingDots){
        while(remainingDots--){
            s+=".0";
        }
    }
    //makes both the versions have equal number of revisions
    void equate(string &version1,string &version2){
        int dot1=countDots(version1);
        int dot2=countDots(version2);
        if(dot1>dot2){
            elongate(version2,dot1-dot2);
        } else if(dot2>dot1){
            elongate(version1,dot2-dot1);
        }
    }
public:
    int compareVersion(string version1, string version2) {
        equate(version1,version2);
        int s1=0,s2=0;
        while(s1<version1.size() and s2<version2.size()){
            int e1=s1,e2=s2;
            while(e1<version1.size() and version1[e1]!='.'){
                e1++;
            }
            while(e2<version2.size() and version2[e2]!='.'){
                e2++;
            }
            int first=stoi(version1.substr(s1,e1-s1));
            int second=stoi(version2.substr(s2,e2-s2));
            if(first<second){
                return -1;
            } else if(first>second){
                return 1;
            } else {
                s2=e2+1;
                s1=e1+1;
            }
        }
        return 0;
    }
};