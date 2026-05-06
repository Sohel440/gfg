import socket
import threading

# Server configuration
HOST = '127.0.0.1'  # localhost
PORT = 5555

# Function to handle client connections
def handle_client(client_socket, username):
    while True:
        try:
            message = client_socket.recv(1024).decode('utf-8')
            if message:
                print(f"{username}: {message}")
                # Broadcast the message to all clients
                broadcast(message, username)
        except:
            # Client has disconnected
            print(f"{username} has left the chat.")
            client_sockets.remove(client_socket)
            client_usernames.remove(username)
            broadcast(f"{username} has left the chat.", "Server")
            client_socket.close()
            break

# Function to broadcast messages to all clients
def broadcast(message, sender):
    for client_socket in client_sockets:
        if client_socket != server_socket:
            client_socket.send(bytes(f"{sender}: {message}", 'utf-8'))

# Main server logic
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind((HOST, PORT))
server_socket.listen()

print("Server is running...")

client_sockets = []
client_usernames = []

while True:
    client_socket, client_address = server_socket.accept()
    print(f"Connection from {client_address} has been established.")

    # Prompt the client for a username
    client_socket.send(bytes("Enter your username: ", 'utf-8'))
    username = client_socket.recv(1024).decode('utf-8')
    client_usernames.append(username)
    client_sockets.append(client_socket)

    # Broadcast new user joining
    broadcast(f"{username} has joined the chat.", "Server")

    # Start a new thread to handle client communication
    client_thread = threading.Thread(target=handle_client, args=(client_socket, username))
    client_thread.start()
