#pragma once

#include "stdio.h"
#include "stdlib.h"
#include "inttypes.h"
#include "time.h"
//#include "openssl"

// https://www.zscaler.com/blogs/security-research/technical-analysis-crytox-ransomware

// This shit from 
typedef struct  {
    int64_t random_generated; // This is some random value that gets stepped every time you run the algo. starts a 0 
    int32_t config_seed; // This is stored in the malware config file
} PConf;


// XXX This is straight out of the IDA shit. Dargons
int generate_key( uint8_t* buf, int64_t GetTickCount, PConf* pConf);

// Compare two files's magic numbers against they key
int compare_files(uint8_t* key, char* encrypted_file, char* plaintext_file);