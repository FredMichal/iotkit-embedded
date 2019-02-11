#ifndef _COAP_WRAPPER_H_
#define _COAP_WRAPPER_H_

#include "infra_types.h"
#include "infra_defs.h"
#include "wrappers_defs.h"

void *HAL_Malloc(uint32_t size);
void HAL_Free(void *ptr);
void HAL_SleepMs(uint32_t ms);
uint64_t HAL_UptimeMs(void);
void HAL_Srandom(uint32_t seed);
uint32_t HAL_Random(uint32_t region);

int HAL_SetProductKey(char *product_key);
int HAL_SetDeviceName(char *device_name);
int HAL_SetDeviceSecret(char *device_secret);

DLL_HAL_API int HAL_DTLSHooks_set(dtls_hooks_t *hooks);
DLL_HAL_API DTLSContext *HAL_DTLSSession_create(coap_dtls_options_t  *p_options);
DLL_HAL_API unsigned int HAL_DTLSSession_write(DTLSContext *context,
        const unsigned char *p_data,
        unsigned int *p_datalen);
DLL_HAL_API unsigned int HAL_DTLSSession_read(DTLSContext *context,
        unsigned char *p_data,
        unsigned int *p_datalen,
        unsigned int timeout_ms);
DLL_HAL_API unsigned int HAL_DTLSSession_free(DTLSContext *context);
intptr_t HAL_UDP_create(char *host, unsigned short port);
intptr_t HAL_UDP_create_without_connect(const char *host, unsigned short port);
int HAL_UDP_write(intptr_t p_socket,
                  const unsigned char *p_data,
                  unsigned int datalen);
int HAL_UDP_readTimeout(intptr_t p_socket,
                        unsigned char *p_data,
                        unsigned int datalen,
                        unsigned int timeout);
int HAL_UDP_close_without_connect(intptr_t sockfd);
p_HAL_Aes128_t HAL_Aes128_Init(
            const uint8_t *key,
            const uint8_t *iv,
            AES_DIR_t dir);
int HAL_Aes128_Destroy(p_HAL_Aes128_t aes);
int HAL_Aes128_Cbc_Encrypt(
            p_HAL_Aes128_t aes,
            const void *src,
            size_t blockNum,
            void *dst);
int HAL_Aes128_Cbc_Decrypt(
            p_HAL_Aes128_t aes,
            const void *src,
            size_t blockNum,
            void *dst);

#endif