class Solution {
    public: 
    int removeDuplicates(vector < int > & arr) {
        int i = 0, j = 1, n = arr.size();
        while (i < n) {
            if (i - 1 >= 0 and arr[i] <= arr[i - 1]) break;
            while (j < n and arr[j] == arr[i]) j++;
            if (i + 1 < n and j < n) arr[i + 1] = arr[j];
            i++;
        }
        return i;
    }
};