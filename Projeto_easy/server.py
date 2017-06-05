import socket 
import sys
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('',12345))
s.listen(10)
while 1:
    (conn, addr) = s.accept()
    while 1:
        print conn.recv(1)
    
s.close()
