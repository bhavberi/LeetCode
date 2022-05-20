

int findDuplicate(int* nums, int numsSize){
    int *array = (int *)calloc(numsSize, sizeof(int));
    for(int i=0;i<numsSize;++i)
    {
        array[nums[i]]+=1;
    }
    for(int i=1;i<numsSize;++i)
    {
        if(array[i] > 1)
            return i;
    }
    return 0;

}
