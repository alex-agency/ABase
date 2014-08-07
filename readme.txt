readme

__________ Network Setup __________________________________

base
- Generate a random baseNonce for the new network tree
- Create a new NetworkTree, and assign it as lastTree
- Send beacons and wait so every device can answer with beacon responses
send beacon to all devices (destMacAddr = 0)
- wait 2 sec
- Hopefully I have received all beacon responses, now I assign addresses
- now I wait a bit while devices are sending me command 0 layer4 packets
- wait 1 sec and retries 10 times last operation
- Wow, now we should have the network working!!
I set the tree we have generated as the activeTree
___________________________________________________________


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



