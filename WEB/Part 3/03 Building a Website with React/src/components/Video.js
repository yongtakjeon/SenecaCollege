import "./css/Video.css"
import {Link} from "react-router-dom"


function Video(props) {

    return (
        <div className="video-container">
            <img className="video-thumbnail" src={props.video_thumbnail} alt="thumnail of the video"/>
            <div className="video-details">
                <p className="name">
                    <Link to={props.id}>{props.title}</Link>
                </p>
                <p className="stats">{props.date_posted}</p>
                <p className="creator">
                    <img src={props.profile_photo} className="creator-profile-photo" alt="profile" />
                    <span>{props.author}</span>
                </p>
                <p className="desc">{props.description}</p>
            </div>
        </div>
    );
}
export default Video;