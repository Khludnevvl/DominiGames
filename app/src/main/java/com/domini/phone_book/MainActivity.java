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

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public native String getAllContacts();
    private native String getContactsByName(String name);
}