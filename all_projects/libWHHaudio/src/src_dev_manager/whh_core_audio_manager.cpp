#include "whh_core_audio_manager.h"

WHHCoreAudioManager::WHHCoreAudioManager()
{
	init_params();
}

WHHCoreAudioManager::~WHHCoreAudioManager()
{
	if (m_p_device_enumrator != NULL) {
		m_p_device_enumrator->Release();
		m_p_device_enumrator = NULL;
	}
}

whh_audio_status_t WHHCoreAudioManager::init_com()
{
	whh_audio_status_t t_audio_stat = WHH_AUDIO_STAT_OK;

	DWORD t_dw_thread_id=GetCurrentThreadId();

	if (m_b_com_inited) {
		t_audio_stat = WHH_AUDIO_STAT_COM_INITED;
	}
	else {
		HRESULT t_hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
		if (FAILED(t_hr)) {
			t_audio_stat = WHH_AUDIO_STAT_COM_FAILED;
			m_b_com_inited = false;
		}
		else {
			m_b_com_inited = true;
			m_dw_thread_id = t_dw_thread_id;
		}
	}

	return t_audio_stat;
}

whh_audio_status_t WHHCoreAudioManager::deinit_com()
{
	whh_audio_status_t t_audio_stat = WHH_AUDIO_STAT_OK;

	DWORD t_dw_thread_id = GetCurrentThreadId();
	if (!m_b_com_inited) {
		t_audio_stat = WHH_AUDIO_STAT_COM_NONE;
	}
	else {
		if (m_dw_thread_id != t_dw_thread_id) {
			t_audio_stat = WHH_AUDIO_STAT_DIFF_THREAD;
		}
		else {
			CoUninitialize();
		}
	}

	return t_audio_stat;
}

whh_audio_status_t WHHCoreAudioManager::init_manager()
{
	whh_audio_status_t t_audio_stat = WHH_AUDIO_STAT_OK;

	// initilize com
	t_audio_stat = init_com();
	if (t_audio_stat == WHH_AUDIO_STAT_COM_FAILED)
		return t_audio_stat;

	HRESULT t_hr = CoCreateInstance(CLSID_MMDeviceEnumerator, NULL,
		CLSCTX_ALL,
		IID_IMMDeviceEnumerator,
		(void**)&m_p_device_enumrator);

	if (FAILED(t_hr)||m_p_device_enumrator==NULL) {
		t_audio_stat = WHH_AUDIO_STAT_ENUMRATOR_FAILED;
		deinit_com();
	}

	t_hr=m_p_device_enumrator->RegisterEndpointNotificationCallback(this);
	if (FAILED(t_hr)) {
		t_audio_stat = WHH_AUDIO_STAT_ENUMRATOR_OBSERVE_FAILED;
		m_b_dev_callback = false;
	}
	else {
		m_b_dev_callback = true;
	}

	return t_audio_stat;
}

whh_audio_status_t WHHCoreAudioManager::deinit_manager()
{
	whh_audio_status_t t_audio_stat = WHH_AUDIO_STAT_OK;

	if (m_p_device_enumrator != NULL) {
		m_p_device_enumrator->Release();
		m_p_device_enumrator = NULL;
	}

	t_audio_stat=deinit_com();

	return t_audio_stat;
}

whh_audio_status_t WHHCoreAudioManager::enum_devices()
{
	whh_audio_status_t t_audio_stat = WHH_AUDIO_STAT_OK;

	if (!m_b_com_inited) {
		t_audio_stat = WHH_AUDIO_STAT_COM_FAILED;
		return t_audio_stat;
	}

	if (m_p_device_enumrator == NULL) {
		t_audio_stat = WHH_AUDIO_STAT_ENUMRATOR_FAILED;
		return t_audio_stat;
	}

	IMMDeviceCollection* t_p_collection = NULL;
	HRESULT t_hr = m_p_device_enumrator->EnumAudioEndpoints(eRender, DEVICE_STATE_ACTIVE, &t_p_collection);
	if (FAILED(t_hr) || t_p_collection == NULL) {
		t_audio_stat = WHH_AUDIO_STAT_ENUMRATOR_FAILED;
	}

	UINT t_n_num = 0;
	t_hr=t_p_collection->GetCount(&t_n_num);
	if (FAILED(t_hr)) {
		t_audio_stat = WHH_AUDIO_STAT_ENUMRATOR_FAILED;
		t_p_collection->Release();
		t_p_collection = NULL;
		return t_audio_stat;
	}

	for (UINT i = 0; i < t_n_num; i++) {
		IMMDevice *t_p_device = NULL;
		t_hr=t_p_collection->Item(i, &t_p_device);
		if (FAILED(t_hr)||t_p_device==NULL)
			continue;

		//LPWSTR t_pwcs = NULL;
		//t_hr=t_p_device->GetId(&t_pwcs);
		//if (FAILED(t_hr) || t_pwcs == NULL) {
		
		//}
		
		IPropertyStore *t_p_prop = NULL;
		t_hr=t_p_device->OpenPropertyStore(STGM_READ, &t_p_prop);
		if (FAILED(t_hr) || t_p_prop == NULL)
			continue;

		t_p_prop->GetValue()
	}

	return t_audio_stat;
}

HRESULT __stdcall WHHCoreAudioManager::OnDeviceStateChanged(LPCWSTR pwstrDeviceId, DWORD dwNewState)
{
	HRESULT t_hr=S_OK;

	return t_hr;
}

HRESULT __stdcall WHHCoreAudioManager::OnDeviceAdded(LPCWSTR pwstrDeviceId)
{
	HRESULT t_hr = S_OK;

	return t_hr;
}

HRESULT __stdcall WHHCoreAudioManager::OnDeviceRemoved(LPCWSTR pwstrDeviceId)
{
	HRESULT t_hr = S_OK;

	return t_hr;
}

HRESULT __stdcall WHHCoreAudioManager::OnDefaultDeviceChanged(EDataFlow flow, ERole role, LPCWSTR pwstrDefaultDeviceId)
{
	HRESULT t_hr = S_OK;

	return t_hr;
}

HRESULT __stdcall WHHCoreAudioManager::OnPropertyValueChanged(LPCWSTR pwstrDeviceId, const PROPERTYKEY key)
{
	HRESULT t_hr = S_OK;

	return t_hr;
}

HRESULT __stdcall WHHCoreAudioManager::QueryInterface(REFIID riid, void ** ppvObject)
{
	HRESULT t_hr = S_OK;

	*ppvObject = NULL;

	return t_hr;
}

ULONG __stdcall WHHCoreAudioManager::AddRef(void)
{
	return ++m_dw_ref;
}

ULONG __stdcall WHHCoreAudioManager::Release(void)
{
	--m_dw_ref;

	if (m_dw_ref <= 0)
		delete this;

	return 0;
}

void WHHCoreAudioManager::init_params()
{
	m_p_device_enumrator = NULL;

	m_b_com_inited = false;
	m_dw_thread_id = -1;

	m_dw_ref = 0;

	m_b_dev_callback = false;
}
