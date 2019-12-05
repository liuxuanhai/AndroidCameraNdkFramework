#ifndef ANDROIDCAMERAFRAMEWORK_OPENGLMANAGER_H
#define ANDROIDCAMERAFRAMEWORK_OPENGLMANAGER_H

#include <jni.h>
#include "OpenGLShaderA.h"
#include "OpenGLShaderB.h"
#include "OpenGLModelCameraScreen.h"

class OpenGLManager {
public:
    OpenGLManager();
    virtual ~OpenGLManager();

private:
    OpenGLModelCameraScreen m_CameraScreen;

public:
    void OnSurfaceCreated(jint textureId);
    void OnSurfaceChanged(int width, int height);
    void OnSurfaceDrawFrame(JNIEnv* env, jfloatArray textureMatrix);

protected:
    void ortho(float *mat4, float left, float right, float bottom, float top, float near, float far);

private:
    int m_Width;
    int m_Height;
};

#endif //ANDROIDCAMERAFRAMEWORK_OPENGLMANAGER_H
