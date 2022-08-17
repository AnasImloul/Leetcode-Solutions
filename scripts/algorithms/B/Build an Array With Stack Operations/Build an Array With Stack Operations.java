class Solution {
    public List<String> buildArray(int[] target, int n) {
      List<String> result=new ArrayList<>();
        int i=1,j=0;
        while(j<target.length)
        {
            result.add("Push");
            if(i==target[j]){
                j++;
            }else{
                result.add("Pop");
            }
            i++;
        }
        return result;
    }
}
