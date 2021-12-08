import "./css/PlaylistPage.css"

import NavMenu from "../components/NavMenu"
import VideoListing from "../components/VideoListing"


function PlaylistPage(props) {

    return (
        <div className="Playlist">

            <NavMenu />
            <h1>My Playlist</h1>

            {
                (props.playlist.length > 0) ?
                    <VideoListing videos={props.playlist} />
                    :
                    <p>You don't have any videos in your playlist.</p>
            }

        </div>
    )
}
export default PlaylistPage;