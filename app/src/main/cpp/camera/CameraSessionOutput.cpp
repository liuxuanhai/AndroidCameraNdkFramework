#include "CameraSessionOutput.h"

CameraSessionOutput::CameraSessionOutput() : m_SessionOutput(NULL) {
}

CameraSessionOutput::~CameraSessionOutput() {
}

void CameraSessionOutput::Open(ANativeWindow* textureWindow) {
    ACaptureSessionOutput_create(textureWindow, &m_SessionOutput);
}

void CameraSessionOutput::Close() {
    if (m_SessionOutput != NULL) {
        ACaptureSessionOutput_free(m_SessionOutput);
        m_SessionOutput = NULL;
    }
}

ACaptureSessionOutput* CameraSessionOutput::GetSessionOutput() const {
    return m_SessionOutput;
}