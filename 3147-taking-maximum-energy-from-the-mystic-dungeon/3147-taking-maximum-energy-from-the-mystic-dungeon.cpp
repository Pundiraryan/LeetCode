class Solution { 
public:  
int maximumEnergy(vector<int>& energy, int k) { 
    int n=energy.size();
    int res=energy[n-1];
    for(int i=n-2;i>=0;i--){
        if(i+k<n)energy[i]+=energy[i+k];
        res=max(res,energy[i]);
    }
    return res;
}
};