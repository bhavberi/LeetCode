int hammingWeight(uint32_t n) {
    int count = 0;
    unsigned z = 1;
    for(unsigned i=0;i<32;++i)
        if(n & z<<i)
            ++count;
    return count;
}
