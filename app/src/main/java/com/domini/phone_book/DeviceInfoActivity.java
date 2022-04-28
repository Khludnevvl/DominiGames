package com.domini.phone_book;

import android.app.Activity;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.annotation.RequiresApi;

public class DeviceInfoActivity extends Activity {

    private void printInfo(){
        System.getProperty("os.version");
        TextView modelInfo = findViewById(R.id.text_view_device_model_info);
        modelInfo.setText(Build.MODEL.toString());
        TextView brandInfo = findViewById(R.id.text_view_device_brand_info);
        brandInfo.setText(Build.BRAND.toString());
        TextView osVersion = findViewById(R.id.text_view_os_version_info);
        osVersion.setText(Build.VERSION.RELEASE.toString());

    }
    @RequiresApi(api = Build.VERSION_CODES.N_MR1)
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_device_info);

        Button backButton = findViewById(R.id.button_info_back);
        backButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(DeviceInfoActivity.this,
                        MainActivity.class);
                startActivity(intent);
            }
        });

        printInfo();
    }
}
