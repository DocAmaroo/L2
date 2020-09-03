package tp2;

public class etudiant {
	
	private String nom;
	private int age;
	private int datedenaissance;
	private TypeInscription codeIns;
	private TypePays codePays;
	private double[] notes;
	
	/**
	 * @param nom
	 * @param age
	 * @param datedenaissance
	 * @param codeIns
	 * @param codePays
	 * @param notes
	 */
	public etudiant(String nom, int age, int datedenaissance, TypeInscription codeIns, TypePays codePays, double[] notes) {
		this.nom = nom;
		this.age = age;
		this.datedenaissance = datedenaissance;
		this.codeIns = codeIns;
		this.codePays = codePays;
		this.notes = notes;
	}
	
	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public int getDatedenaissance() {
		return datedenaissance;
	}

	public void setDatedenaissance(int datedenaissance) {
		this.datedenaissance = datedenaissance;
	}

	public TypeInscription getCodeIns() {
		return codeIns;
	}

	public void setCodeIns(TypeInscription codeIns) {
		this.codeIns = codeIns;
	}

	public TypePays getCodePays() {
		return codePays;
	}

	public void setCodePays(TypePays codePays) {
		this.codePays = codePays;
	}

	public double[] getNotes() {
		return notes;
	}

	public void setNotes(double[] notes) {
		this.notes = notes;
	}


	public double moyenne(){
		double res;
		res=(notes[0] + notes[1] + notes[2]);
		return res/3;
	}
	
	public String mention(){
		double m = this.moyenne();
		if (m>=0){
			return "Ajourn√©";
		}
		else 
			return "Admis";
	}
	
	public String ligneRÈsultats(String nom, double moyenne, String mention, double[] note){
		String ligne = (nom + " a obtenu la moyenne " + moyenne + " (" + mention + ")");
		if (moyenne<10) {
			for(int i=0; i<3; i++){
				if (notes[i] >=10){
					ligne += " Tu as eu la moyenne au module " +i;
				}
			}
		}
		return ligne;
	}

	public static void main(String[] args){
		double[] TabNote={10.02,3.0,16.0};
		etudiant Zoltan = new etudiant("Zoltan", 38, 1998  ,TypeInscription.Reinscription, TypePays.nonfrancophone, TabNote);
		double MoyenneDeZoltan = Zoltan.moyenne();
		String MentionDeZoltan = Zoltan.mention();
		String res = Zoltan.ligneRÈsultats("Zoltan", MoyenneDeZoltan, MentionDeZoltan, TabNote);
		System.out.println(res);
	}
}



