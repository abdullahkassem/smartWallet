# smartWallet

A smart wallet is an online wallet where you could deposit money into it and withdraw the money later, or you could do transactions to another smart wallet account. Like paypal.

## Assumptions and Notes:

The best option to store the data on the server, in this case would be a SQL database, but I could not get c++ mysql connector to work at all, so I serilized objects into JSON files to store them.

To transfer money from one account to the other (transactions), you need to know their accountID.

## external libriries
- ceral for serializing and deserializing objects