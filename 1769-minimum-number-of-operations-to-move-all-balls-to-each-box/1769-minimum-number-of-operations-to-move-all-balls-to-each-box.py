class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n=len(boxes);
        l=[];
        for i in range(n):
            val=0;
            for j in range(n):
                if(boxes[j]=='1'):
                  val=val+abs(i-j); 
            l.append(val);
        return l;