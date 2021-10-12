// Implement a simple text editor. The editor initially contains an empty string 's'. Perform 'q' operations of the following  4 types:

// 1.append(w) - Append string 'w' to the end of 's'.
// 2.delete(k) - Delete the last 'k' characters of 's'.
// 3.print(k) - Print the kth character of 's'.
// 4.undo() - Undo the last (not previously undone) operation of type  or , reverting 's' to the state it was in prior to that operation.



#include <bits/stdc++.h>
using namespace std;
int main() {
    int q;
    cin>>q;
    string s;string r,e;
    stack<int> st;
    while(q--)
    {
        int t;
        cin>>t;
        st.push(t);
        if(t==1)
        {
           cin>>r; 
           s=s+r;
        }
        else if (t==2) {
        int k;
        cin>>k;
        for(int i=s.length()-1;i>=s.length()-k;i--)
        {e=s[i]+e;
             s[i]='\0';
        }
        }
        else if(t==3)
        {
            int l;
            cin>>l;
            cout<<s[l-1]<<endl;
        }
        else {
        if(st.top()==1)
        {
            for(int i=s.length()-1;i>=s.length()-r.length();i--)
            {
                s[i]='\0';
            }
            st.pop();
        }
        else if(st.top()==2)
        {
            s=s+e;
            st.pop();
        }
        }
        
    }
    return 0;
}
