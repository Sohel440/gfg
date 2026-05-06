import socket
import threading

# Client configuration
HOST = '127.0.0.1'  # localhost
PORT = 5555

# Function to receive messages from the server
def receive_messages():
    while True:
        try:
            message = client_socket.recv(1024).decode('utf-8')
            print(message)
        except:
            # An error occurred, likely the server has closed the connection
            print("Connection to server lost.")
            break

# Main client logic
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((HOST, PORT))

# Get username from user
username = input("Enter your username: ")
client_socket.send(bytes(username, 'utf-8'))

# Start a thread to receive messages from the server
receive_thread = threading.Thread(target=receive_messages)
receive_thread.start()

# Main loop to send messages to the server
while True:
    message = input()
    client_socket.send(bytes(message, 'utf-8'))
