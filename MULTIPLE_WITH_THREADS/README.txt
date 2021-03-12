/* So now this program is waiting for incoming connections 
/* on port 8888. Dont close this program , keep it running.
/* Now a client can connect to it on this port. 
/* We shall use the telnet client for testing this. 
/* Open a terminal and type

$ telnet localhost 8888

/* On the terminal you shall get

Trying 127.0.0.1...
Connected to localhost.
Escape character is '^]'.
Connection closed by foreign host.

/* And the server output will show

bind done
Waiting for incoming connections...
Connection accepted

/* So we can see that the client connected to the server. 

