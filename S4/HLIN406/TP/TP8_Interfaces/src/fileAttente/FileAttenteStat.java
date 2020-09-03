package fileAttente;

public class FileAttenteStat extends FileAttente implements IFileAttenteStat {
	private int nbEntrees;
	private int nbSorties;
	
	public FileAttenteStat(){}
	
	public int nbEntrees() {
		return nbEntrees;
	}

	public int nbSorties() {
		return nbSorties;
	}
	
	public void entre(Personne p){
		super.entre(p);
		nbEntrees++;
	}
	
	public Personne sort(){
		nbSorties++;
		return super.sort();
	}
}
