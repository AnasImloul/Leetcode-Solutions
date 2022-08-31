// Runtime: 14 ms (Top 11.69%) | Memory: 42.5 MB (Top 40.28%)
class Solution {
    public String reorganizeString(String s) {
        StringBuilder ans=new StringBuilder("");
        char[] charArray=new char[s.length()];
        Map<Character,Integer> hashMap=new HashMap<>();
        Queue<CharOccurence> queue=new PriorityQueue<>((a,b)->b.occurence-a.occurence);

        charArray=s.toCharArray();

        for(int i=0;i<charArray.length;i++)
        {
            Integer occurence=hashMap.get(charArray[i]);
            if(occurence==null)
                hashMap.put(charArray[i],1);
            else
                hashMap.put(charArray[i],occurence+1);
        }
        queue.addAll(hashMap.entrySet()
                     .stream()
                     .parallel()
                     .map(e->new CharOccurence(e.getKey(),e.getValue()))
                     .collect(Collectors.toList()));
        while(!queue.isEmpty())
        {
            Queue<CharOccurence> tmpQueue=new LinkedList<>();
            int sizeQueue=queue.size();
            int stringLength=ans.length();
            int startSub=(stringLength-1<0)?0:stringLength-1;
            int endSub=stringLength;
            String lastLetter=ans.substring(startSub,endSub);
            boolean letterAdded=false;
            for(int i=0;i<sizeQueue;i++)
            {
                CharOccurence letter=queue.poll();
                if(!lastLetter.contains(String.valueOf(letter.letter)))
                {
                    letter.occurence--;
                    ans.append(String.valueOf(letter.letter));
                    if(letter.occurence>0)
                        tmpQueue.add(letter);
                    letterAdded=true;
                    break;
                }
                else
                {
                    tmpQueue.add(letter);
                }
            }
            if(!letterAdded)
                return "";
            queue.addAll(tmpQueue);
        }
        return ans.toString();

    }
    class CharOccurence{
        public Character letter;
        public int occurence;
        public CharOccurence(Character letter, int occurence)
        {
            this.letter=letter;
            this.occurence=occurence;
        }
    }
}