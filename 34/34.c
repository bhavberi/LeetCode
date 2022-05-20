

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int* arr = (int*)calloc(2,sizeof(int));
    int found = 0;
    int start = -1;
    int end = -1;
    for(int i=0;i<numsSize;++i)
    {
        if(nums[i] == target && !found)
        {
            start = end = i;
            found=1;
        }
        else if(nums[i] == target && found)
        {
            ++end;
        }
        else if(found)
            break;
    }
    if(found == 0)
        arr[0]=arr[1]=-1;
    else
    {
        arr[0]=start;
        arr[1]=end;
    }
    return arr;

}
