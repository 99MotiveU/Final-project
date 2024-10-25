package com.example.bluetoothsolenoid

import android.os.Bundle
import android.widget.Button
import androidx.appcompat.app.AppCompatActivity
import androidx.biometric.BiometricPrompt
import androidx.biometric.BiometricManager
import androidx.core.content.ContextCompat

class MainActivity : AppCompatActivity() {
    private lateinit var authenticateButton: Button

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        authenticateButton = findViewById(R.id.authenticate_button)
        authenticateButton.setOnClickListener {
            authenticateUser()
        }
    }

    private fun authenticateUser() {
        val biometricManager = BiometricManager.from(this)
        when (biometricManager.canAuthenticate()) {
            BiometricManager.Authenticators.SUCCESS -> {
                showBiometricPrompt()
            }
            BiometricManager.Authenticators.ERROR_NO_HARDWARE -> {

            }
            BiometricManager.Authenticators.ERROR_HW_UNAVAILABLE -> {

            }
            BiometricManager.Authenticators.ERROR_NONE_ENROLLED -> {

            }
        }
    }

    private fun showBiometricPrompt() {
        val executor = ContextCompat.getMainExecutor(this)
        val biometricPrompt = BiometricPrompt(this, executor,
            object : BiometricPrompt.AuthenticationCallback() {
                override fun onAuthenticationSucceeded(result: BiometricPrompt.AuthenticationResult) {
                    super.onAuthenticationSucceeded(result)

                }

                override fun onAuthenticationFailed() {
                    super.onAuthenticationFailed()
                    // 인증 실패 시 처리
                }
            })

        val promptInfo = BiometricPrompt.PromptInfo.Builder()
            .setTitle("지문 인증")
            .setSubtitle("지문을 사용하여 잠금을 해제하세요")
            .setNegativeButtonText("취소")
            .build()

        biometricPrompt.authenticate(promptInfo)
    }
}
