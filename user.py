#!/usr/bin/python
import socket , random , string , time
from threading import Thread

### Default socket setting
Local_IP = '127.0.0.1'
Registrar_PORT = 5060
Session_PORT = 5060
My_PORT = 60000 + random.randrange(5500)
proto = socket.getprotobyname('udp')
user_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
try:
	user_socket.bind((Local_IP,My_PORT))
	user_socket.connect((Local_IP,Registrar_PORT))
except socket.error as e:
	print(e)
	user_socket.close()
	exit()
BUFSIZ = 1024
user_id = input("Caller-id: ")
print("User_port %s" % My_PORT)

# Socket functions
def sendPacket(msg):
	try:
		user_socket.sendall(msg.encode())
	except socket.error as e:
		print(e)
		user_socket.close()  ### BYE Msg should also be sent if INVITE has started
		exit()
def recievePacket():
	try:
		msg = user_socket.recv(BUFSIZ).decode("utf8")
		print(msg)
		if msg == "quit":  ### TO be modified to BYE message
			user_socket.close()
			exit()
		return msg
	except socket.error as e:  # Possibly OpenSips server died.
		print(e)

### SIP Messages 
Inv = '''INVITE sip:%s@127.0.0.1 SIP/2.0
Via: SIP/2.0/UDP 127.0.0.1;branch=z9hG4bK%s
Max-Forwards: 70
To: <sip:%s@127.0.0.1>
From: <sip:%s@127.0.0.1>;tag=%s
Call-ID: %s@127.0.0.1
CSeq: 1 INVITE

%s
'''
Reg = '''REGISTER sip:127.0.0.1:5061 SIP/2.0
Via: SIP/2.0/UDP 127.0.0.1;branch=z9hG4bK%s
Max-Forwards: 70
To: <sip:%s@127.0.0.1>
From: <sip:%s@127.0.0.1>;tag=%s
Call-ID: %s@127.0.0.1
CSeq: 1800 REGISTER
Expires: 720029172917
Contact: <sip:%s@127.0.0.1>
Content-Length: 0
'''
Bye = '''BYE sip:%s@p127.0.0.1 SIP/2.0
Via: SIP/2.0/UDP 127.0.0.1;branch=z9hG4bK%s
Max-Forwards: 70
From: <sip:%s@127.0.0.1>;tag=%s
To: <sip:%s@127.0.0.1>;tag=%s
Call-ID: %s@127.0.0.1
CSeq: 230 BYE
Content-Length: 0
'''
Ack = '''ACK sip:%s@p127.0.0.1 SIP/2.0
Via: SIP/2.0/UDP 127.0.0.1;branch=z9hG4bK%s
Max-Forwards: 70
From: <sip:%s@127.0.0.1>;tag=%s
To: <sip:%s@127.0.0.1>;tag=%s
Call-ID: %s@127.0.0.1
CSeq: %s ACK
Content-Length: 0
'''
RandomChoice = string.ascii_letters+string.digits
def generateRand(d=10):
	return ''.join([random.choice(RandomChoice) for n in range(d)])
def generateRegister():
	return Reg % (generateRand(),user_id,user_id,generateRand(),generateRand(15),user_id)
def generateInvite(msg,to):
	return Inv % (to,generateRand(),to,user_id,generateRand(),generateRand(15),msg)
def generateBye(to,branch_id,call_id,to_tag,from_tag):
	return Bye % (to,branch_id,user_id,from_tag,to,to_tag,call_id)
def generateAck(to,branch_id,call_id,from_tag,cseq_id):
	return Ack % (to,branch_id,user_id,from_tag,to,generateRand(),call_id,cseq_id)
# Registration Process
# 1) REGISTER User-id -> Registrar
# 2) 200 OK Registrar -> User-id
message=generateRegister()
print(message)
sendPacket(message)
time.sleep(2)
recievePacket()
time.sleep(2)

# Messaging
  # Method 1:
	# 1) INVITE user-id -> SIP proxy 
	# 		INVITE SIP proxy -> Other user-id 
	#			200 OK Other user-id -> SIP proxy 
	# 2) 200 OK SIP proxy -> user-id
	# 3) Send normal ACK after finding route from message
	# 4) Normal messaging 
  # Method 2:
  	# 1) INVITE other-user-id -> SIP proxy
  	#		INVITE SIP proxy -> user-id
  	# 2) 200 OK user-id -> SIP proxy
  	#		200 OK SIP proxy -> other-user-id
  	# 3) Other user send normal ACK
  	# 4) Normal messaging
starter = input("Do you want to join or start? ")
if starter == 'start':
	other_user_id = input("Other Caller-id: ")
	message=generateInvite('lol',other_user_id)
	print(message)
	sendPacket(message)
	time.sleep(10)
	recievePacket()
	# Depending on recievePacket data start normal connection
else:
	recievePacket()
	# message=generateAck() # Param from recieved INVITE
	print(message)
	sendPacket(message)

### For Normal Messaging
# user_socket = socket(AF_INET, SOCK_DGRAM)
# def receive(): 
# 	"""Handles receiving of messages."""
# 	while True:
# 		try:
# 			msg = user_socket.recv(BUFSIZ).decode("utf8")
# 			print(msg)
# 			if msg == "quit":
# 				user_socket.close()
# 				exit()
# 		except OSError as e:  # Possibly other server died.
# 			print(e)
# 			break
# def send():
# 	"""Handles sending of messages."""
# 	msg = input(">>> ")
# 	user_socket.sendall(bytes(user_name+': '+msg,"utf8"))
# 	if msg == "quit":
# 		user_socket.close()
# 		exit()
# thread_send = threading.Thread(target = send)
# thread_send.start()
# thread_receive = threading.Thread(target = receive)
# thread_receive.start()