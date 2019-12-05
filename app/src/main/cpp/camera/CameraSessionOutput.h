#ifndef ANDROIDCAMERAFRAMEWORK_CAMERASESSIONOUTPUT_H
#define ANDROIDCAMERAFRAMEWORK_CAMERASESSIONOUTPUT_H

#include <camera/NdkCameraManager.h>
#include <camera/NdkCameraDevice.h>

class CameraSessionOutput {
public:
    CameraSessionOutput();
    virtual ~CameraSessionOutput();

public:
    void Open(ANativeWindow* textureWindow);
    void Close();

public:
    ACaptureSessionOutput* GetSessionOutput() const;

private:
    ACaptureSessionOutput* m_SessionOutput;
};


#endif //ANDROIDCAMERAFRAMEWORK_CAMERASESSIONOUTPUT_H
