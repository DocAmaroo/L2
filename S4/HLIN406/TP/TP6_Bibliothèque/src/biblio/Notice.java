package biblio;

import java.util.ArrayList;

public class Notice {
	private String ISBN;
	private String titre;
	private String soustitre;
	private Public cible;
	private ArrayList<Contribution> contributions;
	
	public Notice(String iSBN, String titre, String soustitre, Public cible) {
		ISBN = iSBN;
		this.titre = titre;
		this.soustitre = soustitre;
		this.cible = cible;
		this.contributions = new ArrayList<Contribution>();
	}
	public Notice(String iSBN, String titre, String soustitre, Public cible, ArrayList<Contribution> contributions) {
		ISBN = iSBN;
		this.titre = titre;
		this.soustitre = soustitre;
		this.cible = cible;
		this.contributions = contributions;
	}
	
	public void addContributions(Contribution c){
		contributions.add(c);
	}
	
	public String toString(){
		return "ISBN: " + ISBN + " |Titre: " + titre + " |Sous-titre: " + soustitre + " |Public ciblé: " + cible.name();
	}
	
}
