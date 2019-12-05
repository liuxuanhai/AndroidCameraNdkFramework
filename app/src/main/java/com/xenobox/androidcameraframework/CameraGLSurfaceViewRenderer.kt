package com.xenobox.androidcameraframework

import android.graphics.SurfaceTexture
import android.opengl.GLES11Ext.GL_TEXTURE_EXTERNAL_OES
import android.opengl.GLES20
import android.opengl.GLSurfaceView
import android.view.Surface
import javax.microedition.khronos.egl.EGLConfig
import javax.microedition.khronos.opengles.GL10

class CameraGLSurfaceViewRenderer : GLSurfaceView.Renderer {

    lateinit var mSurfaceTexture: SurfaceTexture
    val mSurfaceTextureMartrix = FloatArray(16)
    @Volatile var mFrameAvailable = false
    val mLock = Object()

    override fun onDrawFrame(gl: GL10?) {
        //.
        synchronized(mLock) {
            if(mFrameAvailable) {
                mSurfaceTexture.updateTexImage()
                mSurfaceTexture.getTransformMatrix(mSurfaceTextureMartrix)
                mFrameAvailable = false
            }
        }

        //.
        onDrawFrame(mSurfaceTextureMartrix)
    }

    override fun onSurfaceChanged(gl: GL10?, width: Int, height: Int) {
        onSurfaceChanged(width, height)
    }

    override fun onSurfaceCreated(gl: GL10?, config: EGLConfig?) {
        //.
        val textures = IntArray(1)
        GLES20.glGenTextures(1, textures, 0)
        GLES20.glBindTexture(GL_TEXTURE_EXTERNAL_OES, textures[0])

        mSurfaceTexture = SurfaceTexture(textures[0])
        mSurfaceTexture.setOnFrameAvailableListener {
            synchronized(mLock) {
                mFrameAvailable = true
            }
        }

        //.
        onSurfaceCreated(textures[0], Surface(mSurfaceTexture))
    }

    external fun onSurfaceCreated(textureId: Int, surface: Surface)
    external fun onSurfaceChanged(width: Int, height: Int)
    external fun onDrawFrame(surfaceTextureMartrix: FloatArray)
}
