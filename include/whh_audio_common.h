#ifndef WHH_AUDIO_COMMON_H
#define WHH_AUDIO_COMMON_H

#include "stdint.h"

typedef enum _audio_status{
	WHH_AUDIO_STAT_OK,

	WHH_AUDIO_STAT_COM_FAILED,
	WHH_AUDIO_STAT_COM_INITED,
	WHH_AUDIO_STAT_COM_NONE,
	WHH_AUDIO_STAT_DIFF_THREAD,

	WHH_AUDIO_STAT_ENUMRATOR_FAILED,
	WHH_AUDIO_STAT_ENUMRATOR_OBSERVE_FAILED,

	WHH_AUDIO_STAT_PARAM_INVALID,

	WHH_AUDIO_STAT_COUNT
}whh_audio_status_t;

typedef struct _audio_device {
	char				m_cs_dev_name[128];
	char				m_cs_id[128];
	char				m_cs_interface_name[128];
	char				m_cs_description[128];
}whh_audio_device_t;

#endif
