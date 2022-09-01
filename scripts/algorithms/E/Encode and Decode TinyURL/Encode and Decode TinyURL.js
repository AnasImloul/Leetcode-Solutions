// Runtime: 78 ms (Top 87.43%) | Memory: 43.8 MB (Top 68.26%)
let arr = new Array();
let size = 0;

var encode = function(longUrl) {
    arr.push(longUrl)
    let i = longUrl.indexOf('/',11);
    longUrl.slice(i);
    longUrl += this.size;
    arr.push(longUrl);
    size += 2;
    return longUrl;
};

var decode = function(shortUrl) {
    let i = 0;
    while(arr[i] !== shortUrl && i<size){
        i++;
    }
    return arr[i-1];
};