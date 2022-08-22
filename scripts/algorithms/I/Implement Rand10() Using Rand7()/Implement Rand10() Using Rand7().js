// Runtime: 132 ms (Top 65.91%) | Memory: 50.3 MB (Top 43.18%)
var rand10 = function() {
    while (true) {
        const rand49 = (rand7() - 1) * 7 + rand7();
        if (rand49 <= 40) return rand49 % 10 + 1;

        const rand9 = rand49 - 40;
        const rand63 = (rand9 - 1) * 7 + rand7();
        if (rand63 <= 60) return rand63 % 10 + 1;

        const rand3 = rand63 - 60;
        const rand21 = (rand3 - 1) * 7 + rand7();
        if (rand21 <= 20) return rand21 % 10 + 1;
    }
};