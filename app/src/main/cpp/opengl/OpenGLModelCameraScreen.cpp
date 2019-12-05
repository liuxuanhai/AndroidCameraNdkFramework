#include "OpenGLModelCameraScreen.h"
#include "OpenGLTextureExternalOES.h"
#include "OpenGLShaderA.h"
#include "OpenGLMeshRectangle.h"

OpenGLModelCameraScreen::OpenGLModelCameraScreen() {
    LoadShader(new OpenGLShaderA());
    LoadMesh(new OpenGLMeshRectangle());
    LoadTexture(new OpenGLTextureExternalOES());
}

OpenGLModelCameraScreen::~OpenGLModelCameraScreen() {
}
