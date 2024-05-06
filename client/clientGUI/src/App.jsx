import { useContext, useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import {normalFetch} from './customAPIs.jsx'
import LoginScreen from './LoginScreen.jsx'
import { viewContext } from './viewContext.jsx'
import UserSignUp from './UserSignUp.jsx'
import MainPage from './MainPage.jsx'
import CreatingAccPage from './CreatingAccPage.jsx'
import { userNameContext } from './userNameContext.jsx'




function App() {
  
  const [view,setView] = useState(1);
  const [userName,setUserName] = useState(1);
  
  
  
  return (
    <userNameContext.Provider value={{userName,setUserName}} >
      <viewContext.Provider value={ {view, setView} }>
        {console.log("view is ",view)}
        
        {/* depending on the view value the appropriate component will be loaded */}

        {view==1 && <LoginScreen  passedViewContext={{view, setView}} passedUserNameContext={{userName,setUserName}}/>}
        {view==2 && <UserSignUp  passedViewContext={{view, setView}}/>}
        {view==3 && <MainPage  passedViewContext={{view, setView}}/>}
        {view==4 && <CreatingAccPage  passedViewContext={{view, setView}}/>}
        
      </viewContext.Provider>
    </userNameContext.Provider>
  )
}

export default App
