#ifndef ANDROIDCAMERAFRAMEWORK_OPENGLSHADERDEFAULT_H
#define ANDROIDCAMERAFRAMEWORK_OPENGLSHADERDEFAULT_H

#include "OpenGLShader.h"

class OpenGLShaderDefault : public OpenGLShader {
protected:
    virtual const char* GetVertexShaderSource();
    virtual const char* GetFragmentShaderSource();
};

#endif //ANDROIDCAMERAFRAMEWORK_OPENGLSHADERDEFAULT_H
