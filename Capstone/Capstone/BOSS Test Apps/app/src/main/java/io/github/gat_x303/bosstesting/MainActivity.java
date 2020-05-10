package io.github.gat_x303.bosstesting;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Context;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.io.DataOutputStream;
import java.io.IOException;
import java.util.UUID;
import java.util.ArrayList;
import java.util.Set;

public class MainActivity extends AppCompatActivity {

    TextView textview_dutyCycle, textView_stepper;
    Button btn_increaseDutyCycle, btn_decreaseDutyCycle, btn_neutral, btn_clockwise, btn_counterClockwise, btn_shoot, btn_piston1, btn_piston2, btn_piston3;

    BluetoothSocket socket;

    int dutyCycle;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        //
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        //

        //
        textview_dutyCycle = (TextView)findViewById(R.id.text_DutyCycle);
        btn_increaseDutyCycle = (Button)findViewById(R.id.button_increaseDutyCycle);
        btn_decreaseDutyCycle = (Button)findViewById(R.id.button_decreaseDutyCycle);
        btn_neutral = (Button) findViewById(R.id.button_neutral);
        btn_clockwise = (Button)findViewById(R.id.button_clockwise);
        btn_counterClockwise = (Button)findViewById(R.id.button_counterClockwise);


        btn_shoot = (Button)findViewById(R.id.button_shoot);
        btn_piston1 = (Button)findViewById(R.id.button_piston1);
        btn_piston2 = (Button)findViewById(R.id.button_piston2);
        btn_piston3 = (Button)findViewById(R.id.button_piston3);
        //

        //Bluetooth connectivity
        BluetoothAdapter bluetoothAdapter = BluetoothAdapter.getDefaultAdapter(); //the bluetooth manager

        //generic, need to research this more
        final UUID myUUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");

        if (!bluetoothAdapter.isEnabled()) {
            //ask to the user turn the bluetooth on
            Intent turnBTon = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
            startActivityForResult(turnBTon,1);
        }

        Set<BluetoothDevice> pairedDevices = bluetoothAdapter.getBondedDevices(); //gets the list of bluetooth connected devices

        //ArrayList btList = new ArrayList();
        if (pairedDevices.size() > 0){
            for (BluetoothDevice bt : pairedDevices) {
                //btList.add(bt.getName() + "\n" + bt.getAddress())
                if (bt.getName().equals("HC-06")){
                    try {
                        socket = bt.createRfcommSocketToServiceRecord(myUUID);
                        bluetoothAdapter.cancelDiscovery();
                        socket.connect();
                    } catch (IOException e) {
                        Log.d("SOCKET ERROR", e.toString());
                    }
                }
            }
        } else {
            Toast.makeText(getApplicationContext(), "No BT", Toast.LENGTH_LONG);
        }

        btn_increaseDutyCycle.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                try {
                    socket.getOutputStream().write(101);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });

        btn_decreaseDutyCycle.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                try {
                    socket.getOutputStream().write(100);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });

        btn_neutral.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                returnNeutral();
            }
        });

        btn_clockwise.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                try {
                    clockwiseTurn();
                } catch (IOException e) {
                    Log.d("BTN PRESS ERROR", e.toString());
                }
            }
        });

        btn_counterClockwise.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                try {
                    counterClockwiseTurn();
                } catch (IOException e) {
                    Log.d("BTN PRESS ERROR", e.toString());
                }
            }
        });

        btn_shoot.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                shoot();
            }
        });

        btn_piston1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                piston1();
            }
        });

        btn_piston2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                piston2();
            }
        });

        btn_piston3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                piston3();
            }
        });

    }

    private void clockwiseTurn() throws IOException {

        if(socket.isConnected()){
            Log.d("BT CONNECTED", "VERY GOOD");
        } else {
            Log.d("BT NOT CONNECTED", "VERY BAD");
        }

        try {
            socket.getOutputStream().write(2);
        } catch (IOException e) {
            Log.d("BT STREAM ERROR", e.toString());
        }
    }

    private void counterClockwiseTurn() throws IOException {

        if(socket.isConnected()){
            Log.d("BT CONNECTED", "VERY GOOD");
        } else {
            Log.d("BT NOT CONNECTED", "VERY BAD");
        }

        try {
            //socket.getOutputStream().write("-1".getBytes());
            socket.getOutputStream().write(1);
        } catch (IOException e) {
            Log.d("BT STREAM ERROR", e.toString());
        }
    }

    private void returnNeutral(){
        try {
            socket.getOutputStream().write(3);
        } catch (IOException e){
            Log.d("BT STREAM ERROR", e.toString());
        }
    }

    private void shoot(){
        try {
            socket.getOutputStream().write(4);
        } catch (IOException e){
            Log.d("BT STREAM ERROR", e.toString());
        }
    }

    private void piston1(){
        try {
            socket.getOutputStream().write(5);
        } catch (IOException e){
            Log.d("BT STREAM ERROR", e.toString());
        }
    }

    private void piston2(){
        try {
            socket.getOutputStream().write(6);
        } catch (IOException e){
            Log.d("BT STREAM ERROR", e.toString());
        }
    }

    private void piston3(){
        try {
            socket.getOutputStream().write(7);
        } catch (IOException e){
            Log.d("BT STREAM ERROR", e.toString());
        }
    }
}

