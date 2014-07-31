readme

__________ create network __________________________________

base
- create tree
- send beacon to all devices (destMacAddr = 0)

client
- client recieved in processIncomingPacket method with type = 0x02
	save network bounce, interface and src address as temprorary base
	create new own nounce
- resend this beacon to all as broadcast (dest = 0)
- also send its nounce as BEACON_CHILD_RESPONSE_TYPE (0x03) to temprorary base

base
- base received packet beaconChildResponse in the onFrameReceived method
- verify src address with nounce from packet in the verifyHmac method
- added client to tree in the onBeaconChildResponse method

_________ send to base ________________________________________



