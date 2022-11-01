class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3)
            return false;
        if(arr[0] > arr[1])
            return false;
        int count=0;
        for(int i=0; i<arr.size()-1; i++)
        {
            if(arr[i] == arr[i+1])
                return false;
            if(arr[i] > arr[i+1])
                count++;
            if(count>0 && arr[i] < arr[i+1])
                return false;
        }
        if(count == 0)
            return false;
        return true;
    }
};