#include "crytox.h"



int generate_key( uint8_t* buf, int64_t GetTickCount, PConf* pConf) {
    // IDA register variables
    __int64_t v2; // rsi 
    __int64_t hash;  // rax
    __int64_t i; // rcs MAPDST
    __int64_t j; // rcs
    uint64_t tmp_hash; // rax
    uint64_t v7; // rbx
    __uint128_t result;

    // This is used twice. But the important one is when we set temp_hash to get our next random value
    hash = GetTickCount;

    // This loop got fucking unrolled by the compiler. 4 sets of 64 is 256
    for(i = 4; i != -1;  --i)
    {
        j = 64;
        do
        {
            // Bump our next random number
            tmp_hash = 0x7D6C3 * (pConf->random_generated + hash) + 0x159EC7;
            pConf->random_generated = tmp_hash;

            v7 = tmp_hash >> 16;

            hash = (unsigned int)(v7 * v7 * v7) / pConf->config_seed;
            
            *(&result) = v2; // This might be zeroing that's not clear
            *(&result + 1) = (unsigned int)(v7 * v7 * v7) %  pConf->config_seed;
            v2 = result >> 1;

            --j;

        }
        while(j);

        hash = v2;
        *buf = v2;

        buf += 8;
    }


    return 0;


}

int compare_files(uint8_t* key, char* encrypted_file, char* plaintext_file) {
    //TODO 
    // Read in plaintext file
    // Read in encrypted file
    // Decrypt file using key
    // Compare magic numbers at beginning of file

    // Block size for AES 256 is 16 bytes apparently, so we only need the beginning.
    char enc_buf[16];
    char plain_buf[16];

    FILE* enc = fopen( encrypted_file, "rb");
    fgets( enc_buf, 16, enc);

    FILE* plain = fopen( encrypted_file, "rb");
    fgets( plain_buf, 16, plain);

    fclose(enc);
    fclose(plain);





    // return 1 if equal, 0 if not

    return 0;
}