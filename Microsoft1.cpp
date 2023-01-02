//Using if else
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n=tokens.size();
        for(string& s:tokens){
            if(s=="+"){
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                st.push(a+b);
            }
            else if(s=="-"){
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                st.push(a-b);
            }
            else if(s=="*"){
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                st.push(a*b);
            }
            else if(s=="/"){
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                st.push(a/b);
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};

//Using Switch Case
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n=tokens.size();
        for(string& s:tokens){
            if(s.size()>1 || isdigit(s[0]))st.push(stoi(s));
            else{
                int s2=st.top();
                st.pop();
                int s1=st.top();
                st.pop();
                switch(s[0]){
                    case '+': s1+=s2; break;
                    case '-': s1-=s2; break;
                    case '*': s1*=s2; break;
                    case '/': s1/=s2; break;
                }
                st.push(s1);
            }
        }
        return st.top();
    }
};