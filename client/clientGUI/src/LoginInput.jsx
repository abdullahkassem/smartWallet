import React from 'react'

function LoginInput({name,Itype="text"}) {
    
  return (
    <div className='loginInput'>
        <label htmlFor={name} >{name}</label>
        <input id={name} type={Itype} />
    </div>
  )
}



export default LoginInput