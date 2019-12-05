#include "CameraCaptureRequest.h"
#include "../common/Logger.h"

CameraCaptureRequest::CameraCaptureRequest() : m_CaptureRequest(NULL), a_CameraOutputTarget(NULL) {
}

CameraCaptureRequest::~CameraCaptureRequest() {
}

void CameraCaptureRequest::Open(ACaptureRequest* captureRequest, ANativeWindow* textureWindow) {
    //.
    Close();

    //.
    m_CaptureRequest = captureRequest;
    m_TextureWindow = textureWindow;

    //.
    ACameraOutputTarget* tempCameraOutputTarget = NULL;
    camera_status_t camera_status = ACameraOutputTarget_create(textureWindow, &tempCameraOutputTarget);
    if (camera_status != ACAMERA_OK) {
        LOGE("Create Camera Output Target Error ...");
        return;
    }

    //.
    a_CameraOutputTarget = new CameraOutputTarget();
    a_CameraOutputTarget->Open(tempCameraOutputTarget);

    //.
    ACaptureRequest_addTarget(
            m_CaptureRequest,
            a_CameraOutputTarget->GetCameraOutputTarget());
}

void CameraCaptureRequest::Close() {
    //.
    if (a_CameraOutputTarget != NULL) {
        a_CameraOutputTarget->Close();
        delete a_CameraOutputTarget;
        a_CameraOutputTarget = NULL;
    }

    //.
    if(m_CaptureRequest != NULL) {
        ACaptureRequest_free(m_CaptureRequest);
        m_CaptureRequest = NULL;
    }
}

ACaptureRequest* CameraCaptureRequest::GetCaptureRequest() const {
    return m_CaptureRequest;
}
