// Runtime: 228 ms (Top 5.18%) | Memory: 36.6 MB (Top 14.81%)
// samll trick: for plaindrome question always try to follow concept that if corners are equal we need to only work
// on middle string to check whether it is also palindrome, instead of check complete strings(both given strings).
class Solution {
public:
    bool ispalind(string x, int i, int j){
        while(i<j){
            if(x[i]!=x[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool checkpositions(string a, string b){
        int i=0,j=b.size()-1;
        while(i<j){
            if(a[i]!=b[j]) break;
            i++;
            j--;
        }
         /*
          left cut
          //agar same hote toh
            "ulacfd" ul.zalu //to check for palindrome : za(from b)
            "jizalu" ji.acfd //to check for palindrome : ac(from a)
        */
        /*
         right cut
         //agar samee hote toh
            "ulacfd" jiza.fd //to check for palindrome : za(from b)
            "jizalu" ulac.lu //to check for palindrome : ac(from a)
        */
        return ispalind(a,i,j) || ispalind(b,i,j);
    }
    bool checkPalindromeFormation(string a, string b) {
              //cut one(from left) //cut two(from right)
        return checkpositions(a,b)||checkpositions(b,a);
    }
};