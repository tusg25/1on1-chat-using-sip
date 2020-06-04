#!/usr/bin/python
import socket , random , string , time
from threading import Thread

### Default socket setting
Local_IP = '127.0.0.1'
Registrar_PORT = 5060
Session_PORT = 5060
user_id = input("Caller-id: ")
My_PORT = 60000 + int(input('Port pass between 1 to 5000? '))
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
		# print(msg)
		if msg == "quit":  ### TO be modified to BYE message
			user_socket.close()
			exit()
		return msg
	except socket.error as e:  # Possibly OpenSips server died.
		print(e)
		exit()

### SIP Messages 
Inv = '''INVITE sip:%s@127.0.0.1 SIP/2.0
Via: SIP/2.0/UDP 127.0.0.1;branch=z9hG4bK%s
Max-Forwards: 70
To: <sip:%s@127.0.0.1>
From: <sip:%s@127.0.0.1>;tag=%s
Call-ID: %s@127.0.0.1
CSeq: 1 INVITE
Content-Length: 0

'''
Reg = '''REGISTER sip:127.0.0.1 SIP/2.0
Via: SIP/2.0/UDP 127.0.0.1;branch=z9hG4bK%s
Max-Forwards: 70
To: <sip:%s@127.0.0.1>
From: <sip:%s@127.0.0.1>;tag=%s
Call-ID: %s@127.0.0.1
CSeq: 1826 REGISTER
Contact: <sip:%s@127.0.0.1>
Expires: 7200
Content-Length: 0

'''
Bye = '''BYE sip:%s@127.0.0.1 SIP/2.0
Via: SIP/2.0/UDP 127.0.0.1;branch=z9hG4bK%s
Max-Forwards: 70
From: <sip:%s@127.0.0.1>;tag=%s
To: <sip:%s@127.0.0.1>;tag=%s
Call-ID: %s@127.0.0.1
CSeq: 230 BYE
Content-Length: 0
'''
Ack = '''ACK sip:%s@127.0.0.1 SIP/2.0
%s
Max-Forwards: 70
To: <sip:%s@127.0.0.1>;tag=%s\r
%s
%s
%sACK
Content-Length: 0

'''
RandomChoice = string.ascii_letters+string.digits
def generateRand(d=10):
	return ''.join([random.choice(RandomChoice) for n in range(d)])
def generateRegister():
	return Reg % (generateRand(),user_id,user_id,generateRand(),generateRand(15),user_id)
def generateInvite(to):
	return Inv % (to,generateRand(),to,user_id,generateRand(),generateRand(15))
def generateBye(to,branch_id,call_id,to_tag,from_tag):
	return Bye % (to,branch_id,user_id,from_tag,to,to_tag,call_id)
def generateAck(msg):
	ls = msg.split('\n')
	def get(s):
		for r in ls:
			if r.split()[0] == s:
				# print(s + " in "+ r)
				return r
		print("%s not in msg" % s)
	via = get('Via:')
	frm  = get('From:')
	callid = get('Call-ID:')
	cseq = get('CSeq:')
	return Ack % (user_id,via,user_id,generateRand(),frm,callid,cseq[:-6])
def handleRegACK(msg):
	status = msg.split('\n')[0].split()[1]
	if status != '200':
		print("Registration failed")
		exit(1)
	else:
		print("Registration Successful")
def handleInvite(msg):
	ls = msg.split('\n')
	for r in ls:
		if 'rport' in r:
			port = r.split('=')[1].split(';')[0]
			# print(port)
			return port
	print("rport not found")
	exit(1)

# Registration Process
# 1) REGISTER User-id -> Registrar
# 2) 200 OK Registrar -> User-id
message=generateRegister()
# print(message)
sendPacket(message)
handleRegACK(recievePacket())

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
oport = 60000
print(starter)
if starter == 'start':
	other_user_id = input("Other Caller-id: ")
	message=generateInvite(other_user_id)
	# print(message)
	sendPacket(message)
	while True:
		message = recievePacket()
		if message.split('\n')[0].split()[0] == 'INVITE':
			break
	oport = handleInvite(message)
	# Depending on recievePacket data start normal connection
else:
	while True:
		message = recievePacket()
		if message.split('\n')[0].split()[0] == 'INVITE':
			break
	oport = handleInvite(message)
	#msg=generateAck(message) # Param from recieved INVITE
	#print(msg)
	#sendPacket(msg)
	other_user_id = message.split('\n')[6].split(':',2)[2].split('@')[0]
	# print(other_user_id)
	message=generateInvite(other_user_id)
	# print(message)
	sendPacket(message)
### For Normal Messaging
user_socket.close()
soc = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
try:
	soc.bind((Local_IP,My_PORT))
	soc.connect((Local_IP,int(oport)))
except socket.error as e:
	print(e)
	soc.close()
	exit(1)
def receive(): 
	"""Handles receiving of messages."""
	while True:
		try:
			msg = soc.recv(BUFSIZ).decode("utf8")
			print(msg,end="\n>>> ")
			if msg == "quit":
				soc.close()
				exit()
		except OSError as e:  # Possibly other server died.
			print(e)
			break
def send():
	"""Handles sending of messages."""
	while True:
		try:
			msg = input(">>> ")
			soc.sendall(bytes(user_id+': '+msg,"utf8"))
			if msg == "quit":
				soc.close()
				exit()
		except OSError as e:
			print(e)
			break
thread_send = Thread(target = send)
thread_send.start()
thread_receive = Thread(target = receive)
thread_receive.start()