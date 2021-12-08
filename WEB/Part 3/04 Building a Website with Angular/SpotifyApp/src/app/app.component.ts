/*********************************************************************************
*  WEB422 – Assignment 06
*  I declare that this assignment is my own work in accordance with Seneca  Academic Policy.  No part of this
*  assignment has been copied manually or electronically from any other source (including web sites) or 
*  distributed to other students.
* 
*  Name: Yongtak Jun, Student ID: 137350195, Date: August/12/2021
*
*  Online Link to Music App: https://priceless-murdock-3177db.netlify.app
*
*  Online Link to User Api: https://spotify-users-api.herokuapp.com/
*
********************************************************************************/ 


import { Component, OnInit } from '@angular/core';
import { Event, NavigationStart, Router } from '@angular/router';
import { AuthService } from './auth.service';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent implements OnInit {
  title = 'music-app';

  searchString: string;
  token: any;

  constructor(private router: Router, private auth: AuthService) { }
 
  ngOnInit() {
    this.router.events.subscribe((event: Event) => {
      if (event instanceof NavigationStart) { // only read the token on "NavigationStart"
        this.token = this.auth.readToken();
      }
    });
  }

  handleSearch() {
    //This function must programmatically navigate to the "/search" route with the "searchString" as its "q" query parameter.
    this.router.navigate(['/search'], { queryParams: { q: this.searchString } });

    // Additionally, this method should also clear the value of searchString by setting it to "". This will save the user 
    // from having to delete their previous query before making a 2nd search.
    this.searchString = "";

  }

  logout() {
    localStorage.clear();

    // redirect to the "login" route
    this.router.navigate(['/login']);
  }
}
