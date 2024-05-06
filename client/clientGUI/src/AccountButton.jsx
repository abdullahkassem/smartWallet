import React from 'react'

function AccountButton(props) {
  
    const handleClick = () =>{
        console.log("account ",props.name,"pressed")
    }
  
    return (
    <div className='accountButton basicButton' onClick={handleClick}>
        {props.name}
    </div>
  )
}


export default AccountButton
