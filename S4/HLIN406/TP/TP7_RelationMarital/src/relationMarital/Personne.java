package relationMarital;

import java.util.ArrayList;

public class Personne {
	private String nom;
	private String prenom;
	private Genre genre;
	private ArrayList<ContratVieCommune> listContrats = new ArrayList<ContratVieCommune>();
	
	public ArrayList<ContratVieCommune> getListContrats() {
		return listContrats;
	}

	public Personne(String nom, String prenom, Genre genre) {
		this.nom = nom;
		this.prenom = prenom;
		this.genre = genre;
	}
	
	public void ajoutContrat(ContratVieCommune contrat){
		listContrats.add(contrat);
	}

	public boolean estEnCouple(){
		return ( listContrats.get(listContrats.size()-1).getDateFin() == -1) ;
	}
	
	public Personne estAvec(){
		if (estEnCouple()) {
			ContratVieCommune dernierContrat = listContrats.get(listContrats.size()-1);
			if ( this == dernierContrat.getPersonne1() ){
				return dernierContrat.getPersonne2();
			}
			else{
				return dernierContrat.getPersonne1();
			}
		}
		System.out.print("Cette personne n'est pas en couple");
		return null;
	}

	@Override
	public String toString() {
		return "nom = " + nom + ", prénom = " + prenom + ", genre = " + genre;
	}
	

}
