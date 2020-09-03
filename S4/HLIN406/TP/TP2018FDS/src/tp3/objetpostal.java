package tp3;


public abstract class objetpostal {
	
	/**
	 * @param origine
	 * @param destination
	 * @param codePostal
	 * @param poids
	 * @param volume
	 * @param txRecommandation
	 */
	public objetpostal(String origine, String destination, int codePostal, int poids, float volume,
			Recommandation txRecommandation) {
		this.origine = origine;
		this.destination = destination;
		this.codePostal = codePostal;
		this.poids = poids;
		this.volume = volume;
		this.txRecommandation = txRecommandation;
	}
	

	private String origine;
	private String destination;
	private int codePostal;
	private int poids;
	private float volume;
	public Recommandation txRecommandation;
	public abstract float tarifRemboursement();
	public abstract float getTarifBase();
	
	public float tarifAffranchissement(){
		float TB = getTarifBase();
		if(txRecommandation==Recommandation.zero){
			return TB;
		}
		else if (txRecommandation==Recommandation.un){
			return TB + 0.5f;
		}
		else{
			return TB + 1.5f;
		}
	}
	
	public float getVolume(){
		return volume;
	}
	public abstract String getType();
	public String chaineDescriptive(){
		String result = getType();
		result+=" / " + codePostal; 
		result+= " / " + destination;
		result+= " / " + txRecommandation;
		return result;
	}
	

}

