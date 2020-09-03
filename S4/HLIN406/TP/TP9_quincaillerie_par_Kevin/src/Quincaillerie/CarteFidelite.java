package Quincaillerie;

public class CarteFidelite {
	private int point;
	
	public CarteFidelite() {
		point = 0;
	}
	
	public int getPts() { return point; }
	
	public void addPts(int x) {
		int tmp = 0;
		while(x >= 5) {
			x -= 5;
			tmp++ ;
		}
		point = tmp;
	}
	
	public float retirerPts() {
		if(point >= 30) {
			point -= 30;
			return (float) 0.85;
		}else if(point >= 20) {
			point -= 20;
			return (float) 0.91;
		}else if(point >= 10){
			point -= 10;
			return (float) 0.96;
		}else{
			return (float)1;
		}
	}
	
}
