class Solution {
public:
double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
    int n1=A.size(), n2=B.size();
    // n1 should be smaller
    if(n1>n2){
        return findMedianSortedArrays(B, A);
    }

    int half = (n1+n2)/2;
    int l=0, r=n1-1;
    while(true){
        int i = floor((l+r)/2.0);
        int j = half - i - 2;
        int Aleft = (i >= 0)? A[i]:INT_MIN;
        int Aright = (i+1 < n1)? A[i+1]:INT_MAX;
        int Bleft = (j >= 0)? B[j]:INT_MIN;
        int Bright = (j+1 < n2)? B[j+1]:INT_MAX;
        
        if(Aleft <= Bright && Bleft <= Aright){
            if((n1+n2)%2!=0){
                return min(Aright, Bright);
            }else{
                return (max(Aleft,Bleft)+min(Aright,Bright))/2.0;
            }
        }

        if(Aleft > Bright){
            r=i-1;
        }else{
            l=i+1;
        }
    }

    return 0;
}
};