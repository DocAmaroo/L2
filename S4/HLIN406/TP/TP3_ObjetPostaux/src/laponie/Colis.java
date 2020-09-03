package laponie;

public class Colis extends ObjetPostaux {

	private double valeur;
	private String contenu;
	private final int tarifBase=2;
	
	public double getValeur() {
		return valeur;
	}

	public String getContenu() {
		return contenu;
	}

	public int getTarifBase() {
		return tarifBase;
	}

	public void setValeur(double valeur) {
		this.valeur = valeur;
	}

	public void setContenu(String contenu) {
		this.contenu = contenu;
	}

	public Colis(String origine, String destination, int codePostal, double poids, double volume, TauxR tauxR, double valeur, String contenu) {
		super(origine, destination, codePostal, poids, volume, tauxR);
		this.valeur = valeur;
		this.contenu = contenu;
	}
	
	public double tauxAffranchissement(){
		
		double res = (getTarifBase() + ((tauxR == TauxR.un) ? 0.5 : (tauxR == TauxR.deux) ? 1.5 : 0));
		res += (getVolume() > (1/8))? 3 : 0;
		return res;
	}
	
	public double tarifRemboursement(){
		
		double val = getValeur();
		double res = ( (tauxR == TauxR.un) ? (val - (val*0.90)) : ( (tauxR == TauxR.deux) ? (val - (val*0.5)) : 0));
		return res;
	}
	
	public String getTypeName(){
		return "Colis";
	}
	
	@Override
	public String toString(){
		return super.toString() + " / Volume = " + getVolume() + "/ Valeur = " + valeur + " ]";
	}
	
}
