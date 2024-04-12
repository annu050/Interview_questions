class Solution {
public:
//brute is min(leftmaxheight,rightmaxheight)-a[i]  water stored at each index
//use of prefixmax and suffixmax then use the formula TC:O(N) 
    int trap(vector<int>& heights) {
        //using two pointer approach like find the highest height from left 
        // side and right side and for sum add the max side - height[current] one
        // int w=0;
         int n=heights.size();
        // int lmax=height[0];             
        // int rmax=height[n-1];
        // int lpos=1;
        // int rpos=n-2;
        // while(lpos<=rpos){
        //     if(height[lpos]>=lmax){
        //         lmax=height[lpos];//find max from left
        //         lpos++;
        //     }
        //     else if(height[rpos]>= rmax){
        //         rmax=height[rpos];//max from right
        //         rpos--;
        //     }
        //     else if(lmax<=rmax && height[lpos]<lmax){// if left max is min. 
        //         w+=lmax-height[lpos];//then subtrect with its current pos in arrray.
        //         lpos++;
        //     }
        //     else{
        //         w+=rmax-height[rpos];
        //         rpos--;
        //     }
        // }
        // return w;
    int left = 0, right = n - 1, water = 0;
 
    int maxLeft = heights[left];
    int maxRight = heights[right];
 
    while (left < right)
    {
        if (heights[left] <= heights[right])
        {
            left++;
            maxLeft = max(maxLeft, heights[left]);
            water += (maxLeft - heights[left]);
        }
        else 
        {
            right--;
            maxRight = max(maxRight, heights[right]);
            water += (maxRight - heights[right]);
        }
    }
 
    return water;
    }
};


