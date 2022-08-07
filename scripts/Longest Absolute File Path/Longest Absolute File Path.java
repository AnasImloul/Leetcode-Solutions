class Solution {
    int ans = 0;
    public int lengthLongestPath(String input) {
        int[] fileLenths = new int[input.length()];
        for(String fileDirName: input.split("\n")) {
               //dirLevel or number of tabs in beginning of current file/dir
              int dirLevel = dirLevel(fileDirName);
              // remove leading tabs
              fileDirName = fileDirName.substring(dirLevel);
              // To find length till this dir, you need to add current dir length in the parent (dirLevel-1) length
              //+1 is for path separator '/'
              fileLenths[dirLevel] = (dirLevel > 0 ? fileLenths[dirLevel-1] + 1: 0) + fileDirName.length();
              //if file
              if(fileDirName.contains(".")) {
                  ans = Math.max(ans, fileLenths[dirLevel]);
               } 

        }
        return ans;
    }
    
    //counts number of tabs in front of the file/dire name
    int dirLevel(String dirName) {
        int count = 0;
        int i = 0;
        while(dirName.charAt(i++) == '\t') count++;
        return count;
    }
}
