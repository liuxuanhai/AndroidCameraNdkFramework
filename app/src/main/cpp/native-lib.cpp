#include <jni.h>
#include <string>
#include "CameraEngineManager.h"

#ifdef __cplusplus
extern "C" {
#endif
    JNIEXPORT void JNICALL
    Java_com_xenobox_androidcameraframework_MainActivity_openCamera(JNIEnv *env, jobject) {
    }

    JNIEXPORT void JNICALL
    Java_com_xenobox_androidcameraframework_MainActivity_closeCamera(JNIEnv *env, jobject) {
        CameraEngineManager::Instance()->CloseCamera();
    }

    JNIEXPORT void JNICALL
    Java_com_xenobox_androidcameraframework_CameraGLSurfaceViewRenderer_onSurfaceCreated(JNIEnv *env, jobject, jint textureId, jobject surface) {
        CameraEngineManager::Instance()->OnSurfaceCreated(textureId);
        CameraEngineManager::Instance()->OpenCamera(env, surface);
    }

    JNIEXPORT void JNICALL
    Java_com_xenobox_androidcameraframework_CameraGLSurfaceViewRenderer_onSurfaceChanged(JNIEnv *env, jobject, jint width, jint height) {
        CameraEngineManager::Instance()->OnSurfaceChanged(width, height);
    }

    JNIEXPORT void JNICALL
    Java_com_xenobox_androidcameraframework_CameraGLSurfaceViewRenderer_onDrawFrame(JNIEnv *env, jobject, jfloatArray textureMatrix) {
        CameraEngineManager::Instance()->OnSurfaceDrawFrame(env, textureMatrix);
    }
#ifdef __cplusplus
}
#endif
