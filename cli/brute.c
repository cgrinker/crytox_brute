
#include "crytox.h"



int main(int argc, char** argv) {
    PConf conf = {};

    int64_t GetTickCount;

    if(argc != 5) {
        printf("%s\n", "Usage: crytox_brute <encrypted_file> <plaintext_file> <config_seed> <seed_start>");
        return 1;
    }

    char* encrypted_file = argv[1];
    char* plaintext_file = argv[2];
    conf.config_seed = atoi(argv[3]);
    GetTickCount = atoi(argv[4]); // pass this GetTickCount to search in parallel



    int found = 0;

    while(!found) {
        // AES 256 right?
        uint8_t key_buffer[256];
        // Question are they saying this seed would have started at 0 for each AES key generated?
        conf.random_generated = 0;
        generate_key(key_buffer, GetTickCount, &conf);

        found = compare_files(key_buffer, encrypted_file, plaintext_file);
        if(found) {
            break;
        }



        GetTickCount++;
    }

    if(found) {
        printf("GetTickCount Found: %lli\n", GetTickCount);
    }

    
    return 0;
}