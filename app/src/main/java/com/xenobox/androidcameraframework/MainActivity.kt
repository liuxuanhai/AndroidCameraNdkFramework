package com.xenobox.androidcameraframework

import android.content.pm.PackageManager
import android.os.Build
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Toast
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        if(!checkFeatureCamera()) {
            Toast.makeText(this, "휴대폰에 카메라가 없어 앱을 종료합니다.", Toast.LENGTH_SHORT).show()
            finish()
        }
    }

    override fun onResume() {
        super.onResume()

        if(checkCameraPermission()) {
            idCameraGLSurfceView.onResume()
            openCamera()
        }
        else {
            requestCameraPermission()
        }
    }

    override fun onPause() {
        super.onPause()

        idCameraGLSurfceView.onPause()
        closeCamera()
    }

    private fun checkFeatureCamera() : Boolean {
        return packageManager.hasSystemFeature((PackageManager.FEATURE_CAMERA))
    }

    private fun checkCameraPermission() : Boolean {
        if(Build.VERSION.SDK_INT >= 23) {
            return checkSelfPermission(android.Manifest.permission.CAMERA) == PackageManager.PERMISSION_GRANTED
        }
        return true
    }

    private fun requestCameraPermission() {
        requestPermissions(arrayOf(android.Manifest.permission.CAMERA), REQUEST_CODE_CAMERA_PERMISSION)
    }

    override fun onRequestPermissionsResult(
        requestCode: Int,
        permissions: Array<out String>,
        grantResults: IntArray
    ) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults)
        if (requestCode == REQUEST_CODE_CAMERA_PERMISSION) {
            if (grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                openCamera()
            } else {
                Toast.makeText(this, "카메라 퍼미션을 허락하지 않아 앱을 종료합니다.", Toast.LENGTH_SHORT).show()
                finish()
            }
        }
    }

    external fun openCamera()
    external fun closeCamera()

    companion object {
        const val REQUEST_CODE_CAMERA_PERMISSION = 100000
        init {
            System.loadLibrary("native-lib")
        }
    }
}
