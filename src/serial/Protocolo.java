package serial;

public class Protocolo {

	private String tipoDado;
	private int tempo;
	private int distancia;
	private String luminosidade;
	
	private String leituraComando;
	private String separador = ",";
	
	public Protocolo() {
		// TODO Auto-generated constructor stub
	}

	private void interpretaComando() {
		//$STS,s1200,2,100
		String aux[] = leituraComando.split(separador);
		if(aux.length == 4) {
			tipoDado 	 = 	aux[0];
			tempo 		 = 	Integer.parseInt(aux[1]);
			distancia 	 = 	Integer.parseInt(aux[2]);
			luminosidade = 	aux[3];
		}
		System.out.print("Dados: ");
		System.out.print("TipoDado("+tipoDado+"), ");
		System.out.print("Tempo("+tempo+"), ");
		System.out.print("Distancia("+distancia+"), ");
		System.out.print("Led("+luminosidade+"), ");
		System.out.println();
	}

	public String getTipoDado() {
		return tipoDado;
	}

	public void setTipoDado(String tipoDado) {
		this.tipoDado = tipoDado;
	}

	public int getTempo() {
		return tempo;
	}

	public void setTempo(int tempo) {
		this.tempo = tempo;
	}

	public int getDistancia() {
		return distancia;
	}

	public void setDistancia(int distancia) {
		this.distancia = distancia;
	}

	public String getLuminosidade() {
		return luminosidade;
	}

	public void setLuminosidade(String luminosidade) {
		this.luminosidade = luminosidade;
	}

	public String getLeituraComando() {
		return leituraComando;
	}

	public void setLeituraComando(String leituraComando) {
		this.leituraComando = leituraComando; // temos a string de dados
		this.interpretaComando(); // interpretamos a string
	}

	
}
