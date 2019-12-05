#include "CameraManager.h"
#include "../common/Logger.h"

CameraManager::CameraManager() : m_CameraManger(NULL), m_CameraDevice(NULL), m_TextureWindow(NULL) {
    m_DeviceStateCallbacks.onDisconnected = onDisconnected;
    m_DeviceStateCallbacks.onError = onError;
}

CameraManager::~CameraManager() {
}

void CameraManager::Open(JNIEnv* env, jobject surface) {
    //.
    Close();

    //.
    m_TextureWindow = ANativeWindow_fromSurface(env, surface);
    ANativeWindow_acquire(m_TextureWindow);

    //.
    m_CameraManger = ACameraManager_create();

    //.
    const char* selectedCameraId = GetSelectedCameraId();
    if(selectedCameraId == NULL) {
        LOGE("Selected CameraId Error...");
        return;;
    }

    //.
    ACameraDevice *tempCameraDevice = NULL;
    camera_status_t camera_status = ACameraManager_openCamera(
            m_CameraManger,
            selectedCameraId,
            &m_DeviceStateCallbacks,
            &tempCameraDevice);
    if (camera_status != ACAMERA_OK) {
        LOGE("CameraDevice OpenCamera Error...");
        return;
    }

    m_CameraDevice = new CameraDevice();
    m_CameraDevice->Open(tempCameraDevice, m_TextureWindow);
}

void CameraManager::Close() {
    //.
    if(m_CameraDevice != NULL) {
        m_CameraDevice->Close();
        delete m_CameraDevice;
        m_CameraDevice = NULL;
    }

    //.
    if(m_CameraManger != NULL) {
        ACameraManager_delete(m_CameraManger);
        m_CameraManger = NULL;
    }

    //.
    if (m_TextureWindow != NULL) {
        ANativeWindow_release(m_TextureWindow);
    }
}

const char* CameraManager::GetSelectedCameraId() {
    //.
    ACameraIdList *cameraIdList = NULL;
    camera_status_t camera_status = ACameraManager_getCameraIdList(m_CameraManger, &cameraIdList);
    if (camera_status != ACAMERA_OK) {
        //. To Android
        return NULL;
    }

    if (cameraIdList->numCameras < 1) {
        //. To Android
        return NULL;
    }
    const char* selectedCameraId = cameraIdList->cameraIds[0];
    ACameraManager_deleteCameraIdList(cameraIdList);

    //.
    ACameraMetadata *cameraMetadata = NULL;
    camera_status = ACameraManager_getCameraCharacteristics(m_CameraManger, selectedCameraId, &cameraMetadata);
    if (camera_status != ACAMERA_OK) {
        //. To Android
        return NULL;
    }
    ACameraMetadata_free(cameraMetadata);

    return selectedCameraId;
}

void CameraManager::onDisconnected(void *context, ACameraDevice *device) {
    LOGE("Open Camera Disconnected Callback");
}

void CameraManager::onError(void *context, ACameraDevice *device, int error) {
    LOGE("Open Camera Error Callback");
}
