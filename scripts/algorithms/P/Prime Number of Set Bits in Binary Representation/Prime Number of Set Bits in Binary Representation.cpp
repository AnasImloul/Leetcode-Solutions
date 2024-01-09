// Runtime: 3 ms (Top 91.95%) | Memory: 6.60 MB (Top 11.85%)

/*
There is a combinatorial formula for computing 
#{x <N| x is natural number with bitcount(x)=k} =
\sum_{i=0}^k C(p[i], k-i)
where p[i]=position for i-th 1 in N's binary expression.
*/

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19};
int C[21][21] = {0};

class Solution {
public:
    void PascalTriangle(int n) {
        for (int i = 0; i <= n; i++) {
            fill(C[i], C[i] + (i + 1), 1);
            for (int j = 1; j <= i / 2; j++) {
                C[i][i-j] = C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }

    vector<int> N2p(int N) {
        bitset<21> bN(N);
        vector<int> p;
        for (int i=20; i >= 0; i--) {
            if (bN[i]) p.push_back(i);
        }
        return p;
    }

    int nums_bitcount(vector<int>& p, int k) {
        int sum = 0;
        for (int i = 0; i < p.size(); i++) {
            int maxIndex = min(p[i], k-i);
            if (maxIndex >= 0) {
                sum += C[p[i]][k-i];
            }
        }
        return sum;
    }

    int nums_bitcount_isPrime(int N) {
        vector<int> p = N2p(N);
        int sum = 0;
        for (int k : prime) {
            sum += nums_bitcount(p, k);
        }
        return sum;
    }

    int countPrimeSetBits(int left, int right) {
        int L = log2(right+1) + 1;
        PascalTriangle(L);
        return nums_bitcount_isPrime(right+1)-nums_bitcount_isPrime(left);
    }
};
