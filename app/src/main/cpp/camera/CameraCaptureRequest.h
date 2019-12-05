#ifndef ANDROIDCAMERAFRAMEWORK_CAMERACAPTUREREQUEST_H
#define ANDROIDCAMERAFRAMEWORK_CAMERACAPTUREREQUEST_H

#include <camera/NdkCameraDevice.h>
#include <camera/NdkCameraManager.h>
#include "CameraOutputTarget.h"

class CameraCaptureRequest {
public:
    CameraCaptureRequest();
    virtual ~CameraCaptureRequest();

public:
    void Open(ACaptureRequest* captureRequest, ANativeWindow* textureWindow);
    void Close();

public:
    ACaptureRequest* GetCaptureRequest() const;

private:
    ACaptureRequest* m_CaptureRequest;

private:
    ANativeWindow* m_TextureWindow;

private:
    CameraOutputTarget* a_CameraOutputTarget;
};


#endif //ANDROIDCAMERAFRAMEWORK_CAMERACAPTUREREQUEST_H
