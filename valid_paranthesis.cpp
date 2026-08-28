class Solution {
public:
int flag=0;
    bool isValid(string s) {
        string temp="";
        for(int i=0;i<s.length();i++)
        {
            char c=s[i];
            if(c=='(' || c=='{' || c=='[')
            {
               temp+=c;
            }
            else
            {
                if(temp.empty())return false;
                char back=temp[temp.length()-1];
                if(c==')' && back!='(' || c=='}' && back!='{' || c==']' && back!='[')
                {
                    return false;
                }
                temp.pop_back();

            }
            
        }
        return temp.empty();
    };
        
};