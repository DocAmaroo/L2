package laponie;

import java.time.LocalDate;

public class ColisExpress extends Colis {

	protected LocalDate dateEnvoi;
	protected final int tarifAffranchissement = 30;
	protected boolean emballage;
	protected static int numeroSuivant;
	protected String numeroSuivis;
	
	public ColisExpress(String origine, String destination, int codePostal, double poids, double volume, TauxR tauxR, double valeur, String contenu, boolean emballage) {
		
		super(origine, destination, codePostal, poids, volume, tauxR, valeur, contenu);
		
		this.dateEnvoi = LocalDate.now();
		this.emballage = emballage;
		this.numeroSuivis = "CX48R23" + numeroSuivant + "W8A3RE4";
		numeroSuivant +=1;
	}
	
	
	public int getTarifAffranchissement() {
		return tarifAffranchissement;
	}


	public boolean isEmballage() {
		return emballage;
	}

	public String getNumeroSuivis() {
		return numeroSuivis;
	}

	public boolean verifPoids(){
		return poids < 30;
	}
	
	public int Emballage(){
		int tarif = getTarifAffranchissement();
		return ( isEmballage()? tarif+3 : tarif);
	}
	
	public LocalDate getDateEnvoi() {
		return dateEnvoi;
	}
	
	public String getTypeName(){
		return "Colis Express";
	}
	
	@Override
	public String toString(){
		if (verifPoids()){
			return super.toString() + " / Poids = " + poids + " / Numéro de colis = " + getNumeroSuivis() + " ]";
		}
		else
			return "[ ERROR ] > Votre colis pèse : " + poids + "kg, le poids maximum est 30kg";
		
	}

}
