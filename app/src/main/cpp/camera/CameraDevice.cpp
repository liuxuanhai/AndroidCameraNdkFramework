//
// Created by Administrator on 2019-12-02.
//

#include "CameraDevice.h"
#include "../common/Logger.h"

CameraDevice::CameraDevice() : m_CameraDevice(NULL), m_CameraCaptureRequest(NULL), m_CameraCaptureSession(NULL), m_CameraSessionOutputContainer(NULL) {
    m_CaptureSessionStateCallbacks.onReady = onReady;
    m_CaptureSessionStateCallbacks.onActive = onActive;
    m_CaptureSessionStateCallbacks.onClosed = onClosed;
}

CameraDevice::~CameraDevice() {
}

void CameraDevice::Open(ACameraDevice* cameraDevice, ANativeWindow* textureWindow) {
    //.
    Close();

    //.
    m_CameraDevice = cameraDevice;

    //.
    CreateCaptureRequest(textureWindow);
    CreateCaptureSession(textureWindow);
}

void CameraDevice::Close() {
    //.
    if(m_CameraSessionOutputContainer != NULL) {
        m_CameraSessionOutputContainer->Close();
        delete m_CameraSessionOutputContainer;
        m_CameraSessionOutputContainer = NULL;
    }

    //.
    if(m_CameraCaptureSession != NULL) {
        m_CameraCaptureSession->Close();
        delete m_CameraCaptureSession;
        m_CameraCaptureSession = NULL;
    }

    //.
    if(m_CameraCaptureRequest != NULL) {
        m_CameraCaptureRequest->Close();
        delete m_CameraCaptureRequest;
        m_CameraCaptureRequest = NULL;
    }

    //.
    if (m_CameraDevice != NULL) {
        ACameraDevice_close(m_CameraDevice);
        m_CameraDevice = NULL;
    }
}

void CameraDevice::CreateCaptureRequest(ANativeWindow* textureWindow) {
    //.
    ACaptureRequest* tempCaptureRequest = NULL;
    camera_status_t camera_status = ACameraDevice_createCaptureRequest(
            m_CameraDevice,
            TEMPLATE_PREVIEW,
            &tempCaptureRequest);
    if (camera_status != ACAMERA_OK) {
        LOGE("Create Capture Request Error ...");
        return;
    }

    m_CameraCaptureRequest = new CameraCaptureRequest();
    m_CameraCaptureRequest->Open(tempCaptureRequest, textureWindow);
}

void CameraDevice::CreateCaptureSession(ANativeWindow* textureWindow) {
    //.
    m_CameraSessionOutputContainer = new CameraSessionOutputContainer();
    m_CameraSessionOutputContainer->Open(textureWindow);

    //.
    ACameraCaptureSession* tempCaptureSession = NULL;
    camera_status_t camera_status = ACameraDevice_createCaptureSession(
            m_CameraDevice,
            m_CameraSessionOutputContainer->GetCaptureSessionOutputContainer(),
            &m_CaptureSessionStateCallbacks,
            &tempCaptureSession);
    if (camera_status != ACAMERA_OK) {
        LOGE("Create Capture Session Error ...");
        return;
    }

    //.
    m_CameraCaptureSession = new CameraCaptureSession();
    m_CameraCaptureSession->Open(tempCaptureSession, m_CameraCaptureRequest->GetCaptureRequest());
}

void CameraDevice::onReady(void *context, ACameraCaptureSession *session) {
    LOGE("Camera Capture Session Ready Callback");
}

void CameraDevice::onActive(void *context, ACameraCaptureSession *session) {
    LOGE("Camera Capture Session Active Callback");
}

void CameraDevice::onClosed(void *context, ACameraCaptureSession *session) {
    LOGE("Camera Capture Session Closed Callback");
}
