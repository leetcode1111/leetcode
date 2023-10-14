class Solution {
public:

// giving tle
// double minmaxGasDist(vector<int> &arr, int k){
//     int n=arr.size();
//     vector<int> stationCount(n-1, 0);
//     priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
//     for(int i=1; i<n; i++){
//         pq.push({arr[i]-arr[i-1], i-1});
//     }
//     for(int i=0; i<k; i++){
//         int befInd = pq.top().second;
//         pq.pop();
//         stationCount[befInd]++;
//         pq.push({(arr[befInd+1] - arr[befInd])/(double)(stationCount[befInd]+1), 
//                     befInd});
//     }
//     return pq.top().first;
// }
bool hasDecimal(long double num) {
    // Calculate the integer part of the number
    long long intPart = num;

    // Calculate the fractional part of the number
    long double fractionalPart = num - intPart;

    // Check if the fractional part is greater than 0
    return fractionalPart > 0;
}
int isRequiredGasStationMoreThanK(vector<int> &arr, int k, long double maxDist){
    int c=0;
    for(int i=1; i<arr.size(); i++){
        long double inBetweenStation = (arr[i]-arr[i-1])/maxDist;
        c+=inBetweenStation;
        if(!hasDecimal(inBetweenStation)){
            c--;
        }
        // if(c>k){
        //     return true;
        // }
    }
    return c;    
}
double minmaxGasDist(vector<int> &arr, int k){
    long double l=0, h=0;
    for(int i=1; i<arr.size(); i++){
        h=max(h, (long double)arr[i]-arr[i-1]);
    }
    while((h-l) > (1e-6)){
        long double m = (l+h)/2.0;
        if(isRequiredGasStationMoreThanK(arr, k, m)>k){
            l=m;
        }else{
            h=m;
        }
    }
    return h;
}
};