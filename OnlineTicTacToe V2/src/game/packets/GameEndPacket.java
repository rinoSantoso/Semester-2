package game.packets;

import java.io.Serializable;

// Packet sent from the server to the client, indicating that the game has ended. Also contains an information on who wins the game
public class GameEndPacket implements Serializable{
	
	private static final long serialVersionUID = -8187076632965484159L;
	private int winner;

	public GameEndPacket(int winner) {
		this.winner = winner;
	}

	public int getWinner() {
		return winner;
	}

}
