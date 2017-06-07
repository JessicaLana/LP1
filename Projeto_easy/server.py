import sys
import socket
import atexit
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('',85))
s.listen(10)
while 1:
    (csocket, address) = s.accept()
    while 1:
        data =  csocket.recv(1)
        print data
    
    s.close()
