import React, { useContext, useState } from 'react'
import { viewContext } from './viewContext';
import { loginAPI, normalFetch } from './customAPIs';
// import LoginInput from './LoginInput'

export default function LoginScreen(props) {

    const {userName,setUserName} = props.passedUserNameContext;
    const {view, setView} = props.passedViewContext;

    const [name, setName] = useState('');
    const [pass, setPass] = useState('');
    

    const handleChangeName = (event)=>{
        setName(event.target.value)
    }

    const handleChangePass = (event)=>{
        setPass(event.target.value)
    }

    const handleSignUp = (event)=>{
        if(name == ''){
            console.log("Name is empty")
            const n = document.querySelector("#userNameLogin")
            n.style["border-color"] = "red";
        }

        if(pass == ''){
            console.log("Pass is empty")
            const n = document.querySelector("#passwrdLogin")
            n.style["border-color"] = "red";
        }

        if (name == '' || pass == '')
            {
    
            }else{
                console.log("will create user with login credientials enterd: ",name," " ,pass);
                // send api to server
                // wait for response
                // if true, then change view
                // else say wrong password
                setUserName(name);
                setView(2);
                
                
            }
    }

    const handleLogin = (event)=> {
        //check if values are empty
        if(name == ''){
            console.log("Name is empty")
            const n = document.querySelector("#userNameLogin")
            n.style["border-color"] = "red";
        }

        if(pass == ''){
            console.log("Pass is empty")
            const n = document.querySelector("#passwrdLogin")
            n.style["border-color"] = "red";
        }

        if (name == '' || pass == '')
        {

        }else{
            console.log("will authenticate username and password with server: ",name," " ,pass);
            // send api to server
            loginAPI(name,pass).then(response => response.text())
            .then(data => {
                console.log(data); // The response body as text
                if (data == "login true" ){
                    console.log("logged in successfully");
                    setUserName(name);
                    setView(3);
                }else{
                    console.log("password or username are incorrect");
                }
            })
            .catch(error => {
            console.error(error);
            }); 

            
        }

    }

  return (
    // <form action={"http://localhost:"+props.port+"/"} className="loginContainer" method="get">
    <form className="loginContainer">
        <p>Enter you login credientials if you have an account and press login, or press signup to create new account. </p>
        
        <label htmlFor="userNameLogin" >UserName</label>
        <input id="userNameLogin" type="text" onChange={handleChangeName}/>

        <label htmlFor="passwrdLogin" >Password</label>
        <input id="passwrdLogin" type="password" onChange={handleChangePass}/>
        

        <button type="button" onClick={handleLogin}>login</button>
        <button type="button" onClick={handleSignUp}>signup</button>
    </form>
    
  )
}

