// Runtime: 0 ms (Top 100.0%) | Memory: 5.94 MB (Top 54.1%)

#define ll long long
class Solution {
private:
    int gcd(int a, int b) {
        if (!b) return a;
        return gcd(b, a % b);
    }
    int lcm(ll a, ll b) {
        ll temp = (a / gcd(a, b)) * b;
        return temp > INT_MAX ? INT_MAX : temp;
    }
public:
    int minimizeSet(int divisor1, int divisor2, int uc1, int uc2) {
        int l = 1, r = INT_MAX, LCM = lcm(divisor1, divisor2);
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int a = mid / divisor1, b = mid / divisor2;
            if (uc1 <= mid - a && uc2 <= mid - b && uc1 + uc2 <= (mid - (mid / LCM))) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};