package biblio;

import java.util.ArrayList;

public class Contributeur extends Personne {
	private ArrayList<Contribution> contributions;
	

	
	public void addContribution(Contribution c){
		contributions.add(c);
	}
	
	public Contributeur(String nom, String prenom) {
		super(nom, prenom);
		this.contributions = new ArrayList<Contribution>();
	}

	public Contributeur(String nom, String prenom, ArrayList<Contribution> contributions) {
		super(nom, prenom);
		this.contributions = contributions;
	}

	public String toString(){
		return "Contributeur: " + getName();
	}
}
