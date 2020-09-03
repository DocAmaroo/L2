package promotion;

public enum Mention {
	RIEN(0, 12, "Vous êtes moyen."),
	ASSEZ_BIEN(12, 14, "C'est assez bien, en fait c'est une mention pour te faire plaisir."),
	BIEN(14, 16, "Cela devient sympathique, tu as la mention bien !"),
	TRES_BIEN(16, 20, "EXCELLENT !! BRAVO LOL !");

	private double noteMin, noteMax;
	private String phrase;

	Mention(int noteMin, int noteMax, String phrase) {
		this.noteMin = noteMin;
		this.noteMax = noteMax;
		this.phrase = phrase;
	}

	public String getPhrase() { return phrase; }

	public static Mention calculerMention(double note) {
		for(Mention m : Mention.values()) {
			if(note >= m.noteMin && note < m.noteMax) return m;
		}
		return Mention.RIEN;
	}
}