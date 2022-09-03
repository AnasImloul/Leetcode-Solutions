// Runtime: 27 ms (Top 57.45%) | Memory: 46.9 MB (Top 71.39%)
class Solution {
    public int numUniqueEmails(String[] emails) {

        Set<String> finalEmails = new HashSet<>();
        for(String email: emails){
            StringBuilder name = new StringBuilder();
            boolean ignore = false;
            for(int i=0;i<email.length();i++){
                char c = email.charAt(i);
                switch(c){
                    case '.':
                        break;
                    case '+':
                        ignore = true;
                        break;
                    case '@':
                        name.append(email.substring(i));
                        i = email.length();
                        break;
                    default:
                        if(!ignore) name.append(c);
                }
            }
            finalEmails.add(name.toString());
        }
        finalEmails.forEach(System.out::println);
        return finalEmails.size();
    }
}