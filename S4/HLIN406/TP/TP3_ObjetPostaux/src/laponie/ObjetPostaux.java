package laponie;

public abstract class ObjetPostaux {

	
	private String origine;
	private String destination;
	private int codePostal;
	protected double poids;
	protected double volume;
	protected TauxR tauxR;
	
	public ObjetPostaux(String origine, String destination, int codePostal, double poids, double volume, TauxR tauxR) {
		this.origine = origine;
		this.destination = destination;
		this.codePostal = codePostal;
		this.poids = poids;
		this.volume = volume;
		this.tauxR = tauxR;
	}
	
	public double getPoids() {
		return poids;
	}

	public double getVolume() {
		return volume;
	}

	public TauxR getTauxR() {
		return tauxR;
	}

	public String getTypeName(){
		return "Objet Postal";
	}
	
	public String descriptionObjet(){
		
		String chaine = "";
		chaine += ("Origine du colis : " + origine + "\n");
		chaine += ("Destination : " + destination + "\n");
		chaine += ("Code Postal : " + codePostal + "\n");
		chaine += ("Poids : " + poids + "\n");
		chaine += ("Volume : " + volume + "\n");
		chaine += ("Taux de Recommandation : " + tauxRtoIntOutput() + "\n");
		return chaine;
	}
	
	public String tauxRtoIntOutput(){
		
		String res = "";
		switch (tauxR) {
			case zero:
				res = "0";
				break;
	
			case un:
				res = "1";
				break;
			case deux:
				res = "2";
				break;
				
			default:
				res = "0";
				break;
		}
		
		return res;
	}
	
	@Override 
	public String toString() {
		return getTypeName() + " [ codePostal = " + codePostal + " / destination = " + destination + " / Taux Recommandation = " + tauxRtoIntOutput();
	}

	public abstract double tarifRemboursement();
}
