/**
 * @param {number[]} balance
 */
var Bank = function(balance) {
   this.arr = balance; 
};

/** 
 * @param {number} account1 
 * @param {number} account2 
 * @param {number} money
 * @return {boolean}
 */
Bank.prototype.transfer = function(account1, account2, money) {
    if (this.arr[account1-1] >= money && this.arr.length >= account1 && this.arr.length >= account2) {
        this.arr[account1-1] -= money;
        this.arr[account2-1] += money;
        return true;
    }
    return false;
};

/** 
 * @param {number} account 
 * @param {number} money
 * @return {boolean}
 */
Bank.prototype.deposit = function(account, money) {
    if (this.arr.length >= account) {
        this.arr[account-1] += money;
        return true;
    }
    return false;
};

/** 
 * @param {number} account 
 * @param {number} money
 * @return {boolean}
 */
Bank.prototype.withdraw = function(account, money) {
    if (this.arr.length >= account && this.arr[account-1] >= money) {
        this.arr[account-1] -= money
        return true;
    }
    return false;
};

/** 
 * Your Bank object will be instantiated and called as such:
 * var obj = new Bank(balance)
 * var param_1 = obj.transfer(account1,account2,money)
 * var param_2 = obj.deposit(account,money)
 * var param_3 = obj.withdraw(account,money)
 */
