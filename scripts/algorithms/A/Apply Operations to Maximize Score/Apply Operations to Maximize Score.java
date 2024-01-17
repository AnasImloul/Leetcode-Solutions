// Runtime: 281 ms (Top 46.88%) | Memory: 65.80 MB (Top 6.25%)

class Solution {
    static int MOD = (int)1e9 + 7;
    class MyNum {
        int value;
        int left;
        int right;
        int idx;
        int score;
        MyNum(int v, int l, int r, int i, int s) {
            this.value = v;
            this.left = l;
            this.right = r;
            this.idx = i;
            this.score = s;
        }
    }
    int score(int x) {
        int count = 0;
        if (x % 2 == 0) {
            count++;
            while (x % 2 == 0) {
                x /= 2;
            }
        }

        // Check for odd prime factors
        for (int i = 3; i <= Math.sqrt(x); i += 2) {
            if (x % i == 0) {
                count++;
                while (x % i == 0) {
                    x /= i;
                }
                if (x == 1) {
                    return count;
                }
            }
        }

        // If x is a prime number greater than 2
        if (x > 2) {
            count++;
        }

        return count;
    }
    long power(int x, int p) {
        if (p == 0) {
            return 1;
        }
        long ans = 1;
        if ((p & 1) == 1) {
            ans = x;
        }
        long res = power(x, p >> 1);
        res = (res * res) % MOD;
        ans = (ans * res) % MOD;
        return ans;
    }

    public int maximumScore(List<Integer> nums, int k) {
        int n = nums.size();
        MyNum[] d = new MyNum[n];
        
        // input the array while calculating the prime score
        // and initialize the left and right for each nums[i]
        for (int i = 0; i < n; i++) {
            d[i] = new MyNum(nums.get(i), i + 1, n - i, i, score(nums.get(i)));
        }

        // use monotonic stack to calculate the left and right
        Stack<Integer> s = new Stack<>();
        for (int i = 0; i < n; i++) {
            while (!s.isEmpty() && d[s.peek()].score < d[i].score) {
                int idx = s.pop();
                d[idx].right = i - idx;
            }
            s.push(i);
        }
        s.clear();
        
        for (int i = n - 1; i >= 0; i--) {
            while (!s.isEmpty() && d[s.peek()].score <= d[i].score) {
                int idx = s.pop();
                d[idx].left = idx - i;
            }
            s.push(i);
        }

        // sort the array by value, 
        Arrays.sort(d, (a, b) -> {
            // if (a.value == b.value) {
            //     return a.idx - b.idx;
            //     // return  b.left * b.right - a.left * a.right;
            // }
            return b.value - a.value;
        });
        // for (int i = 0; i < n; i++) {
        //     System.out.printf("%d, %d, %d%n", d[i].value, d[i].left, d[i].right);
        // }

        // caculate the answer until k reached
        long ans = 1L;
        for (int i = 0; i < n && k > 0; i++) {
            int ops = d[i].right * d[i].left;
            int realOps = Math.min(k, ops);
            k -= realOps;
            ans = ans * power(d[i].value, realOps) % MOD;
        }
        return (int) ans;
    }
}
