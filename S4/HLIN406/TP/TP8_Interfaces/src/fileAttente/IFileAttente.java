package fileAttente;

public interface IFileAttente {
	public abstract void entre(Personne p);
	public abstract Personne sort();
	public abstract boolean estVide();
	public abstract int taille();
	public abstract void vider();
}
