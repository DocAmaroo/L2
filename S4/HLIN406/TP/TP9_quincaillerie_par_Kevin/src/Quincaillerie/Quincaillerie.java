package Quincaillerie;

import java.util.ArrayList;

public class Quincaillerie {
	private String coordonee;
	private ArrayList<Piece> articleDispo;
	
	public Quincaillerie(String c) {
		coordonee = c;
		articleDispo = new ArrayList<Piece>();
	}
	
	public void add(Piece p) {
		articleDispo.add(p);
	}
	
	public String toString() {
		String res = "--------------------SHOP-----------------\n"+"Coordonee : " + coordonee + "\n";
		for(Piece p : articleDispo) {
			res += p.toString() + "\n";
		}
		res += "----------------------------------------\n";
		return res;
	}
	
	public void info() {
		System.out.println(this.toString());
	}
	
	public boolean vend(Piece p) {
		for(Piece x : articleDispo) {
			if(x.getReference().equals(p.getReference()))
				return true;
		}
		return false;
	}
}
