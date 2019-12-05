//
// Created by Administrator on 2019-12-02.
//

#ifndef ANDROIDCAMERAFRAMEWORK_CAMERAMANAGER_H
#define ANDROIDCAMERAFRAMEWORK_CAMERAMANAGER_H

#include <camera/NdkCameraManager.h>
#include <camera/NdkCameraDevice.h>
#include <jni.h>
#include "CameraDevice.h"

class CameraManager {

public:
    CameraManager();
    virtual ~CameraManager();

public:
    void Open(JNIEnv* env, jobject surface);
    void Close();

private:
    ANativeWindow* m_TextureWindow;

private:
    const char* GetSelectedCameraId();

private:
    ACameraManager* m_CameraManger;

private:
    ACameraDevice_StateCallbacks m_DeviceStateCallbacks;
    static void onDisconnected(void *context, ACameraDevice *device);
    static void onError(void *context, ACameraDevice *device, int error);

private:
    CameraDevice* m_CameraDevice;
};

#endif //ANDROIDCAMERAFRAMEWORK_CAMERAMANAGER_H
