package fileAttente;

public class Personne implements Comparable<Personne>{
	private String nom;
	private String prenom;
	private int age;


	public Personne(String nom, String prenom, int age) {
		this.nom = nom;
		this.prenom = prenom;
		this.age = age;
	}

	public String getNom() {
		return nom;
	}
	

	public int getAge() {
		return age;
	}
	
	@Override
	public String toString() {
		return "nom = " + nom + ", prénom = " + prenom + ", age = " + age;
	}

	@Override
	public int compareTo(Personne p) {
		return nom.compareTo(p.getNom());
	}
	
}
