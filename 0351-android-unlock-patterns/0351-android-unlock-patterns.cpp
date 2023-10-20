class Solution {
public:


int dfs(const vector<vector<int>> &jump, vector<bool> &visited, 
            int dot, int remaining_dots){
    if(remaining_dots<0){
        return 0;
    }    
    if(remaining_dots==0){
        return 1;
    }
    visited[dot] = true;
    int c=0;
    for(int dotVal=1; dotVal<=9; dotVal++){
        if(!visited[dotVal] && (!jump[dot][dotVal] || visited[jump[dot][dotVal]])){
            c+=dfs(jump, visited, dotVal, remaining_dots-1);
        }
    }
    visited[dot] = false;
    return c;
}
int numberOfPatterns(int mini, int maxi){
    vector<vector<int>> jump(10, vector<int>(10, 0));
    jump[1][3] = jump[3][1] = 2;
    jump[1][7] = jump[7][1] = 4;
    jump[3][9] = jump[9][3] = 6;
    jump[7][9] = jump[9][7] = 8;
    jump[2][8] = jump[8][2] = jump[4][6] = jump[6][4] 
    = jump[1][9] = jump[9][1] = jump[3][7] = jump[7][3] = 5;

    vector<bool> visited(10, false);
    int res=0;
    for(int dotsCount=mini; dotsCount<=maxi; dotsCount++){
        res+=(dfs(jump, visited, 1, dotsCount-1)*4);
        res+=(dfs(jump, visited, 2, dotsCount-1)*4);
        res+=(dfs(jump, visited, 5, dotsCount-1)*1);
    }
    return res;
}



};