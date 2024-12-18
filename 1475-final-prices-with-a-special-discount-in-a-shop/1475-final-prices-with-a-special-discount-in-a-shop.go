func finalPrices(prices []int) []int {
    n:=len(prices)
     ans := make([]int, n)  
    for i:=0;i<n;i++{
        ans[i]=prices[i];
        for j:=i+1;j<n;j++{
            if(prices[j]<=prices[i]){
                ans[i]=prices[i]-prices[j];
                break;
            }
        }
    }
    return ans;
}