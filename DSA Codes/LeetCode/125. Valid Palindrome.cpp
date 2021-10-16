//Dev Wadhwa

class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(isalnum(s[i]))
            {
                s[i]=tolower(s[i]);
                temp+=s[i];
            }
        }
        string check=temp;
        reverse(check.begin(),check.end());
        if(check==temp) return true;
        else return false;
    }
};
