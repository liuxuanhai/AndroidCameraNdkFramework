#include "OpenGLShaderA.h"

const char* OpenGLShaderA::GetVertexShaderSource() {
       return R"(
uniform mat4 uMVPMatrix; // 호출측에서 4x4 행렬을 전달한다. 이곳에서 이 행렬을 사용하지 않으면 오류가 발생한다
attribute vec4 aPosition; // 호출측에서 전달하는 배열이며 모든 정점에 매핑될 데이터이다. 버텍스 쉐이더에서만  사용할 수 있다.
attribute vec2 aTextureCoord;
varying vec2 vTextureCoord // Fragment Shader로 전달되는 데이터
void main ()
{
       gl_Position = uMVPMatrix * aPosition; // gl_Position 은 시스템으로 전달되는 내장 변수
       vTextureCoord = aTextureCoord; // Framgment Shader(Pixel Shader)로 전달될 값을 할당함
}
       )";
}

const char* OpenGLShaderA::GetFragmentShaderSource() {
       return R"(
precision mediump float; // 쉐이더의 정밀도를 설정한다
varying vec2 vTextureCoord; // Vertex Shader에서 Fragment Shader로 전달되는 값. 양측의 변수명과 자료형이 일치해야 한다.
uniform sampler2D sTexture; // sampler1D, sampler2D, sampler3D등은 텍스쳐 정보를 Fragment Shader로 전달하기 위한 내장 타입
void main()
{
       gl_FragColor = texture2D(sTexture, vTextureCoord); // Fragment Shader에서 시스템으로 전달할  값을 할당한다.
       // 개발자는 이 곳에서 다양한 계산을 수행할 수 있다
}
       )";
}
