#include "CameraSessionOutputContainer.h"
#include "../common/Logger.h"

CameraSessionOutputContainer::CameraSessionOutputContainer() : m_CaptureSessionOutputContainer(NULL), m_CaptureSessionOutput(NULL) {
}

CameraSessionOutputContainer::~CameraSessionOutputContainer() {
}

void CameraSessionOutputContainer::Open(ANativeWindow* textureWindow) {
    //.
    Close();

    //.
    m_CaptureSessionOutput = new CameraSessionOutput();
    m_CaptureSessionOutput->Open(textureWindow);

    //.
    camera_status_t camera_status = ACaptureSessionOutputContainer_create(&m_CaptureSessionOutputContainer);
    if (camera_status != ACAMERA_OK) {
        LOGE("Capture Session Output Contrainer Error...");
        return;
    }

    ACaptureSessionOutputContainer_add(m_CaptureSessionOutputContainer, m_CaptureSessionOutput->GetSessionOutput());
}

void CameraSessionOutputContainer::Close() {
    //.
    if(m_CaptureSessionOutput != NULL) {
        m_CaptureSessionOutput->Close();
        delete  m_CaptureSessionOutput;
        m_CaptureSessionOutput = NULL;
    }

    //.
    if (m_CaptureSessionOutputContainer != NULL) {
        ACaptureSessionOutputContainer_free(m_CaptureSessionOutputContainer);
        m_CaptureSessionOutputContainer = NULL;
    }
}

ACaptureSessionOutputContainer* CameraSessionOutputContainer::GetCaptureSessionOutputContainer() const {
    return m_CaptureSessionOutputContainer;
}