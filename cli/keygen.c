// Generate a test key and shit

#include "crytox.h"









int main(int argc, char** argv) {
    PConf conf = {};
    time_t t;

    if(argc != 2) {
        printf("%s\n", "Usage: crytox_gen <config_seed>");
        return 1;
    }

    srand((unsigned) time(&t));
    conf.config_seed = atoi(argv[1]);
    int64_t GetTickCount = rand(); // pass this GetTickCount to search in parallel



    int found = 0;

    uint8_t key_buffer[256];
    // Question are they saying this seed would have started at 0 for each AES key generated?
    conf.random_generated = 0;
    generate_key(key_buffer, GetTickCount, &conf);

    printf("Key: ");
    for (int i = 0; i < 256; i++)
    {
        if (i > 0) printf(":");
        printf("%02X", key_buffer[i]);
    }

    printf("%s", "\n");

    
    return 0;
}