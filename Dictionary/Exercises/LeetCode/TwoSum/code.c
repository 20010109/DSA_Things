/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* returnArr = malloc(sizeof(int) * 2);
    *returnSize = 2;
    int i = 0, j = i+1;
    while(i < numsSize){
        returnArr[0] = i;
        returnArr[1] = j;
        printf("%d %d", returnArr[0], returnArr[1]);
        if(((nums[i] + nums[j]) == target)){
            return returnArr;
        }
        if(j == numsSize-1){
            i++;
            j = i+1;
        } else 
        if(j < numsSize){
            j++;
        }
    }
    return NULL;
}