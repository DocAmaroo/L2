package quincaillerie;

public class PieceCompositeKit extends PieceComposite {
	
	public PieceCompositeKit(String nom, String reference) {
		super(nom, reference);
	}

	public String getPrefixeReference(){
		return "01";
	}
	
	@Override
	public String getInfos(){
		return "duree montage particulier : " + super.getDureeFabrication() + "min";
	}
}
