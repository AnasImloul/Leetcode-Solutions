class Solution {
    public int maxEnvelopes(int[][] envelopes) {
		//sort the envelopes considering only width
        Arrays.sort(envelopes, new sortEnvelopes());
		
		//Now this is a Longest Increasing Subsequence problem on heights
		//tempList to store the temporary elements, size of this list will be the length of LIS 
        ArrayList<Integer> tempList = new ArrayList<>();
        tempList.add(envelopes[0][1]);
		
        for(int i=1; i<envelopes.length; i++){
            if(envelopes[i][1]>tempList.get(tempList.size()-1)){
                tempList.add(envelopes[i][1]);
            } else{
			//if the element is smaller than the largest(last because it is sorted) element of tempList, replace the largest smaller element of tempList with it..
			//ex->(assume if envelopes[i][1] is 4), then >>[1,7,8] will become [1,4,8]<<
                int index = lowerBound(tempList, envelopes[i][1]);
                tempList.set(index, envelopes[i][1]);
            }
        }
        return tempList.size();
    }
    
	//finding the index of greatest smaller element 
    public int lowerBound(ArrayList<Integer> list, int search){
        int start = 0;
        int end = list.size()-1;
        while(start<end){
            int mid = start + (end-start)/2;
            if(list.get(mid) < search){
                start = mid+1;
            } else{
                end = mid;
            }
        }
        return start;
    }
}

class sortEnvelopes implements Comparator<int[]> {
    public int compare(int[] a, int[] b){
        if(a[0] == b[0]){
		//to ignore the duplicates, we are sorting such that, for same width-> element with 
		//largest height would be considered first, in this way all the other smaller heights would
		//be ignored
            return b[1] - a[1];
        } else{
            return a[0] - b[0];
        }
    }
}
