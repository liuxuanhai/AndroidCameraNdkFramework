# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             native-lib.cpp

            ${CMAKE_CURRENT_SOURCE_DIR}/CameraEngineManager.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/camera/CameraCaptureRequest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/camera/CameraCaptureSession.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/camera/CameraDevice.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/camera/CameraManager.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/camera/CameraOutputTarget.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/camera/CameraSessionOutput.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/camera/CameraSessionOutputContainer.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/common/Logger.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/opengl/OpenGLManager.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/opengl/OpenGLMesh.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/opengl/OpenGLMeshRectangle.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/opengl/OpenGLModel.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/opengl/OpenGLModelCameraScreen.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/opengl/OpenGLShader.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/opengl/OpenGLShaderA.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/opengl/OpenGLShaderB.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/opengl/OpenGLShaderDefault.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/opengl/OpenGLTexture.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/opengl/OpenGLTextureExternalOES.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/opengl/OpenGLTextureImage.cpp
        )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log
        )

find_library(camera-lib camera2ndk)
find_library(gl-lib GLESv2)
find_library(android-lib android)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib}

                       ${camera-lib}
                       ${gl-lib}
                       ${android-lib}
        )
