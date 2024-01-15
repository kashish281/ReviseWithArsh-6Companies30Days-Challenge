class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int r=img.size();
        int c=img[0].size();
        vector<int> temp(c);
        int prevcorner=0;
    
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int sum=0;
                int cnt=0;
                //down ke saare neigbrs
                if(i+1<r){
                    if(j-1>=0){
                        sum+=img[i+1][j-1];
                        cnt++;
                    }
                    sum+=img[i+1][j];
                    cnt++;
                    if(j+1<c){
                        sum+=img[i+1][j+1];
                        cnt++;
                    }
                }
                //just right wala bhi intact hoga to direct add krsakte
                if(j+1<c){
                    sum+=img[i][j+1];
                    cnt++;
                }
                //just left nghbr
                if(j-1>=0){
                    sum+=temp[j-1];
                    cnt++;
                }
                //current cell ko bhi add kro
                sum+=img[i][j];
                cnt++;
                //upar ke row ko add krna agr they exist
                if(i-1>=0){
                    if(j-1>=0){
                        sum+=prevcorner;
                        cnt++;
                    }
                    sum+=temp[j];
                    cnt++;
                    if(j+1<c){
                        sum+=temp[j+1];
                        cnt++;
                    }
                }
                if(i-1>=0){
                    prevcorner=temp[j];
                }
                temp[j]=img[i][j];
                img[i][j]=sum/cnt;
            }
        }
        return img;
        
    }
};