// Runtime: 7 ms (Top 62.0%) | Memory: 44.90 MB (Top 32.0%)

class Solution {
    public boolean primeSubOperation(int[] nums) {
        List<Integer> primes = sieveOfEratosthenes(1000);
        for (int i = nums.length; i >= 2; i--) {
            if (nums[i - 2] >= nums[i - 1]) {
                int index = -1;
                for (int primeIndex = 0; primeIndex < primes.size(); primeIndex++) {
                    if (primes.get(primeIndex) >= nums[i - 2]) {
                        break;
                    }
                    
                    if (nums[i - 2] - primes.get(primeIndex) < nums[i - 1]) {
                        index = primeIndex;
                        break;
                    }
                }
                if (index == -1) {
                    return false;
                }
                nums[i - 2] = nums[i - 2] - primes.get(index);
            }
        }
        return true;
    }
    public List<Integer> sieveOfEratosthenes(int count) {
        List<Integer> result = new ArrayList<>();
        boolean[] primes = new boolean[count + 1];
        for (int i = 0; i < primes.length; i++) {
            primes[i] = true;
        }        
        for (int i = 2; i * i <= count; i++) {
            if (primes[i]) {
                for (int j = i * 2; j <= count; j = j + i) {
                    primes[j] = false;
                }
            }
        }
        for (int i = 2; i <= count; i++) {
            if (primes[i]) {
                result.add(i);
            }
        }
        return result;
    }
}
