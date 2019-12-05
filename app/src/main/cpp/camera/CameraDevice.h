//
// Created by Administrator on 2019-12-02.
//

#ifndef ANDROIDCAMERAFRAMEWORK_CAMERADEVICE_H
#define ANDROIDCAMERAFRAMEWORK_CAMERADEVICE_H

#include <android/native_window_jni.h>
#include <camera/NdkCameraDevice.h>
#include "CameraCaptureSession.h"
#include "CameraCaptureRequest.h"
#include "CameraSessionOutputContainer.h"

class CameraDevice {

public:
    CameraDevice();
    virtual ~CameraDevice();

public:
    void Open(ACameraDevice* cameraDevice, ANativeWindow* textureWindow);
    void Close();

private:
    ACameraDevice* m_CameraDevice;

private:
    void CreateCaptureRequest(ANativeWindow* textureWindow);

private:
    CameraCaptureRequest* m_CameraCaptureRequest;

private:
    void CreateCaptureSession(ANativeWindow* textureWindow);
    ACameraCaptureSession_stateCallbacks m_CaptureSessionStateCallbacks;
    static void onReady(void *context, ACameraCaptureSession *session);
    static void onActive(void *context, ACameraCaptureSession *session);
    static void onClosed(void *context, ACameraCaptureSession *session);

private:
    CameraSessionOutputContainer* m_CameraSessionOutputContainer;
    CameraCaptureSession* m_CameraCaptureSession;
};

#endif //ANDROIDCAMERAFRAMEWORK_CAMERADEVICE_H
