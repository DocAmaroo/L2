package tp7;

public class CVC {
	
	/**
	 * @param dateDeb
	 * @param dateFin
	 */
	
	public CVC(int dateDeb, int dateFin) {
		this.dateDeb = dateDeb;
		this.dateFin = dateFin;
	}
	
	public int getDateDeb() {
		return dateDeb;
	}
	public void setDateDeb(int dateDeb) {
		this.dateDeb = dateDeb;
	}
	public int getDateFin() {
		return dateFin;
	}
	public void setDateFin(int dateFin) {
		this.dateFin = dateFin;
	}

	protected int dateDeb;
	protected int dateFin;
	
}
