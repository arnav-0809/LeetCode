class Solution {
public:
    void mergeS(vector<int>&nums,vector<int>&temp,int l,int mid,int r,int&count){
        int s=mid;
        for(int i=l;i<mid;i++){
            while(s<=r && nums[i]>2LL*nums[s]){
                s++;
            }
            count+=s-mid;
        }
        int i=l,j=mid,k=l;
        while(i<mid && j<=r){
            if(nums[i]<=nums[j]){
                temp[k++]=nums[i++];
            }else{
                temp[k++]=nums[j++];
            }
        }
        
        while(i<mid){
            temp[k++]=nums[i++];
        }
        
        while(j<=r){
            temp[k++]=nums[j++];
        }
        
        for(int m=l;m<=r;m++){
            nums[m]=temp[m];
        }
        
    }
    
    void merge(vector<int>&nums,vector<int>&temp,int l,int r,int&count){
        if(l<r){
            int mid=(l+r)/2;
            merge(nums,temp,l,mid,count);
            merge(nums,temp,mid+1,r,count);
            mergeS(nums,temp,l,mid+1,r,count);
        }
    }
    
    
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(n);
        int count=0;
        merge(nums,temp,0,n-1,count);
        return count;
    }
};