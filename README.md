# smartWallet

A smart wallet is an online wallet where you could deposit money into it and withdraw the money later, or you could do transactions to another smart wallet account. Like paypal.

## How to run
### Server
cd /smartWallet/server
To run just use ./myprogram
use make file to complie and run


### Client 
cd smartWallet/client/clientGUI
then use "npm run dev" and then open the localhost address given in the terminal.
Make sure the same ports are used for both.

## Assumptions and Notes:

The best option to store the data on the server, in this case would be a SQL database, but I could not get c++ mysql connector to work at all, so I serilized objects into JSON files to store them.

To transfer money from one account to the other (transactions), you need to know their accountID.

## Current Progress:

- Basically all that remains is to replicate the login API to all other API and display resutls properly on UI, and implement the remaining UI.

### Server:
- The server is able to do all the required functionalites on its side, like storing users, creating accounts etc. (Working and Tested)
- Communication works between server and client. Server recieves get requests and parses them and reads params and is able to send messages to client successfully.
- The remaining part is: call the appropriate server function for the correspoinding request.

### Client:
- The client GUI is not complete and not styled
- Only the interface for logging in and signing up has been created
- Right now the only working request sent to server is when logging in to verify if account and password are correct.
- Thus logging in is the only working feature.


## external libriries
- ceral for serializing and deserializing objects
- https://netmindms.github.io/urlparser/