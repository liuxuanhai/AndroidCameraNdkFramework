package com.xenobox.androidcameraframework

import android.content.Context
import android.opengl.GLSurfaceView
import android.util.AttributeSet

class CameraGLSurfaceView : GLSurfaceView {
    constructor(context: Context, attrs: AttributeSet?) : super(context, attrs) {
        setEGLContextClientVersion(2)
        setRenderer(CameraGLSurfaceViewRenderer())
    }
}