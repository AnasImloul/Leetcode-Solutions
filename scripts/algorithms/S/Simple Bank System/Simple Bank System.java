// Runtime: 265 ms (Top 12.10%) | Memory: 117.3 MB (Top 39.86%)
class Bank {

    int N;
    long[] balance;
    public Bank(long[] balance) {
        this.N = balance.length;
        this.balance = balance;
    }

    public boolean transfer(int account1, int account2, long money) {
        if(account1 < 1 || account1 > N || account2 < 1 || account2 > N || balance[account1 - 1] < money)
            return false;
        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }

    public boolean deposit(int account, long money) {
        if(account < 1 || account > N)
            return false;
        balance[account - 1] += money;
        return true;
    }

    public boolean withdraw(int account, long money) {
        if(account < 1 || account > N || balance[account - 1] < money)
            return false;
        balance[account - 1] -= money;
        return true;
    }
}