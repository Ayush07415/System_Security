#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <wincrypt.h>

int main()
{
    HCRYPTPROV hProv;
    HCRYPTHASH hHash;

    BYTE hash[16];
    DWORD hashLen = 16;

    char data[] = "Hello world";

    CryptAcquireContext( &hProv,NULL,NULL,PROV_RSA_FULL,CRYPT_VERIFYCONTEXT);

    CryptCreateHash(hProv,CALG_MD5,0,0,&hHash);

    CryptHashData(hHash,(BYTE*)data,strlen(data),0);

    CryptGetHashParam(hHash,HP_HASHVAL,hash,&hashLen,0);

    printf("MD5: ");

    for (DWORD i = 0; i < hashLen; i++)
        printf("%02x", hash[i]);

    printf("\n");

    CryptDestroyHash(hHash);
    CryptReleaseContext(hProv, 0);

    return 0;
}