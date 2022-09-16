// Runtime: 117 ms (Top 99.00%) | Memory: 50 MB (Top 86.57%)
class Solution {
    public int largestComponentSize(int[] nums) {
        int maxNum = getMaxNum(nums);
        Map<Integer, Integer> numToFirstPrimeFactor = new HashMap<>();
        DisjointSet ds = new DisjointSet(maxNum + 1);
        for (int num : nums) {
            if (num == 1) {
                continue;
            }

            List<Integer> primeFactors = getPrimeFactors(num);
            int firstPrimeFactor = primeFactors.get(0);
            numToFirstPrimeFactor.put(num, firstPrimeFactor);

            for (int i = 1; i < primeFactors.size(); i++) {
                ds.union(primeFactors.get(i-1), primeFactors.get(i));
            }
        }

        Map<Integer, Integer> componentToSize = new HashMap<>();
        int maxSize = 0;
        for (int num : nums) {
            if (num == 1) {
                continue;
            }

            int firstPrimeFactor = numToFirstPrimeFactor.get(num);
            int component = ds.find(firstPrimeFactor);
            int size = componentToSize.getOrDefault(component, 0);
            componentToSize.put(component, ++size);
            maxSize = Math.max(maxSize, size);
        }
        return maxSize;
    }

    public int getMaxNum(int[] nums) {
        int maxNum = 0;
        for (int num : nums) {
            maxNum = Math.max(maxNum, num);
        }
        return maxNum;
    }

    public List<Integer> getPrimeFactors(int num) {
        List<Integer> primeFactors = new ArrayList<>();

        // even prime factor i.e. 2
        if((num & 1) == 0){
            primeFactors.add(2);

            do{
                num >>= 1;
            }while((num & 1) == 0);
        }

        // odd prime factors
        int primeFactor = 3;
        while(num != 1 && primeFactor*primeFactor <= num){
            if(num % primeFactor == 0){
                primeFactors.add(primeFactor);

                do{
                    num /= primeFactor;
                }while(num % primeFactor == 0);
            }
            primeFactor += 2;
        }

        // num is prime
        if(num != 1){
            primeFactors.add(num);
        }
        return primeFactors;
    }
}

class DisjointSet {
    int[] root;
    int[] rank;

    public DisjointSet(int size) {
        root = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    public int find(int x) {
        while (x != root[x]) {
            root[x] = root[root[x]];
            x = root[x];
        }
        return x;
    }

    public void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return;
        }

        if (rank[rootX] > rank[rootY]) {
            root[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            root[rootX] = rootY;
        } else {
            root[rootY] = rootX;
            rank[rootX]++;
        }
    }
}