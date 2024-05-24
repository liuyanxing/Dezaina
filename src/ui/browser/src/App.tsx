import React, { useEffect } from 'react';
import './App.css';
import { RouterProvider } from 'react-router-dom';

import { router } from "./router";
import { isLoginOrRedirect, registerErrorCallback } from "./api";


function registerHttpErrorCallbacks() {
  registerErrorCallback(401, () => {
    if (window.location.pathname !== "/login") {
      window.location.href = "/login";
    }
  })  
}


function initApp() {
  registerHttpErrorCallbacks();
}

function App() {
  useEffect(() => {
    initApp();
    isLoginOrRedirect();
  }, []);
  return (
    <div className="App">
      <RouterProvider router={router} />
    </div>
  );
}

export default App;
