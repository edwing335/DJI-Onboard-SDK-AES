#ifndef _AES_H_
#define _AES_H_
typedef struct 
{
	unsigned char key[32]; 
	unsigned char enckey[32]; 
	unsigned char deckey[32];
}Filter;

void aes256_init(Filter *, unsigned char *);
void aes256_done(Filter *);
void aes256_encrypt_ecb(Filter *, unsigned char * );
void aes256_decrypt_ecb(Filter *, unsigned char * );
#endif