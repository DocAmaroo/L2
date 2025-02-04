package quincaillerie;


public class Main {

	public static void main(String[] args) {
		
		/**
		 *  Declaration des pieces
		 *  String nom, String reference, double prix, double garantie, int dureeFabrication
		 */
		Piece pneu = new PieceBase("pneu", "4565", 10, 30, 4);
		Piece chambreAAir = new PieceBase("chambre a air", "7152", 5, 20, 2);
		Piece disqueDeJante = new PieceBase("disque de jante", "1214", 3, 26, 1);
		Piece rayon = new PieceBase("rayon", "4748", 2, 26, 1);
		
		/**
		 * Declaration des pieces composites en kit
		 * String nom, String reference
		 */
//		PieceCompositeKit janteKit = new PieceCompositeKit("jante", "4541");
//		PieceCompositeKit roueBrouetteEnKit = new PieceCompositeKit("roue de brouette en kit", "1512");

//		janteKit.ajouterPiece(disqueDeJante);
//		janteKit.ajouterPiece(rayon);
//		janteKit.ajouterPiece(rayon);
//		janteKit.ajouterPiece(rayon);
//		
//		roueBrouetteEnKit.ajouterPiece(pneu);
//		roueBrouetteEnKit.ajouterPiece(chambreAAir);
//		roueBrouetteEnKit.ajouterPiece(janteKit);
//		System.out.println(roueBrouetteEnKit);
		
		
		/**
		 * Declaration des pieces composites montees
		 * String nom, String reference, double dureeMontage, double prixMontage
		 */
		PieceCompositeMontees janteMontee = new PieceCompositeMontees("jante", "4541", 0, 0);
		PieceCompositeMontees roueBrouetteMontee = new PieceCompositeMontees("roue de brouette montee", "1512", 1, 15);
		
		janteMontee.ajouterPiece(chambreAAir);
		janteMontee.ajouterPiece(rayon);
		janteMontee.ajouterPiece(rayon);
		janteMontee.ajouterPiece(rayon);

		roueBrouetteMontee.ajouterPiece(pneu);
		roueBrouetteMontee.ajouterPiece(chambreAAir);
		roueBrouetteMontee.ajouterPiece(janteMontee);
		
		System.out.println(roueBrouetteMontee);
	}

}
