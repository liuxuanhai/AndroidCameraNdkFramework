#include "OpenGLMesh.h"

OpenGLMesh::OpenGLMesh() : m_VertexBufferId(0), m_IndexBufferId(0) {
}

OpenGLMesh::~OpenGLMesh() {
}

void OpenGLMesh::Create() {
    //.
    glGenBuffers(1, &m_VertexBufferId);
    glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferId);
    glBufferData(GL_ARRAY_BUFFER, GetVertixCount(), GetVertices(), GL_DYNAMIC_DRAW);

    //.
    glGenBuffers(1, &m_IndexBufferId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, GetIndexCount(), GetIndices(), GL_DYNAMIC_DRAW);
}

void OpenGLMesh::Delete() {
    glDeleteBuffers(1, &m_VertexBufferId);
    glDeleteBuffers(1, &m_IndexBufferId);
}

GLuint OpenGLMesh::GetVertexBufferId() {
    return m_VertexBufferId;
}

GLuint OpenGLMesh::GetIndexBufferId() {
    return m_IndexBufferId;
}
