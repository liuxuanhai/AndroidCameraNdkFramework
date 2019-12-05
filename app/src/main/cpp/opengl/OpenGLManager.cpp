#include "OpenGLManager.h"

OpenGLManager::OpenGLManager() : m_Width(480), m_Height(800) {
}

OpenGLManager::~OpenGLManager() {
}

void OpenGLManager::OnSurfaceCreated(jint textureId) {
    m_CameraScreen.GetTexture()->CreateTexture(textureId);
}

void OpenGLManager::OnSurfaceChanged(int width, int height) {
    m_Width = width;
    m_Height = height;
}

void OpenGLManager::OnSurfaceDrawFrame(JNIEnv* env, jfloatArray textureMatrix) {
    //.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glClearColor(0, 0, 0, 1);

    //. Configure main transformations
    float mvp[] = {
            1.0f, 0, 0, 0,
            0, 1.0f, 0, 0,
            0, 0, 1.0f, 0,
            0, 0, 0, 1.0f
    };
    float aspect = m_Width > m_Height ? float(m_Width)/float(m_Height) : float(m_Height)/float(m_Width);
    if (m_Width < m_Height) // portrait
        ortho(mvp, -1.0f, 1.0f, -aspect, aspect, -1.0f, 1.0f);
    else // landscape
        ortho(mvp, -aspect, aspect, -1.0f, 1.0f, -1.0f, 1.0f);
    glUniformMatrix4fv(
            m_CameraScreen.GetShader()->GetUniformLocation("mvp"),
            1,
            false,
            mvp);

    //. Prepare texture for drawing
    m_CameraScreen.GetTexture()->ActiveTexture();

    // Pass SurfaceTexture transformations to shader
    float* tm = env->GetFloatArrayElements(textureMatrix, 0);
    glUniformMatrix4fv(
            m_CameraScreen.GetShader()->GetUniformLocation("texMatrix"),
            1,
            false,
            tm);
    env->ReleaseFloatArrayElements(textureMatrix, tm, 0);

    //. Set the SurfaceTexture sampler
    glUniform1i(
            m_CameraScreen.GetShader()->GetUniformLocation("texSampler"),
            0);

    // I use red color to mix with camera frames
    float c[] = { 1, 0, 0, 1 };
    glUniform4fv(
            m_CameraScreen.GetShader()->GetUniformLocation("color"),
            1,
            (GLfloat*)c);

    // Size of the window is used in fragment shader to split the window
    float sz[2] = {0};
    sz[0] = m_Width;
    sz[1] = m_Height;
    glUniform2fv(
            m_CameraScreen.GetShader()->GetUniformLocation("size"),
            1,
            (GLfloat*)sz);

    // Set up vertices/indices and draw
    glBindBuffer(GL_ARRAY_BUFFER, m_CameraScreen.GetMesh()->GetVertexBufferId());
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_CameraScreen.GetMesh()->GetIndexBufferId());

    GLuint vtxPosAttrib = m_CameraScreen.GetShader()->GetAttribLocation("vertexPosition");
    glEnableVertexAttribArray(vtxPosAttrib);
    glVertexAttribPointer(vtxPosAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);

    GLuint uvsAttrib = m_CameraScreen.GetShader()->GetAttribLocation("uvs");
    glEnableVertexAttribArray(uvsAttrib);
    glVertexAttribPointer(uvsAttrib, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void *)(3 * sizeof(float)));

    glViewport(0, 0, m_Width, m_Height);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void OpenGLManager::ortho(float *mat4, float left, float right, float bottom, float top, float near, float far)
{
    float rl = right - left;
    float tb = top - bottom;
    float fn = far - near;

    mat4[0] = 2.0f / rl;
    mat4[12] = -(right + left) / rl;

    mat4[5] = 2.0f / tb;
    mat4[13] = -(top + bottom) / tb;

    mat4[10] = -2.0f / fn;
    mat4[14] = -(far + near) / fn;
}