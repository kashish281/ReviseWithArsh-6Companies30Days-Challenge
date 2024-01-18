class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n=preorder.size();
        if(preorder[0]==','){
            return false;
        }
        if(preorder[0]=='#'){
            if(n==1){
                return true;
            }
            return false;
        }
        preorder.push_back(',');
        stack<string> st;
        string temp="";
        for(int i=0;i<preorder.size();i++){
            if(preorder[i]==','){
                st.push(temp);
                while(st.size()>2){
                    string a=st.top();
                    st.pop();
                    string b=st.top();
                    st.pop();
                    string c=st.top();
                    st.pop();
                    if(a=="#" && b=="#" && c=="#"){
                        return false;
                    }
                    if(a=="#" && b=="#" && c!="#"){
                        st.push("#");
                    }else{
                        st.push(c);
                        st.push(b);
                        st.push(a);
                        break;
                    }
                }
                temp.clear();
            }    
            else{
                temp+=preorder[i];
            }
            
        }
        return st.size()==1 && st.top()=="#";

    }
};