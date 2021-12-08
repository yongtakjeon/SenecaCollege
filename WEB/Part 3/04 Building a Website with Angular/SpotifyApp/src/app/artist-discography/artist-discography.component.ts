import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { MusicDataService } from '../music-data.service';

@Component({
  selector: 'app-artist-discography',
  templateUrl: './artist-discography.component.html',
  styleUrls: ['./artist-discography.component.css']
})
export class ArtistDiscographyComponent implements OnInit {

  albums: any;
  artist: any;
  private livePostsSub1: any; // subscription reference
  private livePostsSub2: any;

  constructor(private route: ActivatedRoute, private data: MusicDataService) { }

  ngOnInit(): void {
    this.livePostsSub1 = this.data.getArtistById(this.route.snapshot.params['id']).subscribe(data => this.artist = data);
    this.livePostsSub2 = this.data.getAlbumsByArtistId(this.route.snapshot.params['id']).subscribe(data => this.albums = data.items.filter((element, index) => {
      return data.items.indexOf(element) == index;
    }));
  }

  ngOnDestroy(){
    this.livePostsSub1.unsubscribe();
    this.livePostsSub2.unsubscribe();
  }
}
