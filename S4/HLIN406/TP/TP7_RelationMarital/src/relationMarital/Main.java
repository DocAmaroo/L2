package relationMarital;

public class Main {
	
	public static void main(String[] args){
		Personne personne1 = new Personne("Canta", "Thomas", Genre.HOMME);
		Personne personne2 = new Personne("Desgenetez", "Charles", Genre.HOMME);
		Personne personne3 = new Personne("Bancillon", "Adrien", Genre.HOMME);
		Personne personne4 = new Personne("Gracia-Mouslis", "Kevin", Genre.HOMME);
		Personne personne5 = new Personne("Boudier", "Thibault", Genre.HOMME);
		Personne personne6 = new Personne("Marco", "Corentin", Genre.HOMME);
		
		Mariage mariage1 = new Mariage(2019,personne1, personne2, typeContrat.COMMUNAUTE,new Mairie("Montpellier", "Père David"));
		Mariage mariage2 = new Mariage(2006,personne3, personne4, typeContrat.AUTRE, new Mairie("Loin", "OnAOublié"));
		Pacs pacs1 = new Pacs(2015, personne5, personne6, new Tribunal("Bordeaux"));
		
		mariage1.add();
		System.out.println(mariage1.toString());
		mariage1.resiliation();
		mariage2.add();
		System.out.println(mariage1.toString());
		System.out.println(mariage2.toString());
		mariage2.resiliation();
		System.out.println(mariage2.toString());
		pacs1.add();
		System.out.println(pacs1.toString());
		pacs1.resiliation();
		System.out.println(pacs1.toString());
	}
	
}
