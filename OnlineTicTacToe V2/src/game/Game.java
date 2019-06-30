package game;

import javax.swing.JOptionPane;

import game.gui.GameWindow;
import game.gui.Window;

// Base class for both instances of the game, Server and Client
public abstract class Game { 
	
	public static final int PORT = 22222;
	
	public static final int WIDTH = 600, HEIGHT = 600;
	public static final int FIELD_WIDTH = WIDTH/3, FIELD_HEIGHT = HEIGHT / 3;
	
	public static final int NOBODY = 0, PLAYER_ONE = 1, PLAYER_TWO = 2;
	protected int[][] fields;
	
	private Window window;
	protected GameWindow gameWindow;
	
	protected int currentPlayer;
	
	protected int thisPlayer;
	
	// Constructor, initializes the window frame, the gameWindow panel inside the window, and field size (3 x 3 board)
	public Game(int thisPlayer) {
		this.thisPlayer = thisPlayer;
		window = new Window(this, "Networked TicTacToe", WIDTH, HEIGHT);
		gameWindow = new GameWindow(this);
		fields = new int[3][3];
		window.add(gameWindow);
		window.setVisible(true);
		currentPlayer = Game.PLAYER_ONE;
	}
	
	// Method to show the result of the game once it has ended
	protected void showWinner(int winner) {
		if(winner == Game.NOBODY) {
			JOptionPane.showMessageDialog(null, "TIE!");
		}else {
			JOptionPane.showMessageDialog(null, "Player " + winner + " has won the game!");
		}
	}
	
	// Method to check if its the player's turn
	protected boolean isMyTurn() {
		if(thisPlayer == currentPlayer){
			return true;
		}
		return false;
	}
	
	// Abstract method to decide what to do when an input is received
	public abstract void InputRecieved(int x, int y);
	// Abstract method to decide what to do when an info packet is received
	public abstract void packetRecieved(Object object);
	// Abstract method to decide what to do when the window closes
	public abstract void close ();
	
	// Method to get the state of the board
	public int[][] getFields(){
		return fields;
	}
}
