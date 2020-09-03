package relationMarital;

public class Mariage extends ContratVieCommune {
	
	public typeContrat type;
	public Mairie mairie;
	
	/**
	 * @param dateDebut
	 * @param personne1
	 * @param personne2
	 * @param type
	 * @param nomMairie
	 */
	public Mariage(int dateDebut, Personne personne1, Personne personne2, typeContrat type, Mairie mairie) {
		super(dateDebut, personne1, personne2);
		this.type = type;
		this.mairie = mairie;
	}
	
	
	public typeContrat getType() {
		return type;
	}

	@Override
	public String toString(){
		return "Mariage " + getType() + " - " + super.toString() +"\nA la Mairie de " + mairie.getNom() + ", célébrer par " + mairie.getNomACelebrer() + "\n";
	}
	
}
