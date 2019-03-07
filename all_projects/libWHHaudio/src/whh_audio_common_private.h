#ifndef WHH_AUDIO_COMMON_PRIVATE_H
#define WHH_AUDIO_COMMON_PRIVATE_H

#include "whh_audio_common.h"
#include "windows.h"

whh_audio_status_t wchar_to_char(wchar_t *t_p_wcs, char *t_p_cs, uint32_t &t_u32_length);

whh_audio_status_t char_to_wchar(char* t_p_cs,wchar_t* t_p_wcs,uint32_t &t_u32_length);

#endif // !WHH_AUDIO_COMMON_PRIVATE_H

