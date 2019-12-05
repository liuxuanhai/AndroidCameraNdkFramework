#ifndef ANDROIDCAMERAFRAMEWORK_CAMERASESSIONOUTPUTCONTAINER_H
#define ANDROIDCAMERAFRAMEWORK_CAMERASESSIONOUTPUTCONTAINER_H

#include <camera/NdkCameraManager.h>
#include <camera/NdkCameraDevice.h>
#include "CameraSessionOutput.h"

class CameraSessionOutputContainer {
public:
    CameraSessionOutputContainer();
    virtual ~CameraSessionOutputContainer();

public:
    void Open(ANativeWindow* textureWindow);
    void Close();

public:
    ACaptureSessionOutputContainer* GetCaptureSessionOutputContainer() const;

private:
    ACaptureSessionOutputContainer* m_CaptureSessionOutputContainer;

private:
    CameraSessionOutput* m_CaptureSessionOutput;
};


#endif //ANDROIDCAMERAFRAMEWORK_CAMERASESSIONOUTPUTCONTAINER_H
