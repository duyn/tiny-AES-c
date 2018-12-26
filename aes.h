#ifndef _AES_H_
#define _AES_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// #define the macros below to 1/0 to enable/disable the mode of operation.
//
// AES_CBC enables AES encryption in CBC-mode of operation.
// AES_CTR enables encryption in counter-mode.
// AES_ECB enables the basic ECB 16-byte block algorithm. All can be enabled simultaneously.

// The #ifndef-guard allows it to be configured before #include'ing or at compile time.
#ifndef AES_CBC
  #define AES_CBC 1
#endif

#ifndef AES_ECB
  #define AES_ECB 1
#endif

#ifndef AES_CTR
  #define AES_CTR 1
#endif


#define AES128 1
//#define AES192 1
//#define AES256 1

#define AES_BLOCK_LEN 16 //Block length in bytes AES is 128b block only

#if defined(AES256) && (AES256 == 1)
    #define AES_KEY_LEN 32
    #define AES_KEY_EXPSIZE 240
#elif defined(AES192) && (AES192 == 1)
    #define AES_KEY_LEN 24
    #define AES_KEY_EXPSIZE 208
#else
    #define AES_KEY_LEN 16   // Key length in bytes
    #define AES_KEY_EXPSIZE 176
#endif


#if defined(AES_ECB) && (AES_ECB == 1)
// param pucOutBuf: output data after encrypt/decrypt
//       uiBufLen : output buffer length
//       pucInData: input data
//       uiInLen  : input data length
//       pucKey   : key of encrypt/decrypt
//       ucMode   : mode of padding
int32_t AES_ECBEncrypt(uint8_t *pucOutBuf, uint32_t uiBufLen, uint8_t *pucInData, uint32_t uiInLen, const uint8_t *pucKey, uint8_t ucMode);
int32_t AES_ECBDecrypt(uint8_t *pucOutBuf, uint32_t uiBufLen, uint8_t *pucInData, uint32_t uiInLen, const uint8_t *pucKey, uint8_t ucMode);

#endif // #if defined(AES_ECB) && (AES_ECB == !)


#if defined(AES_CBC) && (AES_CBC == 1)
// param pucOutBuf: output data after encrypt/decrypt
//       uiBufLen : output buffer length
//       pucInData: input data
//       uiInLen  : input data length
//       pucKey   : key of encrypt/decrypt
//       pucIV    : iv
//       ucMode   : mode of padding
int32_t AES_CBCEncrypt(uint8_t *pucOutBuf, uint32_t uiBufLen, uint8_t *pucInData, uint32_t uiInLen, const uint8_t *pucKey, const uint8_t *pucIV, uint8_t ucMode);
int32_t AES_CBCDecrypt(uint8_t *pucOutBuf, uint32_t uiBufLen, uint8_t *pucInData, uint32_t uiInLen, const uint8_t *pucKey, const uint8_t *pucIV, uint8_t ucMode);

#endif // #if defined(AES_CBC) && (AES_CBC == 1)


#if defined(AES_CTR) && (AES_CTR == 1)

// Same function for encrypting as for decrypting. 
// IV is incremented for every block, and used after encryption as XOR-compliment for output
// Suggesting https://en.wikipedia.org/wiki/Padding_(cryptography)#PKCS7 for padding scheme
int32_t AES_CTRXcrypt(uint8_t *pucOutBuf, uint32_t uiBufLen, uint8_t *pucInData, uint32_t uiInLen, const uint8_t *pucKey, const uint8_t *pucInitIV, uint8_t ucMode);

#endif // #if defined(AES_CTR) && (AES_CTR == 1)

#ifdef __cplusplus
}
#endif /* end of __cplusplus */

#endif //_AES_H_

/************************************** The End Of File **************************************/

