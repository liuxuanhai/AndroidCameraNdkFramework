#ifndef ANDROIDCAMERAFRAMEWORK_OPENGLMODEL_H
#define ANDROIDCAMERAFRAMEWORK_OPENGLMODEL_H

#include "OpenGLShader.h"
#include "OpenGLMesh.h"
#include "OpenGLTexture.h"

class OpenGLModel {
public:
    OpenGLModel();
    virtual ~OpenGLModel();

public:
    void LoadShader(OpenGLShader* shader);
    OpenGLShader* GetShader();

protected:
    OpenGLShader* m_Shader;

public:
    void LoadMesh(OpenGLMesh* mesh);
    OpenGLMesh* GetMesh();

protected:
    OpenGLMesh* m_Mesh;

public:
    void LoadTexture(OpenGLTexture* texture);
    OpenGLTexture* GetTexture();

protected:
    OpenGLTexture* m_Texture;

public:
    static OpenGLShader* GetDefaultOpenGLShader();
    static OpenGLMesh* GetDefaultOpenGLMesh();

private:
    static OpenGLShader* m_DefaultOpenGLShader;
    static OpenGLMesh* m_DefaultOpenGLMesh;
};

#endif //ANDROIDCAMERAFRAMEWORK_OPENGLMODEL_H
