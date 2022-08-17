var loudAndRich = function(richer, quiet) {
    const map = new Map();
    for (const [rich, poor] of richer) {
        map.set(poor, (map.get(poor) || new Set()).add(rich));        
    }
    
    const memo = new Map();
    const getQuietest = (person) => {
        if (memo.has(person)) return memo.get(person);
        const richerList = map.get(person);
        let min = quiet[person];
        let quietest = person;
        if (!richerList) {
            memo.set(person, quietest);
            return quietest;
        }
        for (const rich of richerList) {         
            if (quiet[getQuietest(rich)] < min) {
                min = quiet[getQuietest(rich)];
                quietest = getQuietest(rich);
            }            
        }
        memo.set(person, quietest);
        return quietest;
    }
    const answer = [];
    for (let i=0; i<quiet.length; i++) {
        answer.push(getQuietest(i));
    }
    return answer;
};
