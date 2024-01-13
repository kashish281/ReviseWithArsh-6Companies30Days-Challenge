string encode(string src)
{
    string ans="";
    int cnt=1;
    for(int i=0;i<src.size();i++){
        if(src[i]==src[i+1]){
            cnt++;
        }
        else{
            ans+=src[i]+to_string(cnt);
            cnt=1;
        }
    }
    return ans;
}     