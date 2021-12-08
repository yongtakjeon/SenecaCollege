import { Component, OnInit } from '@angular/core';
import { MusicDataService } from '../music-data.service';

@Component({
  selector: 'app-favourites',
  templateUrl: './favourites.component.html',
  styleUrls: ['./favourites.component.css']
})
export class FavouritesComponent implements OnInit {

  favourites: any;
  private livePostsSub: any; // subscription reference

  constructor(private data: MusicDataService) { }

  ngOnInit(): void {
    this.livePostsSub = this.data.getFavourites().subscribe(data => {this.favourites = data.tracks; console.log(data)});
  }

  ngOnDestroy(){
    this.livePostsSub.unsubscribe();
  }

  removeFromFavourites(id: any){
    this.data.removeFromFavourites(id).subscribe(data => this.favourites = data.tracks);
  }


}
