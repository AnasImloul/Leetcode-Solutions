enum LogType{
    LETTER,
    DIGIT
}
class LogFile{
    String name;
    String content;
    LogType type;
    public LogFile(String name, String content){
        this.name=name;
        this.content=content;
        this.type = getLogType();
    }
    private LogType getLogType(){
        return this.content.replace(" ","").matches("[a-z]+")?LogType.LETTER:LogType.DIGIT;
    }
}
class Solution {
    public String[] reorderLogFiles(String[] logs) {
        List<LogFile> files = new LinkedList<>();
        for(String log :logs){
            String name = log.substring(0, log.indexOf(' '));
            String content = log.substring(log.indexOf(' ') + 1);
            files.add(new LogFile(name,content));
        }
        Collections.sort(files, new Comparator<LogFile>(){
            public int compare(LogFile f1,LogFile f2){
                int typeCompare = f1.type.compareTo(f2.type);
                if(typeCompare==0 && f1.type==LogType.LETTER){
                    int contentCompare = f1.content.compareTo(f2.content);
                    if(contentCompare==0) return f1.name.compareTo(f2.name);
                    return contentCompare;
                }
                return typeCompare;
            }
        });
        String[] orderedLogs = new String[logs.length];
        for(int i=0;i<logs.length;i++){
            orderedLogs[i]=files.get(i).name+" "+files.get(i).content;
        }
        return orderedLogs;
    }
}
