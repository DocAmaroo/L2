package tp3;

public class lettre extends objetpostal {
	/**
	 * @param origine
	 * @param destination
	 * @param codePostal
	 * @param poids
	 * @param volume
	 * @param txRecommandation
	 * @param urgente
	 */
	
	public lettre(String origine, String destination, int codePostal, int poids, float volume,
			Recommandation txRecommandation, boolean urgente) {
		super(origine, destination, codePostal, poids, volume, txRecommandation);
		this.urgente = urgente;
	}


	private float TarifBase=0.5f;
	public float getTarifBase(){
		return TarifBase;
	}
	
	private boolean urgente;
	public float tarifAffranchissement(){
		float result=super.tarifAffranchissement();
		if(urgente){
			result+=0.30f;
		}
		return result;
	}
	
	public float tarifRemboursement(){
		if(txRecommandation==Recommandation.zero){
			return 0;
		}
		else if (txRecommandation==Recommandation.un){
			return 1.5f;
		}
		else{
			return 15;
		}
	}
	
	public String getType(){
		return type;
	}
	
	private final static String type="Lettre";
	public String chaineDescriptive(){
		String result=super.chaineDescriptive();
		result+=" / " + urgente;
		return result;
	}
	
	public static void main (String[] args){
		Recommandation tx = Recommandation.un;
		lettre mamie = new lettre("France", "Italie", 34270, 10,0.02f,tx,true);
		String res = mamie.chaineDescriptive();
		System.out.println(res);
		
	}
	
	
}
