// Runtime: 17 ms (Top 5.9%) | Memory: 43.57 MB (Top 5.0%)

class Solution {
    public List<Integer> partitionLabels(String s) {
        
    List<Integer>lr=new ArrayList<>();

    HashMap<Character,Boolean>mp=new HashMap<>();

    int count=0;

    for(int i=0;i<s.length();i++){

    if(!mp.containsKey(s.charAt(i))&&s.lastIndexOf(Character.toString(s.charAt(i)))!=i){
        mp.put(s.charAt(i),true);
    }
    else if(mp.containsKey(s.charAt(i))&&s.lastIndexOf(Character.toString(s.charAt(i)))==i){

    mp.remove(s.charAt(i));

    }
    
    if(mp.isEmpty()){
    lr.add(count+1);
    count=0;
    }
    else{
        count++;
    }
    }


    return lr;


    }
}