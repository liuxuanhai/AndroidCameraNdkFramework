#include "OpenGLModel.h"
#include "OpenGLMeshRectangle.h"
#include "OpenGLShaderDefault.h"

OpenGLShader* OpenGLModel::m_DefaultOpenGLShader = new OpenGLShaderDefault();
OpenGLMesh* OpenGLModel::m_DefaultOpenGLMesh = new OpenGLMeshRectangle();

OpenGLModel::OpenGLModel() : m_Shader(NULL), m_Mesh(NULL) {
}

OpenGLModel::~OpenGLModel() {
}

void OpenGLModel::LoadShader(OpenGLShader* shader) {
    //.
    if(m_Shader != NULL) {
        m_Shader->DeleteProgram();
    }

    //.
    m_Shader = shader;
    m_Shader->CreateProgram();
}

OpenGLShader* OpenGLModel::GetShader() {
    return m_Shader;
}

void OpenGLModel::LoadMesh(OpenGLMesh* mesh) {
    //.
    if(m_Mesh != NULL) {
        m_Mesh->Delete();
    }

    //.
    m_Mesh = mesh;
    m_Mesh->Create();
}

OpenGLMesh* OpenGLModel::GetMesh() {
    return m_Mesh;
}

void OpenGLModel::LoadTexture(OpenGLTexture* texture) {
    m_Texture = texture;
}

OpenGLTexture* OpenGLModel::GetTexture() {
    return m_Texture;
}

OpenGLShader* OpenGLModel::GetDefaultOpenGLShader() {
    return m_DefaultOpenGLShader;
}

OpenGLMesh* OpenGLModel::GetDefaultOpenGLMesh() {
    return m_DefaultOpenGLMesh;
}
