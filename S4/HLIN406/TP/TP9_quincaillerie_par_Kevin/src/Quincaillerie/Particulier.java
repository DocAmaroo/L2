package Quincaillerie;

public class Particulier extends Client {
	private String nom;
	private Civilite civilite;
	private Sexe sexe;

	public Particulier(String c, String a, String ad, String n, Civilite civ, Sexe sex) {
		super(c, a, ad);
		nom = n;
		civilite = civ;
		sexe = sex;
	}
	
	public String toString() {
		return super.toString() + "\n" +
				"Nom : " + nom + "\n" +
				"Civilite : " + civilite + "\n" +
				"Sexe : " + sexe + "\n" +
				"-------------------------------------------\n";
	}
	
	public void info() {
		System.out.println(this.toString());
	}
}
