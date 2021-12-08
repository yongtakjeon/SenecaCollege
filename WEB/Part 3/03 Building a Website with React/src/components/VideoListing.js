import "./css/VideoListing.css"

import Video from "./Video"

function VideoListing(props) {
    return (
        <section className="listing-container">
            {
                props.videos.map((video) => {
                    return <div key={video.id}>
                        <Video
                            id = {video.id}
                            title={video.title}
                            author={video.author}
                            description={video.description}
                            views={video.views}
                            date_posted={video.date_posted}
                            profile_photo={video.profile_photo}
                            video_thumbnail={video.video_thumbnail}
                            link={video.link}
                            likes={video.likes}
                            dislikes={video.dislikes} />
                    </div>
                })
            }
        </section>
    )
}
export default VideoListing;
