import NavMenu from "../components/NavMenu"
import VideoListing from "../components/VideoListing"

// import useEffect, useState
import { useEffect, useState } from "react";

function HomePage() {

    // state variable
    // initialize with empty array
    const [videosFromApi, setVideoFromApi] = useState([]);

    useEffect(() => {
        fetch("http://localhost:3000/videos")
            .then(
                (response) => {
                    return response.json()
                }
            )
            .then(
                (jsonData) => {
                    // save the api data to your state variable
                    setVideoFromApi(jsonData);
                }
            )
            .catch(
                (err) => { console.log(err) }
            )
    }, []);

    return (
        <div>
            <NavMenu />
            <VideoListing videos={videosFromApi} />
        </div>
    )
}

export default HomePage;