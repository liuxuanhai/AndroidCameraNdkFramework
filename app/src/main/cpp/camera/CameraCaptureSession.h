#ifndef ANDROIDCAMERAFRAMEWORK_CAMERACAPTURESESSION_H
#define ANDROIDCAMERAFRAMEWORK_CAMERACAPTURESESSION_H

#include <camera/NdkCameraDevice.h>
#include <camera/NdkCameraManager.h>

class CameraCaptureSession {
public:
    CameraCaptureSession();
    virtual ~CameraCaptureSession();

public:
    void Open(ACameraCaptureSession* captureSession, ACaptureRequest* captureRequest);
    void Close();

private:
    ACameraCaptureSession_captureCallbacks m_CaptureSessionCaptureCallbacks;
    static void onCaptureFailed(void* context, ACameraCaptureSession* session, ACaptureRequest* request, ACameraCaptureFailure* failure);
    static void onCaptureSequenceCompleted(void* context, ACameraCaptureSession* session, int sequenceId, int64_t frameNumber);
    static void onCaptureSequenceAborted(void* context, ACameraCaptureSession* session, int sequenceId);
    static void onCaptureCompleted(void* context, ACameraCaptureSession* session, ACaptureRequest* request, const ACameraMetadata* result);

private:
    ACameraCaptureSession* m_CaptureSession;
};

#endif //ANDROIDCAMERAFRAMEWORK_CAMERACAPTURESESSION_H
