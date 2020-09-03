package tp4;

import java.util.ArrayList;

public class promotion {
	
	private ArrayList<etudiant> list;
	private int annee;
	
	/**
	 * @param list
	 * @param annee
	 */
	public promotion(int annee) {
		this.annee = annee;
		list = new ArrayList<>();
	}
	
	public promotion() {
		list = new ArrayList<>();
	}
	
	public ArrayList<etudiant> getList() {
		return list;
	}
	
	public void setList(ArrayList<etudiant> list) {
		this.list = list;
	}
	
	public int getAnnee() {
		return annee;
	}
	
	public void setAnnee(int annee) {
		this.annee = annee;
	}

	public etudiant getEtu(int n){
		return list.get(n);
	}
	
	public int nombEtu(){
		return list.size();
	}
	
	public void inscrire(etudiant e){
		list.add(e);
	}
	
	public float moyenneGeneral(){
		float res = 0;
		for(int i=0;i<nombEtu();i++){
			res+=this.getEtu(i).moyenne();
		}
		return res/nombEtu();
	}
	
	public void AfficheResultats(){
		for(int i=0;i<nombEtu();i++){
			System.out.println(this.getEtu(i).ligneResultats());
		}
	}
	
	public etudiant recherche (String nom){
		for(int i=0;i<nombEtu();i++){
			if(nom==this.getEtu(i).getNom()){
				return getEtu(i);
			}
		}
		return null;
	}
	
	public ArrayList<etudiant> admis(){
		
		ArrayList<etudiant> adm = new ArrayList<>();
		for(int i=0; i<nombEtu(); i++){
			if(this.getEtu(i).moyenne()>=10){
				adm.add(getEtu(i));
			}
		}
		return adm;
	}
	
	public ArrayList <etudiant> nouveauxInscritsNonFrancophones(){
		ArrayList<etudiant> ninf = new ArrayList<>();
		for(int i=0;i<nombEtu();i++){
			if (this.getEtu(i).getCodePays() == TypePays.nonfrancophone && this.getEtu(i).getCodeIns() == TypeInscription.Reinscription ){
				ninf.add(getEtu(i));
			}
		}
		return ninf;
	}
	
	public ArrayList<etudiant> majors(){
		double notemax = 0;
		ArrayList<etudiant> maj = new ArrayList<>();
		for(int i=0;i<nombEtu()-1;i++){
			if (this.getEtu(i).moyenne() <= this.getEtu(i+1).moyenne()){
				notemax = this.getEtu(i+1).moyenne();
			}
		}
		System.out.println(notemax);
		for(int j=0;j<nombEtu();j++){
			if(this.getEtu(j).moyenne()==notemax){
				maj.add(this.getEtu(j));
			}
		}
		return maj;
	}
	
	public static void main(String[] args){
		double[] TabNote={10.02,3.0,16.0};
		double[] TabNote2={20.0,20.0,20.0};
		double[] TabNote3={20.0,20.0,19.9};
		double[] TabNote4={5.0,3.0,6.0};
		etudiant Zoltan = new etudiant("Zoltan", 38, 1998  ,TypeInscription.Reinscription, TypePays.nonfrancophone, TabNote);
		etudiant Zoltan2 = new etudiant("Zoltan2", 92, 1905  ,TypeInscription.premiereInscription	, TypePays.nonfrancophone, TabNote2);
		etudiant Zoltan3 = new etudiant("Zoltan3", 38, 1998  ,TypeInscription.Reinscription, TypePays.francophone, TabNote3);
		etudiant Zoltan4 = new etudiant("Zoltan4", 38, 1998  ,TypeInscription.premiereInscription, TypePays.français, TabNote4);
		
		promotion lesabrutis = new promotion(2018);
		lesabrutis.inscrire(Zoltan);
		lesabrutis.inscrire(Zoltan2);
		lesabrutis.inscrire(Zoltan3);
		lesabrutis.inscrire(Zoltan4);
		System.out.println(lesabrutis.nombEtu());
		System.out.println(lesabrutis.moyenneGeneral());
		lesabrutis.AfficheResultats();
		System.out.println(lesabrutis.majors().get(0).ligneResultats());
		
	}
}
