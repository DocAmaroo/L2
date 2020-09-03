package quincaillerie;

public class PieceCompositeMontees extends PieceComposite {
	
	private double dureeMontage;
	private double prixMontage;
	
	public PieceCompositeMontees(String nom, String reference, double dureeMontage, double prixMontage) {
		super(nom, reference);
		this.dureeMontage = dureeMontage;
		this.prixMontage = prixMontage;
	}

	public double getPrix(){
		return super.getPrix() + getPrixMontage();
	}
	
	public String getPrefixeReference(){
		return "02";
	}
	
	public double getGarantie(){
		return super.getGarantie() + 6;
	}
	
	public double getDureeFabrication(){
		return super.getDureeFabrication() + dureeMontage;
	}
	
	public double getDureeMontage() {
		return dureeMontage;
	}

	public double getPrixMontage() {
		return prixMontage;
	}
	
	@Override
	public String getInfos(){
		String res = "";
		res += "duree montage atelier : " + getDureeMontage() + "jour(s)\n";
		res += "prix du montage : " + getPrixMontage() +"euros";
		return res;
	}
}