import { Component, OnInit } from '@angular/core';
import { ActivatedRoute, Router } from '@angular/router';
import { MusicDataService } from '../music-data.service';

@Component({
  selector: 'app-search-results',
  templateUrl: './search-results.component.html',
  styleUrls: ['./search-results.component.css']
})
export class SearchResultsComponent implements OnInit {

  results: any;
  searchQuery: any;
  private livePostsSub: any; // subscription reference


  constructor(private route: ActivatedRoute, private data: MusicDataService, private router: Router) {
    
    // this is for routerLink on same component when only queryParameter changes
    this.router.routeReuseStrategy.shouldReuseRoute = function () {
      return false;
    };
  }

  ngOnInit(): void {
    this.searchQuery = this.route.snapshot.queryParams['q'];
    console.log("haha");

    this.livePostsSub = this.data.searchArtists(this.searchQuery).subscribe(data => this.results = data.artists.items.filter(element =>
      element.images.length > 0
    ));
    
  }

  ngOnDestroy(){
    this.livePostsSub.unsubscribe();
  }

}
