#ifndef ANDROIDCAMERAFRAMEWORK_OPENGLMESH_H
#define ANDROIDCAMERAFRAMEWORK_OPENGLMESH_H

#include <GLES2/gl2.h>

class OpenGLMesh {
public:
    OpenGLMesh();
    virtual ~OpenGLMesh();

protected:
    virtual GLfloat* GetVertices() = 0;
    virtual GLuint GetVertixCount() = 0;
    virtual GLuint* GetIndices() = 0;
    virtual GLuint GetIndexCount() = 0;

public:
    void Create();
    void Delete();

public:
    GLuint GetVertexBufferId();
    GLuint GetIndexBufferId();

private:
    GLuint m_VertexBufferId;
    GLuint m_IndexBufferId;
};

#endif //ANDROIDCAMERAFRAMEWORK_OPENGLMESH_H
