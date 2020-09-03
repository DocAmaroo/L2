package tp3;

public class colis extends objetpostal {

	public colis(String origine, String destination, int codePostal, int poids, float volume,
			Recommandation txRecommandation) {
		super(origine, destination, codePostal, poids, volume, txRecommandation);
	}
	
	public String declContenu;
	private float valeurDeclare=20;

	
	private float TarifBase=2;
	public float getTarifBase() {
		return TarifBase;
	}
	
	public String getType(){
		return type;
	}
	
	
	public float tarifRemboursement(){
		if(txRecommandation==Recommandation.zero){
			return 0;
		}
		else if (txRecommandation==Recommandation.un){
			return 0.1f*valeurDeclare;
		}
		else{
			return 0*5f*valeurDeclare;
		}
	}
	
	private final static String type="Colis";
	public String chaineDescriptive(){
		String result = super.chaineDescriptive();
		result+= " / " + getVolume();
		result+= " / " + valeurDeclare;
		return result;
	}
	
	public static void main (String[] args){
		Recommandation tx = Recommandation.un;
		colis mamie = new colis("France", "Italie", 34270, 10,0.02f,tx);
		String res = mamie.chaineDescriptive();
		System.out.println(res);
		
	}
	
}
