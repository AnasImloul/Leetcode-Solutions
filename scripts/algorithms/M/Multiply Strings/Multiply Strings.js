// Runtime: 194 ms (Top 12.86%) | Memory: 49.9 MB (Top 18.17%)

var multiply = function(num1, num2) {
    const m = num1.length;
    const n = num2.length;

    const steps = [];
    let carry = 0;
    for(let i = m - 1; i >= 0; i -= 1) {
        const digitOne = parseInt(num1[i]);
        let step = "0".repeat(m - 1 - i);

        carry = 0;
        for(let j = n - 1; j >= 0; j -= 1) {
            const digitTwo = parseInt(num2[j]);

            const product = digitOne * digitTwo + carry;
            const newDigit = product % 10;
            carry = Math.floor(product / 10);

            step = newDigit + step;
        }

        if(carry > 0) step = carry + step;
        steps.push(step);
    }

    for(let i = 0; i < steps.length - 1; i += 1) {
        let nextStep = steps[i + 1];
        let step = steps[i];
        step = "0".repeat(nextStep.length - step.length) + step;

        carry = 0;
        let newStep = "";
        for(let j = step.length - 1; j >= 0; j -= 1) {
            const sum = parseInt(nextStep[j]) + parseInt(step[j]) + carry;
            const digit = sum % 10;
            carry = Math.floor(sum / 10);
            newStep = digit + newStep;
        }

        if(carry > 0) newStep = carry + newStep;
        steps[i + 1] = newStep;
    }

    let result = steps[steps.length - 1];
    let leadingZeros = 0
    while(leadingZeros < result.length - 1 && result[leadingZeros] === '0') {
        leadingZeros += 1;
    }

    return result.slice(leadingZeros);
};