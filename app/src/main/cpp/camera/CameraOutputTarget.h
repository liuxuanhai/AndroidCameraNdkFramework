#ifndef ANDROIDCAMERAFRAMEWORK_CAMERAOUTPUTTARGET_H
#define ANDROIDCAMERAFRAMEWORK_CAMERAOUTPUTTARGET_H

#include <camera/NdkCameraManager.h>
#include <camera/NdkCameraDevice.h>

class CameraOutputTarget {
public:
    CameraOutputTarget();
    virtual ~CameraOutputTarget();

public:
    void Open(ACameraOutputTarget* cameraOutputTarget);
    void Close();

public:
    ACameraOutputTarget* GetCameraOutputTarget() const;

private:
    ACameraOutputTarget* m_CameraOutputTarget;
};


#endif //ANDROIDCAMERAFRAMEWORK_CAMERAOUTPUTTARGET_H
