// import css
import "./css/VideoDetailsPage.css"

// import for navMenu
import NavMenu from "../components/NavMenu"

// import icons
import { GoThumbsdown, GoThumbsup } from "react-icons/go";

// import useEffect, useState
import { useEffect, useState } from "react";

// import for using params
import { useParams } from "react-router-dom"

function VideoDetailsPage(props) {

    let { id } = useParams();

    const [videoFromApi, setVideoFromApi] = useState("");

    //state variables for number of likes and dislikes
    const [numOfLikes, setNumOfLikes] = useState(videoFromApi.likes);
    const [numOfDislikes, setNumOfDislikes] = useState(videoFromApi.dislikes);

    useEffect(() => {
        fetch(`http://localhost:3000/videos/${id}`)
            .then(
                (response) => {
                    return response.json()
                }
            )
            .then(
                (jsonData) => {
                    // save the api data to your state variable
                    setVideoFromApi(jsonData);
                    setNumOfLikes(jsonData.likes);
                    setNumOfDislikes(jsonData.dislikes);
                }
            )
            .catch(
                (err) => { console.log(err) }
            )
    }, [id]);

    const likePressed = () => {

        //increse the number of likes if it is NOT increaed before
        var elementLikes = document.getElementById('likes');
        var elementDislikes = document.getElementById('dislikes');

        if(!(elementLikes.classList.contains('pressed'))){
            setNumOfLikes(numOfLikes + 1);
        }

        //if number of dislikes is already increased, decrease it
        if(elementDislikes.classList.contains('pressed')){
            setNumOfDislikes(numOfDislikes - 1);
        }

        //add 'pressed' class to <li> tag
        elementLikes.classList.add('pressed');
        elementDislikes.classList.remove('pressed');


    }

    const dislikePressed = () => {
        //increse teh number of dislikes if it is NOT increaed before
        var elementLikes = document.getElementById('likes');
        var elementDislikes = document.getElementById('dislikes');

        if(!(elementDislikes.classList.contains('pressed'))){
            setNumOfDislikes(numOfDislikes + 1);
        }

        //if number of likes is already increased, decrease it
        if(elementLikes.classList.contains('pressed')){
            setNumOfLikes(numOfLikes - 1);
        }

        //add 'pressed' class to <li> tag
        elementLikes.classList.remove('pressed');
        elementDislikes.classList.add('pressed');
        
    }
    
    return(
        <div>        
            <NavMenu />

            <section className="video-player-container">
                <iframe width="800" height="450" src={`https://www.youtube.com/embed/${id}`} title="YouTube video player" frameBorder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowFullScreen></iframe>
                <p className="title">{videoFromApi.title}</p>
                <div className="stats">
                    <p>
                        <span>{videoFromApi.views}</span>
                        &nbsp;&bull;&nbsp;
                        <span>{videoFromApi.date_posted}</span>
                    </p>
                    <ul className="links">
                        <li id="likes" onClick={likePressed}>
                            <GoThumbsup/>
                            &nbsp;&nbsp;
                            <span>{numOfLikes}</span>
                        </li>
                        <li id="dislikes" onClick={dislikePressed}>
                            <GoThumbsdown/>
                            &nbsp;&nbsp;                            
                            <span>{numOfDislikes}</span>
                        </li>
                    </ul>
                </div>
                <div className="video-details">
                    <div>
                        <p className="creator">
                            <img src={videoFromApi.profile_photo} className="creator-profile-photo" alt="profile"/>
                            <span>{videoFromApi.author}</span>                    
                        </p>   
                        <p className="desc">{videoFromApi.description}</p>
                    </div>
                    <div className="col-right">
                        <button className="btn btn-secondary" onClick={ () => { props.addToPlaylist(videoFromApi) } }>                            
                            ADD TO PLAYLIST
                        </button>                
                    </div>
                </div>                        
            </section>
        </div>
    )
}
export default VideoDetailsPage;