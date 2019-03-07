#include "whh_audio_common_private.h"

whh_audio_status_t wchar_to_char(wchar_t * t_p_wcs, char * t_p_cs, uint32_t & t_u32_length)
{
	whh_audio_status_t t_audio_stat = WHH_AUDIO_STAT_OK;

	if (t_p_wcs == NULL||t_p_cs==NULL) {
		t_audio_stat = WHH_AUDIO_STAT_PARAM_INVALID;
		return t_audio_stat;
	}

	if (IsBadWritePtr((void*)t_p_cs, t_u32_length)) {
		t_audio_stat = WHH_AUDIO_STAT_PARAM_INVALID;
		return t_audio_stat;
	}

	uint32_t t_u32_len=WideCharToMultiByte(CP_ACP,0,t_p_wcs,-1,NULL,0,NULL,NULL);
	if (t_u32_len > t_u32_length) {
		t_audio_stat = WHH_AUDIO_STAT_PARAM_INVALID;
		return t_audio_stat;
	}

	t_u32_length=WideCharToMultiByte(CP_ACP, 0, t_p_wcs, -1, t_p_cs, t_u32_len, NULL, NULL);

	return t_audio_stat;
}

whh_audio_status_t char_to_wchar(char* t_p_cs, wchar_t* t_p_wcs, uint32_t &t_u32_length)
{
	whh_audio_status_t t_audio_stat = WHH_AUDIO_STAT_OK;

	if (t_p_cs == NULL || t_p_wcs == NULL) {
		t_audio_stat = WHH_AUDIO_STAT_PARAM_INVALID;
		return t_audio_stat;
	}

	if (IsBadWritePtr((void*)t_p_wcs, sizeof(wchar_t)*t_u32_length)) {
		t_audio_stat = WHH_AUDIO_STAT_PARAM_INVALID;
		return t_audio_stat;
	}

	uint32_t t_u32_len = MultiByteToWideChar(CP_ACP, 0, t_p_cs, -1, NULL, 0);
	if (t_u32_len > t_u32_length) {
		t_audio_stat = WHH_AUDIO_STAT_PARAM_INVALID;
		return t_audio_stat;
	}

	t_u32_length = MultiByteToWideChar(CP_ACP, 0, t_p_cs, -1, t_p_wcs, 0);

	return t_audio_stat;
}
