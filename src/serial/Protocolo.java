package serial;

public class Protocolo {

	private String tipoDado;
	private String tempo;
	private String distancia;
	private String luminosidade;
	
	private String leituraComando;
	
	public Protocolo() {
		// TODO Auto-generated constructor stub
	}

	private void interpretaComando() {
		//$STS,s1200,2,100
		String aux[] = leituraComando.split(",");
		if(aux.length == 4) {
			aux[0]= tipoDado;
			aux[1]= tempo;
			aux[2]= distancia;
			aux[3]= luminosidade;
		}
	}
	
	public String getTipoDado() {
		return tipoDado;
	}

	public void setTipoDado(String tipoDado) {
		this.tipoDado = tipoDado;
	}

	public String getTempo() {
		return tempo;
	}

	public void setTempo(String tempo) {
		this.tempo = tempo;
	}

	public String getDistancia() {
		return distancia;
	}

	public void setDistancia(String distancia) {
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
