import "./css/NavMenu.css"
import { Link } from "react-router-dom"

function NavMenu() {
    return (
        <nav>
            <img src="./assets/logo.png" className="logo" alt="logo img" />
            <ul>
                <li><Link to="/">Home</Link></li>
                <li><Link to="/myplaylist">My Playlist</Link></li>
            </ul>
        </nav>
    )
}
export default NavMenu;
