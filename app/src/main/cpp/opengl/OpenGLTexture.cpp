#include "OpenGLTexture.h"

OpenGLTexture::OpenGLTexture() : m_TextureId(0) {
}

OpenGLTexture::~OpenGLTexture() {
}

GLuint OpenGLTexture::GetTextureId() {
    return m_TextureId;
}

void OpenGLTexture::ActiveTexture() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_EXTERNAL_OES, m_TextureId);
}
