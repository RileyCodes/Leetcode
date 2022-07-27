class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        /*
                   0001 1000
            >> 1 = 0000 0110
            ABCD >> 2 00AB
            << 2      CD00
            or | 
            
            ABCDEFGH  8 BITS
            EFGHABCD  4 BITS
            GHEFCDAB  2 BITS
            
            HGFEDCBA  1 BITS
            
      @      ABCDEFGH (>> 4) | (<< 4)
            EFGHABCD  2 BITS
            00EFGHAB
            GHABCD00
            
        */
        
        
        n = n >> 16 | n << 16; 
        
        int _8bit_mask =   0b1111111100000000111111110000000011111111000000001111111100000000;
        int _8bit_mask_2 = 0b0000000011111111000000001111111100000000111111110000000011111111;
        n = (n & _8bit_mask) >> 8 | (n & _8bit_mask_2) << 8;
        
        int _4bit_mask =   0xf0f0f0f0;
        int _4bit_mask_2 = 0x0f0f0f0f;
        n = (n & _4bit_mask) >> 4 | (n & _4bit_mask_2) << 4;
        
        int _2bit_mask =   0xCCCCCCCC;
        int _2bit_mask_2 = 0x33333333;
        n = (n & _2bit_mask) >> 2 | (n & _2bit_mask_2) << 2;
        
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        
        return n;
    }
};