import { Component, OnInit } from '@angular/core';
import { MatSnackBar } from '@angular/material/snack-bar';
import { ActivatedRoute } from '@angular/router';
import { MusicDataService } from '../music-data.service';

@Component({
  selector: 'app-album',
  templateUrl: './album.component.html',
  styleUrls: ['./album.component.css']
})
export class AlbumComponent implements OnInit {

  album: any;
  private livePostsSub: any; // subscription reference

  constructor(private snackBar: MatSnackBar, private route: ActivatedRoute, private data: MusicDataService) { }

  ngOnInit(): void {
    this.livePostsSub = this.data.getAlbumById(this.route.snapshot.params['id']).subscribe(data => this.album = data);
  }

  ngOnDestroy(){
    this.livePostsSub.unsubscribe();
  }

  addToFavourites(trackID: any){

    if(this.data.addToFavourites(trackID)){ // if it is successful


    }

    this.data.addToFavourites(trackID).subscribe(
      (successful) => {
      // Invoke the "open" method of the MatSnackBar Service to show a confirmation message to the user
      this.snackBar.open("Adding to Favourites...", "Done", { duration: 1500 });
      },
      (err) => {
        this.snackBar.open("Unable to add song to Favourites", "Error", { duration: 1500 });
      }
    );

  }

}
