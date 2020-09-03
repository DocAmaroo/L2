package Quincaillerie;

import java.util.HashMap;

public class PanierAchat {
	private HashMap<Piece, Integer> listArticle;
	
	public PanierAchat() {
		listArticle = new HashMap<Piece, Integer>();
	}
	
	public void add(Piece p) { //new elem
		listArticle.put(p, 1);
	}
	
	public void remove(Piece p) {
		listArticle.remove(p);
	}
	
	public boolean contient(Piece p) {
		return listArticle.containsKey(p);
	}
	
	public void up(Piece p) { //+1
		int tmp = listArticle.get(p);
		listArticle.put(p, tmp + 1);
	}
	
	public void down(Piece p) { //-1
		int tmp = listArticle.get(p);
		listArticle.put(p, tmp - 1);
	}
	
	public int quantite(Piece p) {
		return listArticle.get(p);
	}
	
	public void vider() {
		listArticle.clear();
	}
	
	public String toString() {
		String res = "";
		for(Piece p : listArticle.keySet()) {
			res += "----------------- ( quantité : "+ listArticle.get(p) +" ) -> " + p.toString();
		}
		return res;
	}
	
	public void info() {
		System.out.println(this.toString());
	}
	
	public int prix() {
		int res = 0;
		for(Piece p : listArticle.keySet()) {
			res += (p.getPrix() * listArticle.get(p));
		}
		return res;
	}
	
}