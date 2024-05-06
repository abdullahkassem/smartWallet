import React, { useContext } from 'react'
import { userNameContext } from './userNameContext'

function UserSignUp(props) {
  
  return (
    <div className='userSignUpContainer'>
      <h1>Enter your details</h1>

      <label htmlFor="fullName">Full Name</label>
      <input type="text" id="fullName" />

      <label htmlFor="nationalID">National ID</label>
      <input type="text" id="nationalID" />

      <label htmlFor="nationality">Nationality</label>
      <input type="text" id="nationality" />

      <label htmlFor="martialStatus">Maritial Status</label>
      <input type="text" id="martialStatus" />

      <label htmlFor="phoneNo">Phone Number</label>
      <input type="tel" id="phoneNo" />

      <label htmlFor="DOB">Date of Birth</label>
      <input type="date" id="DOB" />

      <button className='basicButton' >Submit</button>

    </div>
  )
}

export default UserSignUp