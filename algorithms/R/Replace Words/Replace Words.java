class Solution {
public:
    class trii{
        public:
        char data;
        trii* dict[26];
        bool isTerminal;
        
        trii(){
            
        }
        
        trii(char d){
           data=d;
            for(int i=0;i<26;i++){
                dict[i]=NULL;
            }
            isTerminal=false;
        }
    };
    
    class tree{
        public:
        trii* root;
        tree(){
            root=new trii('\0');
        }
        
        void insert(string str,trii* node){
            if(str.size()==0){
                node->isTerminal=true;
                return;
            }
            int index=str[0]-'a';
            if(node->dict[index]==NULL ){
                node->dict[index]=new trii(str[0]);
            }
            insert(str.substr(1),node->dict[index]);
        }
        
        string find(string str,trii* node,string pre){
            if( node->isTerminal==true ){
                return pre; 
            }            
            int index=str[0]-'a';
            if(str.size()==0 || node->dict[index]==NULL){
                return "\0";
            }
           return find(str.substr(1),node->dict[index],pre+str[0]);
        }
        
        string replaceWith(string word ,trii* node){
            string temp=find(word,node,"");
            if(temp!="\0"){
                word=temp;
            }
            return word;
        }
    };
    
    string replaceWords(vector<string>& dictionary, string sentence) {
       tree* t=new tree();
        for(int i=0;i<dictionary.size();i++){
            t->insert(dictionary[i],t->root);
        }
        string ans=sentence;
        sentence="";
        for(int i=0;i<ans.size();i++){
            string word="";
            while(i<ans.size()&&ans[i]!=' '){
                word+=ans[i];
                i++;
            }
            
            sentence+=t->replaceWith(word,t->root)+" ";
        }
        sentence.pop_back();
        return sentence;
    }
};

