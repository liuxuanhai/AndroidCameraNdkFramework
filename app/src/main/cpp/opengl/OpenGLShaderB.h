#ifndef ANDROIDCAMERAFRAMEWORK_OPENGLSHADERB_H
#define ANDROIDCAMERAFRAMEWORK_OPENGLSHADERB_H

#include "OpenGLShader.h"

class OpenGLShaderB : public OpenGLShader {
protected:
    virtual const char* GetVertexShaderSource();
    virtual const char* GetFragmentShaderSource();
};

#endif //ANDROIDCAMERAFRAMEWORK_OPENGLSHADERB_H
