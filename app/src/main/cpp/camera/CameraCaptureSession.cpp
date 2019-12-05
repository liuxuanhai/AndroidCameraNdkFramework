#include "CameraCaptureSession.h"
#include "../common/Logger.h"

CameraCaptureSession::CameraCaptureSession() : m_CaptureSession(NULL) {
    m_CaptureSessionCaptureCallbacks.onCaptureFailed = onCaptureFailed;
    m_CaptureSessionCaptureCallbacks.onCaptureSequenceCompleted = onCaptureSequenceCompleted;
    m_CaptureSessionCaptureCallbacks.onCaptureSequenceAborted = onCaptureSequenceAborted;
    m_CaptureSessionCaptureCallbacks.onCaptureCompleted = onCaptureCompleted;
}

CameraCaptureSession::~CameraCaptureSession() {
}

void CameraCaptureSession::Open(ACameraCaptureSession* captureSession, ACaptureRequest* captureRequest) {
    //.
    Close();

    //.
    m_CaptureSession = captureSession;

    //.
    ACameraCaptureSession_setRepeatingRequest(
            m_CaptureSession,
            &m_CaptureSessionCaptureCallbacks,
            1,
            &captureRequest,
            NULL);
}

void CameraCaptureSession::Close() {
    //.
    if(m_CaptureSession != NULL) {
        ACameraCaptureSession_stopRepeating(m_CaptureSession);
        ACameraCaptureSession_close(m_CaptureSession);
        m_CaptureSession = NULL;
    }
}

void CameraCaptureSession::onCaptureFailed(void* context, ACameraCaptureSession* session, ACaptureRequest* request, ACameraCaptureFailure* failure) {
    LOGE("Camera Capture Failed Callback");
}

void CameraCaptureSession::onCaptureSequenceCompleted(void* context, ACameraCaptureSession* session, int sequenceId, int64_t frameNumber) {
    LOGE("Camera Capture Sequence Completed Callback");
}

void CameraCaptureSession::onCaptureSequenceAborted(void* context, ACameraCaptureSession* session, int sequenceId) {
    LOGE("Camera Capture Sequence Aborted Callback");
}

void CameraCaptureSession::onCaptureCompleted(void* context, ACameraCaptureSession* session, ACaptureRequest* request, const ACameraMetadata* result) {
    LOGE("Camera Capture Completed Callback");
}
