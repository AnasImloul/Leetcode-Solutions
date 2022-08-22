// Runtime: 6 ms (Top 13.25%) | Memory: 6.1 MB (Top 79.18%)
class Solution {
public:
    int strongPasswordChecker(string password) {

if (password.size()<=2) return (6-password.size());
    else
    {
        //is first condition met?
        int sizeissue=0;
        if (password.size()<6)
            sizeissue=password.size()-6;
        else if(password.size()>20) sizeissue=password.size()-20;

        //is second condition met?
        int chtype=0, u=1,l=1,d=1;

        if(none_of(password.begin(), password.end(), &::isupper)) { chtype++; u=0;}
        if(none_of(password.begin(), password.end(), &::islower)) { chtype++; l=0;}
        if(none_of(password.begin(), password.end(), &::isdigit)) { chtype++; d=0;}

        //is the third condition met? Note there are 26 letter, the string is constrained under 50, so realistically you can always find some 'other' character not included previously in the string to break the password apart so the consecutive characters are split apart. So need to find the largest sets of consecutive characters or 'blocks', and for these the min is (size of block (-1 if even)/2?
        unsigned int output=0, i=0, start,end,issuethree=0;
        char c;

        if (sizeissue<0)
            {
                while (i<(password.size()-2))
                { if (password[i]==password[i+1]&&password[i]==password[i+2])
                    { start=i;
                        c=password[i]; i++;
                        while (c==password[i+2]&&i<(password.size()-2)) i++;
                        end=i+1;
                        i=end+1;

                        //what would the amount of changes be needed?

                        issuethree=(end-start+1)/3;

                        // add the latest issue to total output
                        output=output+issuethree;

                        // check if the missing second condition issue could resolve any of this
                        if(chtype>=1)
                        {if(islower(c)&&(u==0)) {chtype--;u=1; issuethree--; if(sizeissue<0) sizeissue++; }
                        if(islower(c)&&(d==0)&&issuethree>0) {chtype--;d=1;issuethree--; if(sizeissue<0) sizeissue++; }

                        if(isupper(c)&&(l==0)) {chtype--;l=1;issuethree--; if(sizeissue<0) sizeissue++; }
                        if(isupper(c)&&(d==0)&&issuethree>0) {chtype--;d=1;issuethree--; if(sizeissue<0) sizeissue++; }

                        if(isxdigit(c)&&(l==0)) {chtype--;l=1;issuethree--;}
                        if(isxdigit(c)&&(u==0)&&issuethree>0) {chtype--;u=1;issuethree--; if(sizeissue<0) sizeissue++; }

                        if(c=='!'&&(u==0)) {chtype--;u=1; issuethree--; if(sizeissue<0) sizeissue++; }
                        if(c=='!'&&(d==0)&&issuethree>0) {chtype--;d=1;issuethree--; if(sizeissue<0) sizeissue++; }
                        if(c=='!'&&(l==0)&&issuethree>0) {chtype--;l=1;issuethree--; if(sizeissue<0) sizeissue++; }

                        if(c=='.'&&(u==0)) {chtype--;u=1; issuethree--; if(sizeissue<0) sizeissue++; }
                        if(c=='.'&&(d==0)&&issuethree>0) {chtype--;d=1;issuethree--; if(sizeissue<0) sizeissue++; }
                        if(c=='.'&&(l==0)&&issuethree>0) {chtype--;l=1;issuethree--; if(sizeissue<0) sizeissue++; }
                        }

                        //check first issue would resolve this
                        if((-sizeissue)<=issuethree) sizeissue=0; //e.g. aaa
                        else sizeissue=sizeissue+issuethree; //don't think this option is possible?

                    }
                    else i++;
                }
                if (chtype>0 && sizeissue<0)
                    {if (chtype>abs(sizeissue)) sizeissue=0;
                    else sizeissue=sizeissue+chtype;}
            }

        else if (sizeissue==0)
                {while (i<(password.size()-2))
                    { if (password[i]==password[i+1]&&password[i]==password[i+2])
                        { start=i;
                            c=password[i]; i++;
                            while (c==password[i+2]&&i<(password.size()-2)) i++;
                            end=i+1;
                            i=end+1;

                            //what would the amount of changes be needed?

                            issuethree=(end-start+1)/3;

                            // add the latest issue to total output
                            output=output+issuethree;

                            // check if the missing second condition issue could resolve any of this
                            if(chtype>=1)
                            {if(islower(c)&&(u==0)) {chtype--;u=1; issuethree--; if(sizeissue<0) sizeissue++; }
                            if(islower(c)&&(d==0)&&issuethree>0) {chtype--;d=1;issuethree--; if(sizeissue<0) sizeissue++; }

                            if(isupper(c)&&(l==0)) {chtype--;l=1;issuethree--; if(sizeissue<0) sizeissue++; }
                            if(isupper(c)&&(d==0)&&issuethree>0) {chtype--;d=1;issuethree--; if(sizeissue<0) sizeissue++; }

                            if(isxdigit(c)&&(l==0)) {chtype--;l=1;issuethree--;}
                            if(isxdigit(c)&&(u==0)&&issuethree>0) {chtype--;u=1;issuethree--; if(sizeissue<0) sizeissue++; }

                            if(c=='!'&&(u==0)) {chtype--;u=1; issuethree--; if(sizeissue<0) sizeissue++; }
                            if(c=='!'&&(d==0)&&issuethree>0) {chtype--;d=1;issuethree--; if(sizeissue<0) sizeissue++; }
                            if(c=='!'&&(l==0)&&issuethree>0) {chtype--;l=1;issuethree--; if(sizeissue<0) sizeissue++; }

                            if(c=='.'&&(u==0)) {chtype--;u=1; issuethree--; if(sizeissue<0) sizeissue++; }
                            if(c=='.'&&(d==0)&&issuethree>0) {chtype--;d=1;issuethree--; if(sizeissue<0) sizeissue++; }
                            if(c=='.'&&(l==0)&&issuethree>0) {chtype--;l=1;issuethree--; if(sizeissue<0) sizeissue++; }

                            }

                         }
                        else i++;

                    }
                }

        else if (sizeissue>0)
                {int v[3],mod;
                    v[0]=0; v[1]=0; v[2]=0;
                    //have a vector where it says how many extra characters at the end of a block; e.g. aaa aa = v[2]=1; and in issue three how many blocks;
                    while (i<(password.size()-2))
                        { if (password[i]==password[i+1]&&password[i]==password[i+2])
                            { start=i;
                                c=password[i]; i++;
                                while (c==password[i+2]&&i<(password.size()-2)) i++;
                                end=i+1;
                                i=end+1;

                                issuethree=issuethree+(end-start+1)/3;
                                mod=(end-start+1)%3;
                                v[mod]=v[mod]+1;
                                }

                            else i++;
                        }
                    output=issuethree;

                    //delete efficiently to ensure most 'blocks of 3' are removed.
                    while (sizeissue>=1&&v[0]>0)
                    {sizeissue=sizeissue-1; v[0]--; issuethree--;}
                    while (sizeissue>=2&&v[1]>0)
                    {sizeissue=sizeissue-2; v[1]--; output=output+1; issuethree--;}
                    while (sizeissue>=3&&v[2]>0)
                    {sizeissue=sizeissue-3; v[2]--; output=output+2; issuethree--;}
                    while(sizeissue>=3&&issuethree>0)
                    {sizeissue=sizeissue-3; issuethree--; output=output+2;}

                    i=0;
                        // check if the missing second condition issue could resolve any of this
                    {while (i<(password.size()-2) && issuethree>0)
                        { if (password[i]==password[i+1]&&password[i]==password[i+2])
                            { start=i;
                                c=password[i]; i++;
                                while (c==password[i+2]&&i<(password.size()-2)) i++;
                                end=i+1;
                                i=end+1;

                                // check if the missing second condition issue could resolve any of this
                                if(chtype>=1)
                                {if(islower(c)&&(u==0)) {chtype--;u=1; issuethree--; if(sizeissue<0) sizeissue++; }
                                    if(islower(c)&&(d==0)&&issuethree>0) {chtype--;d=1;issuethree--; if(sizeissue<0) sizeissue++; }

                                    if(isupper(c)&&(l==0)) {chtype--;l=1;issuethree--; if(sizeissue<0) sizeissue++; }
                                    if(isupper(c)&&(d==0)&&issuethree>0) {chtype--;d=1;issuethree--; if(sizeissue<0) sizeissue++; }

                                    if(isxdigit(c)&&(l==0)) {chtype--;l=1;issuethree--;}
                                    if(isxdigit(c)&&(u==0)&&issuethree>0) {chtype--;u=1;issuethree--; if(sizeissue<0) sizeissue++; }

                                    if(c=='!'&&(u==0)) {chtype--;u=1; issuethree--; if(sizeissue<0) sizeissue++; }
                                    if(c=='!'&&(d==0)&&issuethree>0) {chtype--;d=1;issuethree--; if(sizeissue<0) sizeissue++; }
                                    if(c=='!'&&(l==0)&&issuethree>0) {chtype--;l=1;issuethree--; if(sizeissue<0) sizeissue++; }

                                    if(c=='.'&&(u==0)) {chtype--;u=1; issuethree--; if(sizeissue<0) sizeissue++; }
                                    if(c=='.'&&(d==0)&&issuethree>0) {chtype--;d=1;issuethree--; if(sizeissue<0) sizeissue++; }
                                    if(c=='.'&&(l==0)&&issuethree>0) {chtype--;l=1;issuethree--; if(sizeissue<0) sizeissue++; }

                                }

                            }
                            else i++;

                        }
                    }

                }

        //add all other changes remaining to be done
        output=output+chtype+abs(sizeissue);

        return output;

    }

    }

   };
