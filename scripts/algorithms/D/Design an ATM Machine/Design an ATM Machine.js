// Runtime: 617 ms (Top 12.20%) | Memory: 63.7 MB (Top 39.02%)

var ATM = function() {
    this.bankNotes = new Array(5).fill(0)
    this.banksNotesValue = [20, 50, 100, 200, 500]
};

/**
 * @param {number[]} banknotesCount
 * @return {void}
 */
ATM.prototype.deposit = function(banknotesCount) {
    for (let i = 0; i < 5; i++) {
       this.bankNotes[i] += banknotesCount[i]
    }
    return this.bankNotes
};

/**
 * @param {number} amount
 * @return {number[]}
 */
ATM.prototype.withdraw = function(amount) {
    let remain = amount
    let usedBankNotes = new Array(5).fill(0)
    let temp = [...this.bankNotes]
    for (let i = 4; i >= 0; i--) {
        if (temp[i] > 0 && remain >= this.banksNotesValue[i]) {
            const bankNote = Math.floor(remain / this.banksNotesValue[i])
            const maxCanUse = Math.min(temp[i], bankNote)
            usedBankNotes[i] = maxCanUse
            temp[i] -= maxCanUse

            remain -= maxCanUse * this.banksNotesValue[i]
        }
    }

    if (remain > 0) {
        return [-1]
    } else {
        this.bankNotes = temp
        return usedBankNotes
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * var obj = new ATM()
 * obj.deposit(banknotesCount)
 * var param_2 = obj.withdraw(amount)
 */