// Runtime: 5 ms (Top 15.48%) | Memory: 5.9 MB (Top 26.64%)
// This is a typical Binary Search Problem Here I did Binary Search and Optimized my lcm function a lot.
// Here Number of Ugly numbers for any number is
// that number/a + that number/b + that number/c + that number/lcm(a,b,c) - that number/lcm(a,b) - that number/lcm(b,c) - that number/(a,c) and howzz that??
// See Lets suppose that number is 17 for which you are checking values and a = 2 , b=3 and c= 4 now figure out
// all the possible values for a = 2,4,6,8,10,12,14,16
// b = 3,6,9,12,15
// c = 4,8,12,16
// Now if we add them all we can see 4,6,8,16 are coming twice and 12 is coming thrice so we do lcm(2,3) = 6
// then we are basically multiple occurance of numbers divisible by 6 simlarly for lcm(2,4) & lcm(3,4)
// but any number which is divisble by all three of them we have deleted it 3 times we need at least so we are adding numbers which are divisble by lcm(2,3,4) which is 12 here So if suppose we are countering more numbers than n then h = mid-1 we need to move backward else we need to forward.
class Solution {
public:
    #define ll long long
     ll gcd(ll a, ll b)
     {
       if (b == 0)
        return a;
      return gcd(b, a % b);
      }
      ll lcm(ll a, ll b)
     {
         return (a / gcd(a, b)) * b;
     }
    bool check(ll mid , int a , int b , int c, int n)
    {
        ll j1 = lcm(a,b);
        ll j2 = lcm(a,c);
        ll j3 = lcm(b,c);
        ll j4 = lcm(j1,c);
        ll k = mid/a + mid/b + mid/c + mid/j4 - (mid/j1 + mid/j2 + mid/j3);
        return k==n;
    }
    bool check1(ll mid , int a , int b , int c, int n)
    {
        ll j1 = lcm(a,b);
        ll j2 = lcm(a,c);
        ll j3 = lcm(b,c);
        ll j4 = lcm(j1,c);
        ll k = mid/a + mid/b + mid/c + mid/j4 - (mid/j1 + mid/j2 + mid/j3);
        return k>=n;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        ll l = min(a,min(b,c));
        ll h = INT_MAX;
        while(l<=h)
        {
             ll mid = l + (h-l)/2;
             if(check(mid,a,b,c,n) && (mid%a==0 || mid%b==0 || mid%c==0))
             {
                 return mid;
             }
             else
             {
                 if(check1(mid,a,b,c,n))
                 {
                     h = mid-1;
                 }
                 else
                 {
                     l = mid+1;
                 }
             }
        }
        return 1;
    }
};