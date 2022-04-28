package com.domini.phone_book;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class AddContactActivity extends Activity {
    static {
        System.loadLibrary("phone_book");
    }

    private void returnToMainActivity(){
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_contact);

        Button saveButton = findViewById(R.id.button_save_contact);
        saveButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String name = ((EditText) findViewById(R.id.edit_text_name)).getText().toString();
                String phone = ((EditText) findViewById(R.id.edit_text_phone)).getText().toString();
                addNewContact(name, phone);
                returnToMainActivity();
            }
        });

        Button backButton = findViewById(R.id.button_add_window_back);
        backButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                returnToMainActivity();
            }
        });
    }

    public native void addNewContact(String name, String phone);
}
