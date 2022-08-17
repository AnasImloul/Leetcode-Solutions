class Solution {
public:
    bool isSubSequence(string str1, string str2){
        int j = 0,m=str1.size(),n=str2.size();
        for (int i = 0; i < n && j < m; i++)
            if (str1[j] == str2[i])
                j++;
        return (j == m);
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        string copy=s;
        int left = 0, right =removable.size();
        while (left <= right) {
            int mid = (left+right)/2;
            for(int i=0;i<mid;i++) copy[removable[i]]='*';
            if (isSubSequence(p,copy))
			 //if p is subsequence of string after mid number of removals then we should look for if it's possible to remove more characters 
                left = mid+1;
            else {
			//if p is not a subsequence of string it means that we have certainly removed more characters from string 
			//so we must decrease our size of removal characters and hence we  add all characters we removed earlier.
                for(int i=0;i<mid;i++) copy[removable[i]] = s[removable[i]];
                right = mid-1;
            }
        }
        return right;
    }
};
