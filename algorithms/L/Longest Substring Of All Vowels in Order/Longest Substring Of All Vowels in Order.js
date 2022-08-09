here i used sliding window approach

i will use two pointers slow and fast.
stack to keep track of last encountered vowel.
and also a set to keep watch if set has all 5 vowels(which means we have a valid window)
map each vowel in increamenting order.

now start moving fast pointer

there are 3 things possilbe.

1st 
stack is empty so just add given vowel

2nd
the new char which fast pointer is pointing is wether equal or has more value than vowel on top of stack than just add 
vowel to both stack and set
check if set has all 5 vowels and calculate maxlength.

3rd
we have now encountered a vowel which has less value than top of stack which means we hit our window 
so move slow pointer to fast and also decrease fast bcz lets say in this given ex. 'a e i o u a a a i'
 when fast pointer is at 5th index on line 66 fast pointer will get incremented and hence index 5 will not get processed and won't be added to stack and set. 
again check wether set has all 5 vowls or not and cal. maxlength. and clear both stack and set.

(sorry for my poor english and upvote if found helpful or downvote if felt confusing :) )

var longestBeautifulSubstring = function(word) {
  let maxLength = 0;
  let stack = [];
  let map = new Map();
  let set = new Set();
  let slow = 0,
      fast = 0;


  map.set("a", 1);
  map.set("e", 2);
  map.set("i", 3);
  map.set("o", 4);
  map.set("u", 5);


  while (fast < word.length) {

    let char = word[fast];
    if (stack.length === 0) {

      stack.push(char);
      set.add(char);

    } else if (map.get(char) >= map.get(stack[stack.length - 1])) {

      stack.push(char);
      set.add(char);
      if (set.size === 5) {
        maxLength = Math.max(maxLength, fast - slow + 1);

      }
    } else {

      slow = fast;
      fast--; 

      if (set.size === 5) {
        maxLength = Math.max(maxLength, fast - slow + 1);
      }

      stack = [];
      set.clear();

    }

    fast++;

  }
  return maxLength;
};

