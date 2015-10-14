//demo main.cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aes.h"
#define MAXSIZE (512)// can change the size basing on your data length
void two_bytes_2_one_byte(const unsigned char *pstr, unsigned char *pdata)
{
	int i;
	char temp_area[3];
	unsigned int temp8;
	temp_area[0] = temp_area[1] = temp_area[2] = 0;
	
	for(i = 0; i< 32 ;i++)
	{
		temp_area[0] =pstr[0];
		temp_area[1] =pstr[1];
		sscanf(temp_area,"%x", &temp8);
		pdata[i] =temp8;
		pstr += 2;
	}
}
int main (int argc, char *argv[])
{
	
	unsigned char orign_key[]="aabbbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";//user key
	unsigned char key[32];
	unsigned char data_buf[]={1,0,1};//user data
	
	

	Filter ctx;
	unsigned char encryption_buf[MAXSIZE];
	memset(encryption_buf,0,MAXSIZE);
	unsigned short data_len=3;
	unsigned short encryption_len = data_len+(16-data_len%16);
	memcpy(encryption_buf,data_buf,data_len);
	
	for(int i=0;i<encryption_len;i++)
	    printf("%d ",encryption_buf[i]);
	printf("\n");

	two_bytes_2_one_byte(orign_key, (unsigned char*)key);
	for(int i=0;i<32;i++)
		printf("%x ",key[i]);
	printf("\n");
	
	// encrypt
	aes256_init(&ctx, key);
	for(int i=0;i<encryption_len;i +=16)
	{
		aes256_encrypt_ecb(&ctx, encryption_buf+i);
	}
	for(int i=0;i<encryption_len;i++)
		printf("%x ",encryption_buf[i]);
	printf("\n");

	// decrypt
	aes256_init(&ctx, key);
	for(int i=0;i<encryption_len;i +=16)
	{
		aes256_decrypt_ecb(&ctx, encryption_buf+i);
	}
	memcpy(data_buf,encryption_buf,data_len);
	memset(encryption_buf,0,MAXSIZE);
	for(int i=0;i<data_len;i++)
		printf("%d ",data_buf[i]);
	aes256_done(&ctx);
	system("pause");
	return 0;
} /* main */
