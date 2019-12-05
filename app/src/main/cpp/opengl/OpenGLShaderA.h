#ifndef ANDROIDCAMERAFRAMEWORK_OPENGLSHADERA_H
#define ANDROIDCAMERAFRAMEWORK_OPENGLSHADERA_H

#include "OpenGLShader.h"

class OpenGLShaderA : public OpenGLShader {
protected:
    virtual const char* GetVertexShaderSource();
    virtual const char* GetFragmentShaderSource();
};

#endif //ANDROIDCAMERAFRAMEWORK_OPENGLSHADERA_H
