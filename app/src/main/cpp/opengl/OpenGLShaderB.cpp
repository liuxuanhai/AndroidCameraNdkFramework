#include "OpenGLShaderB.h"

const char* OpenGLShaderB::GetVertexShaderSource() {
    return R"(
precision highp float;
attribute vec3 vertexPosition;
attribute vec2 uvs;
varying vec2 varUvs;
uniform mat4 texMatrix;
uniform mat4 mvp;
void main()
{
       varUvs = (texMatrix * vec4(uvs.x, uvs.y, 0, 1.0)).xy;
       gl_Position = mvp * vec4(vertexPosition, 1.0);
}
       )";
}

const char* OpenGLShaderB::GetFragmentShaderSource() {
       return R"(
#extension GL_OES_EGL_image_external : require
precision mediump float;
varying vec2 varUvs;
uniform samplerExternalOES texSampler;
uniform vec4 color;
uniform vec2 size;
void main()
{
       if (gl_FragCoord.x/size.x < 0.5) {
              gl_FragColor = texture2D(texSampler, varUvs) * color;
       }
       else {
              const float threshold = 1.1;
              vec4 c = texture2D(texSampler, varUvs);
              if (length(c) > threshold) {
                     gl_FragColor = vec4(0.0, 0.0, 1.0, 1.0);
              }
              else {
                     gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);"
              }
       }
}
       )";
}
