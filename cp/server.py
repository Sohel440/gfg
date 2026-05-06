import socket               # Import socket module

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)         # Create a socket object
host = '127.0.0.1' # Get local machine name
port = 5000                # Reserve a port for your service.
s.bind((host, port))        # Bind to the port

s.listen(5)                 # Now wait for client connection.
print (s)
print ('server is ready')
while True:
   c, addr = s.accept()     # Establish connection with client.
   print ('Got connection from', addr)
   c.send(('Thank you for connecting').encode('utf-8'))
   c.close()                # Close the connection
   break
s.close()