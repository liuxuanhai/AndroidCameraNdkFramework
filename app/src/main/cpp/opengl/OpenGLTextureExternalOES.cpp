#include "OpenGLTextureExternalOES.h"

void OpenGLTextureExternalOES::CreateTexture(GLuint textureId) {
    m_TextureId = textureId;
    glBindTexture(GL_TEXTURE_EXTERNAL_OES, m_TextureId);
}

void OpenGLTextureExternalOES::ActiveTexture() {
    OpenGLTexture::ActiveTexture();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}