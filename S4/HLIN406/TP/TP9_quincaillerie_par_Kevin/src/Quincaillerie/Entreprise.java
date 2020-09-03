package Quincaillerie;

public class Entreprise extends Client {
	private String siret;
	
	public Entreprise(String c, String a, String ad, String si) {
		super(c, a, ad);
		siret = si;
	}

	public String toString() {
		return super.toString() + "\n" +
				"Num Siret : " + siret;
	}
	
	public void info() {
		System.out.println(this.toString());
	}
}
