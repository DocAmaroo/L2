package relationMarital;

public class Pacs extends ContratVieCommune {

	public Tribunal tribunal;
	
	public Pacs(int dateDebut, Personne personne1, Personne personne2, Tribunal tribunal) {
		super(dateDebut, personne1, personne2);
		this.tribunal = tribunal;
	}

	
	@Override
	public String toString(){
		return "Pacs - " + super.toString()+"\nAu Tribunal de " + tribunal.getNom() + "\n";
	}
	

}
