package game;

import java.io.IOException;
import java.net.Socket;

import game.packets.ClientPlayPacket;
import game.packets.GameEndPacket;
import game.packets.UpdatePacket;

// Client class that extends from the Game class
public class ClientGame extends Game{

	private Socket socket;
	
	private Connection connection;
	
	// Constructor, initializes the player (client is player 2), socket connecting to the IP and port of the server, and connection class
	public ClientGame() {
		super(Game.PLAYER_TWO);
		try {
			socket = new Socket("localhost", Game.PORT);
			connection = new Connection(this, socket);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	// Method that sends a packet to the server upon a valid mouse click
	@Override
	public void InputRecieved(int x, int y) {
		if(isMyTurn()) {
			connection.sendPacket(new ClientPlayPacket(x, y));
		}
	}
	
	// Method that decides what to do upon receiving a packet
	@Override
	public void packetRecieved(Object object) {
		
		if(object instanceof UpdatePacket) {
			UpdatePacket packet = (UpdatePacket) object;
			
			fields = packet.getFields();
			currentPlayer = packet.getCurrentPlayer();
		}
		
		else if(object instanceof GameEndPacket) {
			GameEndPacket packet = (GameEndPacket) object;
			showWinner(packet.getWinner());
		}
		
		gameWindow.repaint();
	}
	
	// Method to close
	@Override
	public void close() {
		try {
			connection.close();
			socket.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	

}
