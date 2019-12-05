#ifndef ANDROIDCAMERAFRAMEWORK_OPENGLTEXTUREIMAGE_H
#define ANDROIDCAMERAFRAMEWORK_OPENGLTEXTUREIMAGE_H

#include "OpenGLTexture.h"

class OpenGLTextureImage : public OpenGLTexture {
public:
    virtual void CreateTexture(const char* name);
    virtual void DeleteTexture();
    virtual void ActiveTexture();

private:
    void LoadImage(GLubyte* data, int width, int height);
};

#endif //ANDROIDCAMERAFRAMEWORK_OPENGLTEXTUREIMAGE_H
