/* See LICENSE file for license details. */
#ifndef __SW_CRC32_H__
#define __SW_CRC32_H__
#include "cam_types.h"

uint32_t crc32(const buf_va_t start, buf_sz_t size, uint32_t *initial);

#endif /* __SW_CRC32_H__ */
