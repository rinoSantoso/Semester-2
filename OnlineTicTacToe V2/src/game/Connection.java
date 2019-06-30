package game;

import java.io.EOFException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.net.SocketException;

// Class that handles sending and receiving data, implements runnable as it always listens for any received packet while running
public class Connection implements Runnable{
	private ObjectOutputStream outputStream;
	private ObjectInputStream inputStream;
	
	private boolean running;
	
	private Game game;
	
	// Constructor, initializes the input and output stream
	public Connection(Game game, Socket socket) {
		this.game = game;
		
		try {
			outputStream = new ObjectOutputStream(socket.getOutputStream());
			inputStream = new ObjectInputStream(socket.getInputStream());
		} catch (IOException e) {
			e.printStackTrace();
		}
		new Thread (this).start();
	}
	
	// Method used when waiting for an input, constantly checks for a packet to be received
	@Override
	public void run() {
		running = true;
		while(running) {
			try {
				Object object = inputStream.readObject();
				game.packetRecieved(object);
				
			} catch (EOFException | SocketException e) {
				 running = false;
				 
			}catch (ClassNotFoundException | IOException e) {
				e.printStackTrace();
			}
		}
		
	}
	
	// Method to send a packet, resets the previous object upon sending a new instance of the packet
	public void sendPacket(Object object) {
		try {
			outputStream.reset();
			outputStream.writeObject(object);
			outputStream.flush();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	// Method to close	
	public void close() throws IOException {
		running = false;
		inputStream.close();
		outputStream.close();
	}
}
