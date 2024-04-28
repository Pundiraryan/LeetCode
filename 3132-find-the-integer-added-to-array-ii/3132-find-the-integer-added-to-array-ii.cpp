class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int ans=1e9;
        sort(nums2.begin(),nums2.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                vector<int>v;
                for(int k=0;k<n;k++){
                    if(k==i||k==j)continue;
                    v.push_back(nums1[k]);
                }
                sort(v.begin(),v.end());
                bool p=true;
                int val=nums2[0]-v[0];
                for(int i=0;i<n-2;i++){
                    if(nums2[i]-v[i]!=val){
                        p=false;break;
                    }
                }
                if(p){
                    ans=min(ans,val);
                }
            }
        }
        return ans;
    }
};