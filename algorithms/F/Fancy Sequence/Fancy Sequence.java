class Fancy {
    private ArrayList<Long> lst;
    private ArrayList<Long> add;
    private ArrayList<Long> mult;
    private final long MOD = 1000000007;

    public Fancy() {
        lst = new ArrayList<>();
        add = new ArrayList<>();
        mult = new ArrayList<>();
        add.add(0L);
        mult.add(1L);
    }

    public void append(int val) {
        lst.add((long) val);
        int l = add.size();
        add.add(add.get(l - 1));
        mult.add(mult.get(l - 1));
    }

    public void addAll(int inc) {
       int l = add.size();
       add.set(l - 1, add.get(l - 1) + inc);
    }

    public void multAll(int m) {
        int l = add.size();
        add.set(l - 1, (add.get(l - 1) * m) % MOD);
        mult.set(l - 1, (mult.get(l - 1) * m) % MOD);
    }

    public int getIndex(int idx) {
        if (idx >= lst.size()) return -1;

        int l = add.size();
        long m = (mult.get(l - 1) * inverse(mult.get(idx))) % MOD;
        long a = (add.get(l - 1) - (add.get(idx) * m) % MOD + MOD) % MOD;
        return (int) (((lst.get(idx) * m) % MOD + a) % MOD);
    }

    long inverse(long a) {
        return pow(a, MOD - 2);
    }

    long pow(long a, long n) {
        if (n == 0) return 1;
        if (n % 2 == 0) {
            long t = pow(a, n / 2);
            return (t * t) % MOD;
        } else {
            return (pow(a, n - 1) * a) % MOD;
        }
    }
}
