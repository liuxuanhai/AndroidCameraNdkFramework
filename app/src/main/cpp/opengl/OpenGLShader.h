#ifndef ANDROIDCAMERAFRAMEWORK_OPENGLSHADER_H
#define ANDROIDCAMERAFRAMEWORK_OPENGLSHADER_H

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include "OpenGLMesh.h"

class OpenGLShader {
public:
    OpenGLShader();
    virtual ~OpenGLShader();

protected:
    virtual const char* GetVertexShaderSource() = 0;
    virtual const char* GetFragmentShaderSource() = 0;

private:
    GLuint CreateShader(GLenum shaderType, const char *shaderSource);
    void DeleteShader(GLuint shaderId);

protected:
    GLuint m_VertexShaderId;
    GLuint m_FragmentShaderId;

public:
    GLuint GetAttribLocation(const char* name);
    GLuint GetUniformLocation(const char* name);

public:
    void CreateProgram();
    void DeleteProgram();
    void UseProgram();

protected:
    GLuint m_ProgramId;
};


#endif //ANDROIDCAMERAFRAMEWORK_OPENGLSHADER_H
