class Solution {
    public String reformatDate(String date) {
        int len = date.length();
        
        String[] monthArray = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        
        String year = date.substring(len - 4);
        int month = Arrays.asList(monthArray).indexOf(date.substring(len - 8, len - 5)) + 1;
        String day = date.substring(0, len - 11);
        
        StringBuffer sb = new StringBuffer();
        
        sb.append(year + "-");
        
        if(month < 10)
            sb.append("0" + month + "-");
        else
            sb.append(month + "-");
        
        if(day.length() == 1) 
            sb.append("0" + day);
        else
            sb.append(day);
        
        return sb.toString();
    }
}
