import React, { useContext } from 'react'
import { userNameContext } from './userNameContext'
import AccountButton from './AccountButton';

function MainPage(props) {
  const {userName,setUserName} = useContext(userNameContext);
  console.log("logged in username is", userName);

  let tempArr = ["account1","acc2"];

  const components = tempArr.map((e)=>{
    return <AccountButton key = {e} name={e}/>
  });

  return (
    <div className='mainPageContatiner'>
      <h2>Accounts</h2>
      {components }
      <div className="createAccButt basicButton">Create New Account</div>
    </div>
  )
}


export default MainPage
