#include "OpenGLMeshRectangle.h"

GLfloat v[20] = {
        // x, y, z, u, v
        -1, -1, 0, 0, 0,
        -1, 1, 0, 0, 1,
        1, 1, 0, 1, 1,
        1, -1, 0, 1, 0
};

GLuint i[6] = {2, 1, 0, 0, 3, 2};

GLfloat* OpenGLMeshRectangle::GetVertices() {
    return v;
}

GLuint OpenGLMeshRectangle::GetVertixCount() {
    return sizeof(v);
}

GLuint* OpenGLMeshRectangle::GetIndices() {
    return i;
}

GLuint OpenGLMeshRectangle::GetIndexCount() {
    return sizeof(i);
}
