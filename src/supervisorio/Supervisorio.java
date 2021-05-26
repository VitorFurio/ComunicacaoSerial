package supervisorio;

import serial.SerialRxTx;

public class Supervisorio {

	public static void main(String[] args) {
		SerialRxTx serial = new SerialRxTx();
		
		if(serial.iniciaSerial()) {
			while(true) {
				
			}
		
		} 
		else {
			
		}
	}

}
