int hammingWeight(int n) {
    int bitCount = 0;
    for(int i = 0; i < sizeof(n) * 8; i++){
        if((n >> i) & 1){
            bitCount++;
        }
    }
    return bitCount;
}