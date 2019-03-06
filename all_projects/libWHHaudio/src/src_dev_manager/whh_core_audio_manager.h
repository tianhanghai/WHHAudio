#ifndef WHH_CORE_AUDIO_MANAGER_H
#define WHH_CORE_AUDIO_MANAGER_H

#include "um/mmdeviceapi.h"
#include "../whh_audio_common_private.h"

class WHHCoreAudioManager:public IMMNotificationClient
{
public:
	WHHCoreAudioManager();
	~WHHCoreAudioManager();

public:
	whh_audio_status_t init_manager();
	whh_audio_status_t deinit_manager();

	whh_audio_status_t enum_devices();

// device notification interfaces
public:
	HRESULT STDMETHODCALLTYPE OnDeviceStateChanged(
		/* [annotation][in] */
		_In_  LPCWSTR pwstrDeviceId,
		/* [annotation][in] */
		_In_  DWORD dwNewState);

	HRESULT STDMETHODCALLTYPE OnDeviceAdded(
		/* [annotation][in] */
		_In_  LPCWSTR pwstrDeviceId);

	HRESULT STDMETHODCALLTYPE OnDeviceRemoved(
		/* [annotation][in] */
		_In_  LPCWSTR pwstrDeviceId);

	HRESULT STDMETHODCALLTYPE OnDefaultDeviceChanged(
		/* [annotation][in] */
		_In_  EDataFlow flow,
		/* [annotation][in] */
		_In_  ERole role,
		/* [annotation][in] */
		_In_  LPCWSTR pwstrDefaultDeviceId);

	HRESULT STDMETHODCALLTYPE OnPropertyValueChanged(
		/* [annotation][in] */
		_In_  LPCWSTR pwstrDeviceId,
		/* [annotation][in] */
		_In_  const PROPERTYKEY key);

// IUnknown Interfaces
	HRESULT STDMETHODCALLTYPE QueryInterface(
		/* [in] */ REFIID riid,
		/* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR *__RPC_FAR *ppvObject);

	virtual ULONG STDMETHODCALLTYPE AddRef(void);

	virtual ULONG STDMETHODCALLTYPE Release(void);

protected:
	void init_params();

	whh_audio_status_t init_com();
	whh_audio_status_t deinit_com();

protected:
	bool											m_b_com_inited;
	DWORD											m_dw_thread_id;

	DWORD											m_dw_ref;

	IMMDeviceEnumerator*							m_p_device_enumrator;
	bool											m_b_dev_callback;
	

};

#endif // !WHH_CORE_AUDIO_MANAGER_H
