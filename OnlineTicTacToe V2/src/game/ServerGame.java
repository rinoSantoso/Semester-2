package game;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

import game.packets.ClientPlayPacket;
import game.packets.GameEndPacket;
import game.packets.UpdatePacket;

// Server class that extends from the Game class
public class ServerGame extends Game{

	private ServerSocket serverSocket;
	private Socket socket;
	
	private Connection connection;
	
	// Initializes the player (server is player 1), sockets, and connection class that handles sending and receiving packets
	public ServerGame() {
		super(Game.PLAYER_ONE);
		try {
			serverSocket = new ServerSocket(Game.PORT);
			socket = serverSocket.accept();
			connection = new Connection(this, socket);
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
	
	// Input Method, if mouse is clicked at a certain point in the game window and it is currently player 1's turn, update the board based on which field is clicked
	@Override
	public void InputRecieved(int x, int y) {
		if(isMyTurn()) {
			updateField(x, y);
		}
	}

	
	// Method that decides what to do upon receiving an input packet
	@Override
	public void packetRecieved(Object object) {
		
		if(object instanceof ClientPlayPacket) {
			ClientPlayPacket packet = (ClientPlayPacket) object;
			
			updateField(packet.getX(), packet.getY());
		}
	}
	
	// Method to update the field, upon updating the field also sends a packet to the client to update the display on their side
	private void updateField(int x, int y) {
		if(fields[x][y] == Game.NOBODY) {
			fields[x][y] = currentPlayer;
			if(currentPlayer == Game.PLAYER_ONE) {
				currentPlayer = Game.PLAYER_TWO;
			}
			else if (currentPlayer == Game.PLAYER_TWO){
				currentPlayer = Game.PLAYER_ONE;
			}
			
			connection.sendPacket(new UpdatePacket(fields, currentPlayer));
			gameWindow.repaint();
			int winner = checkWin();
			
			// Checks for the current status of the game
			if (winner != Game.NOBODY) {
				endGame(winner);
			}else {
				int emptyCount = 0;
				for(int a = 0; a < 3; a++) {
					for(int b = 0; b < 3; b++) {
						if(fields[a][b] != Game.NOBODY) {
							emptyCount++;
						}
					}
				}
				if (emptyCount == 9) {
					endGame(winner);
				}
			}
		}
	}
	
	// Method to display the result of the game once it has ended
	private void endGame(int winner) {
		showWinner(winner);
		connection.sendPacket(new GameEndPacket(winner));
	}
	
	// Method to check the winner of the game or if the game is still ongoing
	private int checkWin() {
		for(int player = Game.PLAYER_ONE ; player <= Game.PLAYER_TWO; player++) {
			for(int y = 0; y < 3; y++) {
				int playerCount = 0;
				
				for (int x = 0; x < 3; x++) {
					if(fields[x][y] == player) {
						playerCount++;
					}
				}
				if (playerCount == 3) {
					return player;
				}
			}
			for(int x = 0; x < 3; x++) {
				int playerCount = 0;
				
				for (int y = 0; y < 3; y++) {
					if(fields[x][y] == player) {
						playerCount++;
					}
				}
				if (playerCount == 3) {
					return player;
				}
			}
			int playerCount = 0;
			for(int coordinate = 0; coordinate < 3; coordinate++) {
				if(fields[coordinate][coordinate] == player) {
					playerCount++;
				}
			}
			if(playerCount == 3) {
				return player;
			}
			
			playerCount = 0;
			for(int coordinate = 0; coordinate < 3; coordinate++) {
				if(fields[2 - coordinate][coordinate] == player) {
					playerCount++;
				}
			}
			if(playerCount == 3) {
				return player;
			}
		}
		return Game.NOBODY;
	}
	
	// Method on what to do when the window is closed (closes the connection and server socket)
	@Override
	public void close() {
		try {
			connection.close();
			serverSocket.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
