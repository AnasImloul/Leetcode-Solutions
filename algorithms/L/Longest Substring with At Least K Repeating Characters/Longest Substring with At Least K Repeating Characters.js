var longestSubstring = function(s, k) {
    let n = s.length;
    if(n == 0 || n < k)
        return 0;
    if(k == 1)
        return n;
    
    const freq = {};  // object to store the freq of each character ex . { 'a' : 2 , 'b' : 1 ...}
    
	// counting the freq. of each character
    for(let i=0;i<n;i++)  
    {
        let char = s[i];
        if(freq[char])    // if the character is already present , increase it's freq.
            freq[char]++;
        else
            freq[char] = 1; // else assign the freq. as 1
    }
    let i = 0;
    while(i < n && freq[s[i]] >= k)  // while loop continue till the freq. of character is greater than or equal to k
        i++;
    
    if(i >= n-1) // if i == string.length
        return i;
    
    let left1 = longestSubstring(s.substring(0,i),k);  // dividing the string at index where freq. of character is less than k and calling the func again on the substring
    
    while(i < n && freq[s[i]] < k) // ignore the char whose freq. is less than k
        i++;
    
    let right1 = longestSubstring(s.substring(i),k); // second part of the string
    
    return Math.max(left1,right1);
};
