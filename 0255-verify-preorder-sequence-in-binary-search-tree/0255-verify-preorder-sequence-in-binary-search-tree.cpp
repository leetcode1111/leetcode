class Solution {
public:
// preorder root, left, right
    void f(vector<int>& arr, int minVal, int maxVal){
        if(arr.empty() || arr.back()<=minVal || arr.back()>=maxVal){
            return;
        }
        int curVal = arr.back();
        arr.pop_back();
        f(arr, minVal, curVal);
        f(arr, curVal, maxVal);
    }
    bool verifyPreorder(vector<int>& arr) {
        // reversing the array for easy traversal and pop
        reverse(arr.begin(), arr.end());
        f(arr, INT_MIN, INT_MAX);
        // pop the element while valid bst else not valid if there any element left
        return arr.empty();
    }
};