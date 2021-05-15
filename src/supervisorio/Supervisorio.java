package supervisorio;

import serial.SerialRxTx;

public class Supervisorio {

	public static void main(String[] args) throws InterruptedException {
		SerialRxTx serial = new SerialRxTx();
		System.out.println("Error");
		if(serial.iniciaSerial()) {
			while(true) {
					if(serial.getProtocolo().getDistancia()>=100 ) {
							serial.sendData("a");
							System.out.println("sending < a >...");
						}
					if(serial.getProtocolo().getDistancia()<100 ) {
						serial.sendData("b");
						System.out.println("sending < b >...");	
					}
				Thread.sleep(100);	
			}
				
		} 
		else {
			System.out.println("Error");
		}
	}

}
