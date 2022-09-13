// Runtime: 319 ms (Top 38.38%) | Memory: 70.9 MB (Top 7.75%)
class Solution {
public:

    //use to memoize recursive solution
    vector<vector<int>> v;

    /*
    boundary of both strings,
    l is length of concatenated string,
    ans is used to store final result
    */

    int boundary,l,ans;

    //Longest palindromic string
    int find(string &s,int i,int j)
    {
        // i->left, j->right
        //if left index is greater than right then return
        if(i>j) return 0;

        //if already calculated, return result
        if(v[i][j]!=-1) return v[i][j];

        //if we are at stage where i==j,
        //means here single character
        //count it and increase left boundary and decrease right boundary
        if(i==j)
        {
            return v[i][j]=1+find(s,i+1,j-1);
        }

        //if two characters are same, count these two and
        //increase left boundary and decrease right boundary
        //and call function
        if(s[i]==s[j])
        {

            int k=v[i][j]=2+find(s,i+1,j-1);

            /*

             if left character is from word1 and
             right character is from word2
             then store maximum result in ans

             NOTE: till (boundary-1) index s stored word1
             and from index (boundary) s stored word2

            */
            if(i<boundary && j>=boundary)
            {
                ans=max(ans,k);
            }
            return k;
        }

        //if characters are not same,
        //try both increase left index and make right index constent
        // or make left constant or decrease right index
        // and return max of both
        else
        {
            return v[i][j]=max(find(s,i+1,j),find(s,i,j-1));
        }
    }

    int longestPalindrome(string word1, string word2) {

        //store boundary of strings
        boundary=word1.size();

        //concatenate both strings
        word1+=word2;

        //find total length of string
        l=word1.length();

        //used to memoize solution
        v=vector<vector<int>> (l+1,vector<int> (l+1,-1));

        //call function
        int k=find(word1,0,l-1);

        //return final ans
        return ans;
    }
};