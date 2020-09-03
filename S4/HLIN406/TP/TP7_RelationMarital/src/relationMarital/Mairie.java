package relationMarital;

public class Mairie{
	
	public String nom;
	public String nomACelebrer;
	
	public Mairie(String nom, String nomACelebrer){
		this.nom = nom;
		this.nomACelebrer = nomACelebrer;
	}
	
	public String getNom() {
		return nom;
	}
	public String getNomACelebrer() {
		return nomACelebrer;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	public void setNomACelebrer(String nomACelebrer) {
		this.nomACelebrer = nomACelebrer;
	}
}
