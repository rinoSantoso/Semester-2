package game.packets;

import java.io.Serializable;

// Packet sent from the server to the user, contains the new currentPlayer (the change of turns), and the new state of the field
public class UpdatePacket implements Serializable{
	private static final long serialVersionUID = -4043686984608719773L;
	
	private int[][] fields;
	
	private int currentPlayer;

	public UpdatePacket(int[][] fields, int currentPlayer) {
		this.fields = fields;
		this.currentPlayer = currentPlayer;
	}

	public int[][] getFields() {
		return fields;
	}

	public int getCurrentPlayer() {
		return currentPlayer;
	}

	public void setCurrentPlayer(int currentPlayer) {
		this.currentPlayer = currentPlayer;
	}
	
	
}
