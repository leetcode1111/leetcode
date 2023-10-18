def sss(l):
    n=len(l)
    m=len(l[0])
    d={"":l[:]}
    for i in range(n):
        for j in range(1,m+1):
            s=l[i][:j]
            if s not in d:
                d[s]=[]
            d[s].append(l[i])
    # print(d)
    ans=[]
    
    def ss(i,tt):
        t=tt[:]
        if i>=m:
            ans.append(t)
            return 
        s=t[i][:i]
        # x=0
        # for j in range(m):
        #     if t[j][:i]==s:
        #         x+=1 
         
        # print(i,t,s)
        if s not in d :
            return 
        
        else:
            for p in d[s]:
                t=tt[:]
                for j in range(i,m):
                    t[j] = t[j][:i]+p[j]+"."*(m-i-1)
                t[i]=p 
                ss(i+1,t)
           
    ss(0,["."*m]*m)           
    return ans

class Solution:
    def wordSquares(self, words: List[str]) -> List[List[str]]:
        return sss(words)
        