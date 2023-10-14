import math 
# def minimiseMaxDistance(l: [int], k: int) -> float:
class Solution:
    def minmaxGasDist(self, l: List[int], k: int) -> float:
            # Write your code here.
        dis=[]
        n=len(l)
        for i in range(n-1):
            dis.append(l[i+1]-l[i])
        
        def ss(m):
            x=0 
            for i in dis:
                x+=math.ceil(i/m)-1 
            # print(x)
            if x<=k:
                return True 
            return False

        i=0 
        j=max(dis)
        ans=j
        while i<=j:
            # print(i,j)
            m=(i+j)/2 
            if ss(m):
                if abs(m-ans)<=0.0000001:
                    return m
                else:
                    ans=m 
                j=m-0.0000001
            else:
                i=m+0.0000001
        
        return ans
        