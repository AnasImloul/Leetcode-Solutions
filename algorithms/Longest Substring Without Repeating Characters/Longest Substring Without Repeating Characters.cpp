
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
	
	// Base Condition
    if(n==0){
        return 0;
    }
      
    // Hashing Technique with more efficient hashing cost than map. It will take O(1) for each update
    int freq[129] = {0};
	
	// Two pointers to indicate a window
    int low = 0;
    int high = 0;
	
	// Difference between two pointers will denote the size of Window
    int maxSize = 1;
	
    // Loop of sliding window
    for (int i = 0; i < n; i++) {

      if (freq[s[i]] > 0) {
        // Duplicate is there hence slide window
		// But before sliding make sure to store the max size till now.
		maxSize = max(maxSize, high - low);

        // Adjust the information of frequency before sliding
        while (freq[s[i]] > 0) {
          freq[s[low]]--;
          low++;   // Slide the window with each increment in low pointer
		  
		  // Safety Check because string could end while increment in low pointer
          if (low >= n)
            break;
        }
      }
	  
	  // Increment the frequency of current character
      freq[s[i]]++;
	  
	  // Increase the size of window
      high++;
    }
	
	// Return the size of window
    maxSize = max(maxSize, high - low);
    return maxSize;
  }
};
