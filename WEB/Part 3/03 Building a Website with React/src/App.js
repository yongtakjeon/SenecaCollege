/* This application is built with the assumption that it will be tested with 'json-server' running on localhost port 3000.
The testing environment would run 'json-server' with 'db.json' from the root directory (same level as the package.json file). */

// Name: Yongtak Jun, Student ID: 137350195, Date: June/28/2021


import './App.css';

// page imports
import HomePage from "./pages/HomePage"
import VideoDetailsPage from "./pages/VideoDetailsPage"
import PlaylistPage from "./pages/PlaylistPage"


// imports for react router
import {
  BrowserRouter as Router,
  Switch,
  Route
} from "react-router-dom";


// imports useEffect, useState
import { useState } from "react";



function App() {

  // state variable
  // initialize with empty array
  const [myplaylist, setMyplaylist] = useState([]);


  const addToPlaylist = (video) => {

    // check if it is already saved video
    let alreadySaved = false;

    for (let i = 0; i < myplaylist.length; i++) {
      if (myplaylist[i].id === video.id) {
        alert("Already Saved!");
        alreadySaved = true;
      }
    }

    // if the video is not saved before, add it.
    if (!alreadySaved) {
      // 1. copy
      const copy = Array.from(myplaylist);

      // 2. update
      copy.push(video);

      // 3. update the state variable
      setMyplaylist(copy);

      alert("Saved!");
    }


  }

  return (
    <div>

      <Router>
        <Switch>

          <Route exact path="/">
            <HomePage />
          </Route>

          <Route exact path="/myplaylist">
            <PlaylistPage playlist={myplaylist} />
          </Route>

          <Route path="/:id">
            <VideoDetailsPage addToPlaylist={addToPlaylist} />
          </Route>

        </Switch>
      </Router>

    </div>
  );
}

export default App;
