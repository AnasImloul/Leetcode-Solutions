var canFormArray = function(arr, pieces) {
	let total = "";
    arr=arr.join("");
    for (let i = 0; i < pieces.length; i++) {
      pieces[i] = pieces[i].join("");
      total += pieces[i];
      if (arr.indexOf(pieces[i]) == -1) return false;
    }
    return total.length == arr.length;
};
