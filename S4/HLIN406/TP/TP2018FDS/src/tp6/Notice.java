package tp6;

import java.util.ArrayList;

public class Notice {
	private ArrayList<Exemplaire> listeExemplaires = new ArrayList<> ();
	private String isbn;
	private String titre;
	private String sstitre;
	private Public rated;
	
	

	public Notice(String iden, String nom, String ssnom, Public r) {
		isbn = iden;
		titre = nom;
		sstitre = ssnom;
		rated = r;
	}
	
	public String getTitre(){
		return titre;
	}
	public String getIden(){
		return isbn;
	}
	public Public getPegi(){
		return rated;
	}
	public Exemplaire chercher(){
		
		for(int i=0; i<listeExemplaires.size(); i++){
			if(listeExemplaires.get(i).getDisponible())
			{
				return listeExemplaires.get(i);
			}
		}
		return null;
	}
	

	
}
