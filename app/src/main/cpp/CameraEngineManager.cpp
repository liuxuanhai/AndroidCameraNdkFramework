#include "CameraEngineManager.h"

CameraEngineManager* CameraEngineManager::m_Instance = NULL;

void CameraEngineManager::OpenCamera(JNIEnv* env, jobject surface) {
    m_CameraManager.Open(env, surface);
}

void CameraEngineManager::CloseCamera() {
    m_CameraManager.Close();
}

void CameraEngineManager::OnSurfaceCreated(jint textureId) {
    m_OpenGLManger.OnSurfaceCreated(textureId);
}

void CameraEngineManager::OnSurfaceChanged(int width, int height) {
    m_OpenGLManger.OnSurfaceChanged(width, height);
}

void CameraEngineManager::OnSurfaceDrawFrame(JNIEnv *env, jfloatArray textureMatrix) {
    m_OpenGLManger.OnSurfaceDrawFrame(env, textureMatrix);
}
