package laponie;

public class Lettre extends ObjetPostaux{

	private boolean urgente;
	private final double tarifBase=0.5;
	
	public double getTarifBase() {
		return tarifBase;
	}

	public Lettre(String origine, String destination, int codePostal, double poids, double volume, TauxR tauxR, boolean urgente) {
		super(origine, destination, codePostal, poids, volume, tauxR);
		
		this.urgente = urgente;
	}

	
	public double tauxAffranchissement(){
		
		double res = getTarifBase();
		res += ( (tauxR == TauxR.un) ? 0.5 : ( (tauxR == TauxR.deux) ? 1.5 : ( (urgente)? 0.3 : 0)));
		return res;
		
	}
	
	public double tarifRemboursement(){
		
		double res = ( (tauxR == TauxR.un) ? 1.5 : ( (tauxR == TauxR.deux) ? 15 : 0));
		return res;
	}
	
	public String getTypeName(){
		return "Lettre";
	}
	
	@Override
	public String toString(){
		return super.toString() + " / " + ((urgente)? "urgente" : "ordinaire") + " ]";
	}
	
}
