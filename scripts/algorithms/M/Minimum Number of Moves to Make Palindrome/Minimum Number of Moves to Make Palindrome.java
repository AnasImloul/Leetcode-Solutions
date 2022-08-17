class Solution {

	public int minMovesToMakePalindrome(String s) {
		int len = s.length();
		char[] strArr = s.toCharArray();        
		int steps = 0;
		int l = 0, r = len-1;                                           // use two pointers l for left and r for right. 

		while(l < r){            
			if(strArr[l] == strArr[r]){                                 // Both characters are equal. so keep going futher.
				l++; r--;
			}else{                                                      // Both characters are not equal.    
				int k = r;
				k = findKthIndexMatchingwithLthIndex(strArr, l, k);     // loop through k, until char at index k = char at index l              

				if(k == l){                                             // we did not find any char at k = char at index l    
					swap(strArr, l);
					steps++;   
				}else{                                                  
					while(k < r){                                           
						swap(strArr, k);
						steps++;
						k++;
					}
					l++; r--;
				}                
			}// end of else

		}   // end of while
		System.out.println("palindrome: "+String.valueOf(strArr));
		return steps;

	}

	public int findKthIndexMatchingwithLthIndex(char[] strArr, int l, int k){
		while(k > l){
			if(strArr[k] == strArr[l]){  return k;  }                    
			k--;
		}
		return k;
	}

	public void swap(char[] strArr, int l){
		if(l+1 < strArr.length){
			char tempCh = strArr[l];
			strArr[l] = strArr[l+1];
			strArr[l+1] = tempCh;
		}
	}
}
