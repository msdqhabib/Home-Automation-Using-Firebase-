package com.prank.cardviewdesign;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.RadioButton;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;

import com.google.firebase.database.ChildEventListener;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import java.util.ArrayList;

public class RoomsActivity extends AppCompatActivity {

    Switch  light1 , light2 , light3 , light4 ;

    FirebaseDatabase rootNode;
    DatabaseReference reference;



    int stateon =  1;
    int stateoff = 0 ;
    int s1 , s2 , s3 , s4 ;
    @SuppressLint("WrongViewCast")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_rooms);

         light1 = (Switch) findViewById(R.id.switch1);
         light2 = (Switch) findViewById(R.id.switch2);
         light3 = (Switch) findViewById(R.id.switch3);
         light4 = (Switch) findViewById(R.id.switch4);






        light1.setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
        rootNode = FirebaseDatabase.getInstance();
        reference = rootNode.getReference("Lights");

        {if(light1.isChecked()){
            s1 = stateon;
        }
        else {
            s1 = stateoff;
        }}

        {if(light2.isChecked()){
            s2 = stateon;
        }
        else {
            s2 = stateoff;
        }}

        {if(light3.isChecked()){
            s3 = stateon;
        }
        else {
            s3 = stateoff;
        }}

        {if(light4.isChecked()){
            s4 = stateon;
        }
        else {
            s4 = stateoff;
        }}





        data udata = new data(s1 , s2 , s3 ,s4);
        reference.child("switch status").setValue(udata);


    }
});


        //for light 2
        light2.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                rootNode = FirebaseDatabase.getInstance();
                reference = rootNode.getReference("Lights");

                {if(light1.isChecked()){
                    s1 = stateon;
                }
                else {
                    s1 = stateoff;
                }}

                {if(light2.isChecked()){
                    s2 = stateon;
                }
                else {
                    s2 = stateoff;
                }}

                {if(light3.isChecked()){
                    s3 = stateon;
                }
                else {
                    s3 = stateoff;
                }}

                {if(light4.isChecked()){
                    s4 = stateon;
                }
                else {
                    s4 = stateoff;
                }}





                data udata = new data(s1 , s2 , s3 ,s4);
                reference.child("switch status").setValue(udata);


            }
        });



//for light 3
        light3.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                rootNode = FirebaseDatabase.getInstance();
                reference = rootNode.getReference("Lights");

                {if(light1.isChecked()){
                    s1 = stateon;
                }
                else {
                    s1 = stateoff;
                }}

                {if(light2.isChecked()){
                    s2 = stateon;
                }
                else {
                    s2 = stateoff;
                }}

                {if(light3.isChecked()){
                    s3 = stateon;
                }
                else {
                    s3 = stateoff;
                }}

                {if(light4.isChecked()){
                    s4 = stateon;
                }
                else {
                    s4 = stateoff;
                }}





                data udata = new data(s1 , s2 , s3 ,s4);
                reference.child("switch status").setValue(udata);


            }
        });


// for light 4
        light4.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                rootNode = FirebaseDatabase.getInstance();
                reference = rootNode.getReference("Lights");

                {if(light1.isChecked()){
                    s1 = stateon;
                }
                else {
                    s1 = stateoff;
                }}

                {if(light2.isChecked()){
                    s2 = stateon;
                }
                else {
                    s2 = stateoff;
                }}

                {if(light3.isChecked()){
                    s3 = stateon;
                }
                else {
                    s3 = stateoff;
                }}

                {if(light4.isChecked()){
                    s4 = stateon;
                }
                else {
                    s4 = stateoff;
                }}


                data udata = new data(s1 , s2 , s3 ,s4);
                reference.child("switch status").setValue(udata);


            }
        });

    }
}



