package com.domini.phone_book;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.domini.phone_book.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'phone_book' library on application startup.
    static {
        System.loadLibrary("phone_book");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText(stringFromJNI());
    }

    /**
     * A native method that is implemented by the 'phone_book' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}