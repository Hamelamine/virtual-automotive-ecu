import socket

HOST = "127.0.0.1"
PORT = 5000

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

print("Connecting...")

client.connect((HOST, PORT))

print("Connected!")

try:
    while True:
        data = client.recv(1024)

        if not data:
            print("Server closed connection")
            break

        print("Received:", data.decode(), end="")

except KeyboardInterrupt:
    print("\nClosing client")

finally:
    client.close()