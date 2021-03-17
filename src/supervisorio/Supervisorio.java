package supervisorio;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import serial.SerialRxTx;

public class Supervisorio {

	public static void main(String[] args) throws InterruptedException, IOException {
		SerialRxTx serial = new SerialRxTx();
		System.out.println("Error");
		if(serial.iniciaSerial()) {
			
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			while(true) {
				try {
					String s = br.readLine();
					System.out.println("sending " + s + "...");
					serial.sendData(s);
				} catch (IOException e) {e.printStackTrace();}
			}
				
		} 
		else {
			System.out.println("Error");
		}
	}

}
