class Solution {
public:
    void sortColors(vector<int>& arr) {
         int ptr1 = -1,pt2 = arr.size() - 1;
 for(int i = 0;i <= pt2;i++)
 {
    if(arr[i] == 0)
    {
        ptr1++;
        swap(arr[i],arr[ptr1]);
    }
    else if(arr[i] == 2)
    {
        swap(arr[i],arr[pt2]);
        pt2--;
        i--;
    }

 }


}
};