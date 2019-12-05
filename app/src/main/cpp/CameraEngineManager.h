#ifndef ANDROIDCAMERAFRAMEWORK_CAMERAENGINEMANAGER_H
#define ANDROIDCAMERAFRAMEWORK_CAMERAENGINEMANAGER_H

#include "camera/CameraManager.h"
#include "opengl/OpenGLManager.h"

class CameraEngineManager {
public:
    static CameraEngineManager* Instance() {
        if(m_Instance == NULL) {
            m_Instance = new CameraEngineManager();
        }
        return m_Instance;
    }

private:
    static CameraEngineManager* m_Instance;

public:
    void OpenCamera(JNIEnv* env, jobject surface);
    void CloseCamera();

private:
    CameraManager m_CameraManager;

public:
    void OnSurfaceCreated(jint textureId);
    void OnSurfaceChanged(int width, int height);
    void OnSurfaceDrawFrame(JNIEnv *env, jfloatArray textureMatrix);

private:
    OpenGLManager m_OpenGLManger;
};

#endif //ANDROIDCAMERAFRAMEWORK_CAMERAENGINEMANAGER_H
