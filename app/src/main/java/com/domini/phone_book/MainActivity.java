package com.domini.phone_book;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.SimpleAdapter;


import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class MainActivity extends AppCompatActivity {
    // Used to load the 'phone_book' library on application startup.
    static {
        System.loadLibrary("phone_book");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        createButtonListeners();
        showContacts(getAllContacts());
    }

    private void createButtonListeners(){
        Button clearButton = findViewById(R.id.button_clear);
        clearButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                EditText editText = findViewById(R.id.edit_text_find);
                editText.setText("");
                showContacts(getAllContacts());
            }
        });

        Button findButton = findViewById(R.id.button_find);
        findButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                EditText editText = findViewById(R.id.edit_text_find);
                showContacts(getContactsByName(editText.getText().toString()));
                editText.setText("");
            }
        });

        Button updateButton = findViewById(R.id.button_update);
        updateButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                showContacts(getAllContacts());
            }
        });
        Button addButton = findViewById(R.id.button_add);
        addButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(MainActivity.this ,
                        AddContactActivity.class);
                startActivity(intent);
            }
        });
        Button infoButton = findViewById(R.id.button_info);
        infoButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(MainActivity.this ,
                        DeviceInfoActivity.class);
                startActivity(intent);
            }
        });
    }

    private List<HashMap<String,String>> convertJSONToList(JSONArray jsonArray)  {
        List<HashMap<String,String>> result = new ArrayList<>();
        for(int i = 0; i < jsonArray.length(); i++){
            JSONObject cur_contact = jsonArray.optJSONObject(i);
            HashMap<String, String> tmp_map = new HashMap<>();
            tmp_map.put("First Line", cur_contact.opt("name").toString());
            tmp_map.put("Second Line",  cur_contact.opt("phone").toString());
            result.add(tmp_map);
        }
        return result;
    }

    private void showContacts(String json_str){
        try {
            ListView contactList = findViewById(R.id.contact_list);
            JSONArray phoneBookJSON = new JSONArray(json_str);
            List<HashMap<String,String>> phone_book = convertJSONToList(phoneBookJSON);
            SimpleAdapter adapter = new SimpleAdapter(this, phone_book, R.layout.list_item,
                    new String[]{"First Line","Second Line"}, new int[]{R.id.name, R.id.phone});

            contactList.setAdapter(adapter);

        } catch (JSONException e) {
            e.printStackTrace();
        }
    }
    public native String getAllContacts();
    private native String getContactsByName(String name);
}