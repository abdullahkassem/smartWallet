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
    db->store(temp);    //store updated user

    //create account obj 
    account* newAcc = new account(newAccID,accName,temp->get_userName(),accountType,0);

    //store in database
    db->store(newAcc);


    //if there is a starting balance it needs to be added as a transaction.
    if(startingBal>0){
        Deposit(newAccID,startingBal,"initial balance");
    }else if(startingBal<0){
        Deposit(newAccID,-startingBal,"initial balance");
    }

    return true;
}

/// @brief transfers money between 2 accounts and records transactions into the 2 accounts if possible.
/// @param SrcAccountID must exist, thus
/// @param DestAccountID could exist in database or not
/// @param amount 
/// @param transType 
/// @param details 
/// @return 
bool server::transferMoney(string SrcAccountID, string DestAccountID, double amount, string transType, string details="")
{
    
    // check if dest acc exists
    bool destFound = true;
    account* destAcc;
    try{
        destAcc = getAccount(DestAccountID);
    }catch(int x){
        destFound = false;
    }

    if(destFound){
        //make 2 transactions
        return (makeSingleTrans(SrcAccountID,DestAccountID,-amount,transType,details) &&
        makeSingleTrans(DestAccountID,SrcAccountID,amount,transType,"Sender Note: "+details) );
    }else{
        return makeSingleTrans(SrcAccountID,DestAccountID,amount,transType,details);
    }


    return true;
}

vector<string> server::getUserAccounts(string usrName)
{
    user*temp = getUser(usrName);
    return temp->accounts;
}

/// @brief helper function to create transacction and update srcAccount only
/// @param SrcAccountID 
/// @param DestAccountID 
/// @param amount amount will be added to balance
/// @param transType 
/// @param details 
/// @return 
bool server::makeSingleTrans(string SrcAccountID, string DestAccountID, double amount, string transType, string details=""){
    account* srcAcc;
    try{
        srcAcc = getAccount(SrcAccountID);
    }catch(int x){
        cerr << "Src Account does not exist\n";
        return false;
    }

    //create transaction obj and store it:

    string transID_1 = generateUniqueID();    
    transactions* trans1 = new transactions(transID_1,transType,amount,SrcAccountID,DestAccountID,details);
    db->store(trans1);

    //load account from db and then update account balance & add transaction to list in account:
    
    srcAcc->listOfTrans.push_back(transID_1);
    srcAcc->balance += amount;
    db->store(srcAcc);
    return true;
}


bool server::Deposit(string SrcAccountID, double amount, string details=""){
    if (amount <= 0)
        return false;
    return makeSingleTrans(SrcAccountID,"",amount,"deposit",details);
}

bool server::Withdraw(string SrcAccountID, double amount, string details=""){
    if (amount <= 0)
        return false;
    return makeSingleTrans(SrcAccountID,"",-amount,"withdraw",details);
}