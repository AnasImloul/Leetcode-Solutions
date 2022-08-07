class Solution {
public:

    string convertCombination(int *c, int k)
    {
        int hours=0;
        int minutes=0;

        for(int i=0;i<k;i++)
        {
            int indicatorIdx = c[i];
            switch(indicatorIdx)
            {
                case 0:
                hours+=8;
                break;

            case 1:
                hours +=4;
            break;

            case 2:
                hours +=2;

            break;

            case 3:
                hours +=1;

            break;

            case 4:
                minutes += 32;
            break;

            case 5:
                minutes += 16;

            break;
            case 6:
                minutes += 8;

            break;
            case 7:
                minutes += 4;

            break;
            case 8:
                minutes += 2;

            break;
            case 9:
                minutes += 1;

            break;

            }
        }
        if(hours>11 || minutes > 59) return ""; // invalid time
        return (to_string(hours)+":"+to_string(minutes/10)+to_string(minutes%10));
    }


    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>result;

        int k = turnedOn;

        int c[10];
        std::iota(begin(c),begin(c)+k,0);

        constexpr int N = 10;

        int count = 0;
        string str = convertCombination(c, k);
        if(!str.empty()) result.push_back(str);
//        print(c,k,str);
        while(true)
        {
            // go to the next combination
            int alter_idx = 0; // count from the right digit
            while(alter_idx<k && c[k-alter_idx-1]==(N-1-alter_idx)) alter_idx++;
            if(alter_idx == k) break;
            c[k-alter_idx-1]++;
            for(int i=0;i<alter_idx;i++) c[k-alter_idx+i]=c[k-alter_idx-1]+1+i;
            str = convertCombination(c, k);
            if(!str.empty()) result.push_back(str);
//            print(c,k,str);
        }
        return result;

    }

    void print(int *c, int k, string s)
    {
        if(s.empty()) return;
        for(int i=0;i<k;i++) cout << c[i];
        cout << " : " << s << endl;
    }

};
