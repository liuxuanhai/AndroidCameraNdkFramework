#include "CameraOutputTarget.h"

CameraOutputTarget::CameraOutputTarget() : m_CameraOutputTarget(nullptr) {
}

CameraOutputTarget::~CameraOutputTarget() {
}

void CameraOutputTarget::Open(ACameraOutputTarget* cameraOutputTarget) {
    m_CameraOutputTarget = cameraOutputTarget;
}

void CameraOutputTarget::Close() {
    if (m_CameraOutputTarget != NULL) {
        ACameraOutputTarget_free(m_CameraOutputTarget);
        m_CameraOutputTarget = NULL;
    }
}

ACameraOutputTarget* CameraOutputTarget::GetCameraOutputTarget() const {
    return m_CameraOutputTarget;
}