package tp6;

public class Personne {

	private String nom;
	private String prenom;
	private int age;
	
	public Personne(String m, String p, int a) {
	nom=m;
	prenom=p;
	age=a;
	}
	
	public String getNom(){
		return nom;
	}
	public String getPrenom(){
		return prenom;
	}
	public int getAge(){
		return age;
	}

}
