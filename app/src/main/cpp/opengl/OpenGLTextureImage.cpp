#include "OpenGLTextureImage.h"

void OpenGLTextureImage::CreateTexture(const char* name) {
}

void OpenGLTextureImage::LoadImage(GLubyte* data, int width, int height) {
    //.
    glGenTextures(1, &m_TextureId);
    glBindTexture(GL_TEXTURE_EXTERNAL_OES, m_TextureId);
    glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RGBA,
            width,
            height,
            0,
            GL_RGBA,
            GL_UNSIGNED_BYTE,
            data
    );
}

void OpenGLTextureImage::DeleteTexture() {
    glDeleteTextures(1, &m_TextureId);
}

void OpenGLTextureImage::ActiveTexture() {
    OpenGLTexture::ActiveTexture();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}