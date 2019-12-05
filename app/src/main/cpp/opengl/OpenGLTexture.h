#ifndef ANDROIDCAMERAFRAMEWORK_OPENGLTEXTURE_H
#define ANDROIDCAMERAFRAMEWORK_OPENGLTEXTURE_H

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

class OpenGLTexture {
public:
    OpenGLTexture();
    virtual ~OpenGLTexture();

public:
    virtual void CreateTexture(const char* name) {}
    virtual void CreateTexture(GLuint textureId) {}
    virtual void DeleteTexture() {}
    virtual void ActiveTexture();

public:
    GLuint GetTextureId();

protected:
    GLuint m_TextureId;
};

#endif //ANDROIDCAMERAFRAMEWORK_OPENGLTEXTURE_H
