#include <math.h>

// 1st Try - not good
bool isPowerOfTwo(int n) {
    for(int i = 0; i < 31; i++){
        if((pow(2,i) == n)){
            return true;
        }
    }
    return false;
}

// 2nd Try - Optimized
bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0)
}