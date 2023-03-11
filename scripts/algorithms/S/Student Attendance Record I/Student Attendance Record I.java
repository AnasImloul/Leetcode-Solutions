class Solution {
    public boolean checkRecord(String s) {

    int size=s.length();
    if(s.replace("A","").length()<=size-2||s.indexOf("LLL")!=-1)return false;

    return true;

    }
}