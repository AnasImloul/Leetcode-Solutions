let numberMap = {
	0: 'Zero',
  100: 'Hundred',
  1: 'One',
  2: 'Two',
  3: 'Three',
  4: 'Four',
  5: 'Five',
  6: 'Six',
  7: 'Seven',
  8: 'Eight',
  9: 'Nine',
  10: 'Ten',
  11: 'Eleven',
  12: 'Twelve',
  13: 'Thirteen',
  14: 'Fourteen',
  15: 'Fifteen',
  16: 'Sixteen',
  17: 'Seventeen',
  18: 'Eighteen',
  19: 'Nineteen',
  20: 'Twenty',
  30: 'Thirty',
  40: 'Forty',
  50: 'Fifty',
  60: 'Sixty',
  70: 'Seventy',
  80: 'Eighty',
  90: 'Ninety'
};

let bigNumberMap = {
	1000000000: 'Billion',
  1000000: 'Million',
  1000: 'Thousand',
  1: 'One'
}

let bases = [];

for (let base in numberMap) {
	bases.push(parseInt(base, 10));
}
bases = bases.sort((a,b) => b-a);

let bigBases = [];
for (let base in bigNumberMap) {
	bigBases.push(parseInt(base, 10));
}
bigBases = bigBases.sort((a,b) => b-a);

var numberToWords = function(num) {
    let res = '';
    if (num === 0) return numberMap[num];
   	bigBases.forEach((base) => {
    	base = parseInt(base, 10);
      let baseAsString = base + '';
      let nums = num/base << 0;
      let remainder = num - nums * base;
      if (nums >= 1) {
    		[res, nums] = getForHundredBase(res, nums);
        res += baseAsString.length > 1 ? (' ' + bigNumberMap[base + '']) : '';
        num = remainder;
      }
    });
    return res;
};

function getForHundredBase(res, num) {
		bases.forEach((base) => {
    	base = parseInt(base, 10);
    	[num, res] = getNums(num, base, res);
    });
    return [res, num];
}

function getNums(num, base, res) {
	let nums = num / base << 0;
  let baseAsString = base + '';
  if (nums > 1 || (nums == 1 && baseAsString.length > 2)) {
  	res += res === '' ? res : " ";
  	res += numberMap[nums] + " " + numberMap[baseAsString];
  } else if (nums == 1) {
  	res += res === '' ? res : " ";
  	res += numberMap[baseAsString];
  }
  return [num - (nums * base), res];
}


