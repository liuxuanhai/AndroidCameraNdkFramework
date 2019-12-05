#ifndef ANDROIDCAMERAFRAMEWORK_OPENGLTEXTUREEXTERNALOES_H
#define ANDROIDCAMERAFRAMEWORK_OPENGLTEXTUREEXTERNALOES_H

#include "OpenGLTexture.h"

class OpenGLTextureExternalOES : public OpenGLTexture {
public:
    virtual void CreateTexture(GLuint textureId);
    virtual void ActiveTexture();
};

#endif //ANDROIDCAMERAFRAMEWORK_OPENGLTEXTUREEXTERNALOES_H
