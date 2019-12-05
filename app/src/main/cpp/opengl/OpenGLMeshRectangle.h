#ifndef ANDROIDCAMERAFRAMEWORK_OPENGLMESHRECTANGLE_H
#define ANDROIDCAMERAFRAMEWORK_OPENGLMESHRECTANGLE_H

#include "OpenGLMesh.h"

class OpenGLMeshRectangle : public OpenGLMesh {
protected:
    virtual GLfloat* GetVertices();
    virtual GLuint GetVertixCount();
    virtual GLuint* GetIndices();
    virtual GLuint GetIndexCount();
};

#endif //ANDROIDCAMERAFRAMEWORK_OPENGLMESHRECTANGLE_H
