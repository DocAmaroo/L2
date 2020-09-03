package biblio;

public class Personne {
	private String nom;
	private String prenom;
	
	
	
	public Personne(String nom, String prenom) {
		super();
		this.nom = nom;
		this.prenom = prenom;
	}



	public String getName(){
		return nom + ":" + prenom;
	}
}
