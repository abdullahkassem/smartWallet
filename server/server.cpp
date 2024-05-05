#include "server.h"

string server::generateUniqueID() {
    boost::uuids::random_generator gen;
    boost::uuids::uuid id = gen();
    return boost::uuids::to_string(id);
}

server::server(/* args */)
{
    db = database::getInstance();
}

server::~server()
{
}

//create a new user
void server::createUser(string usrName, string Password)    
{
    //first check if userName already exists
    bool nameExists = true;
    try
    {
        db->loadUser(usrName);
    }
    catch(int exp)
    {
        //this means that we could not open file, thus name does not exist.
        nameExists = false;
    }

    if(nameExists){
        cerr<<"Name already exists\n";
        return;
    }
    // create a new user object
    user* temp = new user(usrName,Password);

    // store in database
    db->store(temp);
    
    
}
// loads and returns user, must catch this function
user* server::getUser(string usrName){   
    
    user* curUser;
    try{
        curUser = new user(db->loadUser(usrName));
    }catch(int x){
        throw x;
    }
    
    return curUser;
  
}

account* server::getAccount(string accName){
    account* curAccount;
    try{
        curAccount = new account(db->loadAccount(accName));
    }catch(int x){
        throw x;
    }
    return curAccount;
}

transactions* server::getTransaction(string transName){
    transactions* curTransaction;
    try{
        curTransaction = new transactions(db->loadTransaction(transName));
    }catch(int x){
        throw x;
    }
    return curTransaction;
}

// returns true if login is successful 
bool server::login(string usrName, string Password)
{
    //first check if userName already exists
    bool nameExists = true;
    user curUser; 
    try
    {
        curUser = db->loadUser(usrName);
    }
    catch(int exp)
    {
        //this means that we could not open file, thus name does not exist.
        nameExists = false;
    }
    
    if(!nameExists){
        // cout << "User Name does not exist\n";
        return false;
    }

    if(Password != curUser.password){
        // cout << "passwords mismatch\n";
        return false;
    }

    return true;
}


/// @brief creates a new account
/// @param usrName 
/// @param accountType 
/// @param startingBal 
/// @return true if successful
bool server::createAccount(string usrName, string accName,string accountType, double startingBal)
{
    string newAccID = generateUniqueID();
    //The chance that the account is duplicated is very low, so I will assume its unique for simplicity

    //add accID to corresponding user's list 
    user* temp;
    try{
        temp = getUser(usrName);
    }
    catch(int x){
        return false;
    }
    
    temp->accounts.push_back(newAccID);
    db->store(temp);

    //create account obj 
    account* newAcc = new account(newAccID,accName,temp->get_userName(),accountType,startingBal);

    //store in database
    db->store(newAcc);

    return true;
}

/// @brief creates a transaction between 2 accounts and stores them in accounts if possible.
/// @param SrcAccountID must exist, thus
/// @param DestAccountID could exist in database or not
/// @param amount 
/// @param transType 
/// @param details 
/// @return 
bool server::createTrans(string SrcAccountID, string DestAccountID, double amount, string transType, string details)
{
    return false;
}
