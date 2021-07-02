package supervisorio;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

import embedded.mas.bridges.jacamo.Literal;
import serial.SerialRxTx;

public class Supervisorio {

	public static void main(String[] args) throws InterruptedException, IOException {
		SerialRxTx serial = new SerialRxTx("/dev/ttyUSB0",9600);
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String beliefs[] = null;
		String s;
		
		if(serial.iniciaSerial()) {
			while(serial.isConectado()) {
			
				ArrayList<String> percepts = new ArrayList<String>(); //adicionar os valores lidos arduino na lista percepts (dúvidas - olhar DemoDevice)
				try {
					beliefs = serial.read().split(",");percepts.add(beliefs[0]);
					percepts.add(beliefs[1]);
					percepts.add(beliefs[2]);
					percepts.add(beliefs[3]);
					percepts.add(beliefs[4]);
					
					//String beliefs = serial.read();
					System.out.println(percepts);
				} catch (Exception e) {
					e.printStackTrace();
				}
			
				Thread.sleep(500);
				
				s = br.readLine();
				if(s.equals("e")) {
					System.out.println("Fechando porta serial");
					serial.close();
				}
				
			}
		}else {
			System.out.println("Error");
		}
		
	}

}
