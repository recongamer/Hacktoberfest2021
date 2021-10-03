class Solution {
public:
    bool isPair(char a, char b){
        if((a == '(') && (b == ')'))
            return true;
        else if((a == '{') && (b == '}'))
            return true;
        else if((a == '[') && (b == ']'))
            return true;
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(st.empty())
                st.push(s[i]);
            else if(isPair(st.top(), s[i]))
                st.pop();
            else
                st.push(s[i]);
        }
        if(!st.empty())
            return false;
        return true;
    }
};
