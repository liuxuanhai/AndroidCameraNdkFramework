#include "OpenGLShader.h"
#include "../common/Logger.h"

OpenGLShader::OpenGLShader() : m_VertexShaderId(0), m_FragmentShaderId(0), m_ProgramId(0) {
}

OpenGLShader::~OpenGLShader() {
    DeleteProgram();
}

GLuint OpenGLShader::CreateShader(GLenum shaderType, const char *shaderSource) {
    //
    GLuint shaderId = glCreateShader(shaderType);
    glShaderSource(shaderId, 1, &shaderSource, NULL);
    glCompileShader(shaderId);

    //.
    GLint isCompiled = 0;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE)
    {
        //.
        GLint maxLength = 0;
        glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);
        char* logStr = new char [maxLength];
        glGetShaderInfoLog(shaderId, maxLength, &maxLength, logStr);
        LOGE("Could not compile shaderId %s - %s", shaderSource, logStr);
        delete [] logStr;

        //.
        glDeleteShader(shaderId);
        shaderId = 0;
    }

    return shaderId;
}

void OpenGLShader::DeleteShader(GLuint shaderId) {
    glDeleteShader(shaderId);
}

GLuint OpenGLShader::GetAttribLocation(const char* name) {
    return glGetAttribLocation(m_ProgramId, name);
}

GLuint OpenGLShader::GetUniformLocation(const char* name) {
    return glGetUniformLocation(m_ProgramId, name);
}


void OpenGLShader::CreateProgram() {
    //.
    m_VertexShaderId = CreateShader(GL_VERTEX_SHADER, GetVertexShaderSource());
    if(m_VertexShaderId == 0) {
        return;
    }

    //.
    m_FragmentShaderId = CreateShader(GL_FRAGMENT_SHADER, GetFragmentShaderSource());
    if(m_FragmentShaderId == 0) {
        return;
    }

    //.
    m_ProgramId = glCreateProgram();
    glAttachShader(m_ProgramId, m_VertexShaderId);
    glAttachShader(m_ProgramId, m_FragmentShaderId);
    glLinkProgram(m_ProgramId);

    //.
    GLint isLinked = 0;
    glGetProgramiv(m_ProgramId, GL_LINK_STATUS, &isLinked);
    if (m_ProgramId == GL_FALSE)
    {
        //.
        GLint maxLength = 0;
        glGetProgramiv(m_ProgramId, GL_INFO_LOG_LENGTH, &maxLength);
        char* logStr = new char [maxLength];
        glGetProgramInfoLog(m_ProgramId, maxLength, &maxLength, logStr);
        LOGE("Could not create program %s %s - %s", GetVertexShaderSource(), GetFragmentShaderSource(), logStr);
        delete [] logStr;

        //.
        glDeleteProgram(m_ProgramId);
        m_ProgramId = 0;
    }
}

void OpenGLShader::DeleteProgram() {
    DeleteShader(m_VertexShaderId);
    DeleteShader(m_FragmentShaderId);
    glDeleteProgram(m_ProgramId);
}

void OpenGLShader::UseProgram() {
    glUseProgram(m_ProgramId);
}


