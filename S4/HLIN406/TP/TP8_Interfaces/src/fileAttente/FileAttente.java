package fileAttente;

import java.util.ArrayList;

public class FileAttente implements IFileAttente{
	private String nomFile;
	private static String reglementationFile = "sans priorite";
	private ArrayList<Personne> contenu;
	
	public ArrayList<Personne> getContenu() {
		return contenu;
	}

	public FileAttente(){
		contenu=new ArrayList<Personne>();
	}
	
	public void entre(Personne p){
		contenu.add(p);
	}
	
	public Personne sort(){
		Personne p=null;
		if (!contenu.isEmpty()){
			p=contenu.get(0);
			contenu.remove(0);
		}
		return p;
	}
	
	public boolean estVide(){
		return contenu.isEmpty();
	}
	
	public int taille(){
		return contenu.size();
	}
	
	public String toString(){
		return ""+descriptionContenu();
	}
	
	private String descriptionContenu(){
		String resultat = "";
		for (Personne p:this.contenu)resultat += p + " ";
		return resultat;
	}
	
	public void vider(){
		int taille = taille();
		for (int i=0; i<taille; i++)this.sort();
	}
	
	public Personne max(){
		if (estVide()){
			System.out.println("La liste est vide");
			return null;
		}
		Personne first = contenu.get(0);
		for (Personne e : contenu){
			if ( first.compareTo(e) > 0 ){
				first = e;
			}
		}

		return first;
		
	}
}
