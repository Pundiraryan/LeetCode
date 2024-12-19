func maxChunksToSorted(arr []int) int {
    ans:=0;
    maxi:=-1;
    n:=len(arr)
    for i:=0;i<n;i++ {
        maxi=max(maxi,arr[i]);
        if maxi==i{
           ans++;   
        }
    }
    return ans;
}