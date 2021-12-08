import { HttpClient } from '@angular/common/http';
import { Observable } from 'rxjs';
import { Injectable } from '@angular/core';
import { SpotifyTokenService } from './spotify-token.service';
import { mergeMap } from 'rxjs/operators';
import { environment } from './../environments/environment';

@Injectable({
  providedIn: 'root'
})
export class MusicDataService {

  constructor(private spotifyToken: SpotifyTokenService, private http: HttpClient) { }

  getNewReleases(): Observable<SpotifyApi.ListOfNewReleasesResponse> {

    // For the inner "get" request to be successful, it must provide an "Authentication" header consisting of the value
    // "Bearer token", where token is first obtained by invoking the getBearerToken() method of the
    // SpotifyTokenService.
    // NOTE: This is true for any requests to api.spotify.com in our application.

    return this.spotifyToken.getBearerToken().pipe(mergeMap(token => {
      return this.http.get<SpotifyApi.ListOfNewReleasesResponse>("https://api.spotify.com/v1/browse/new-releases", { headers: { "Authorization": `Bearer ${token}` } });
    }));
  }

  getArtistById(id: any): Observable<SpotifyApi.SingleArtistResponse> {
    return this.spotifyToken.getBearerToken().pipe(mergeMap(token => {
      return this.http.get<SpotifyApi.SingleArtistResponse>(`https://api.spotify.com/v1/artists/${id}`, { headers: { "Authorization": `Bearer ${token}` } });
    }));
  }

  getAlbumsByArtistId(id: any): Observable<SpotifyApi.ArtistsAlbumsResponse> {
    return this.spotifyToken.getBearerToken().pipe(mergeMap(token => {
      return this.http.get<SpotifyApi.ArtistsAlbumsResponse>(`https://api.spotify.com/v1/artists/${id}/albums?include_groups=album,single&limit=50`, { headers: { "Authorization": `Bearer ${token}` } });
    }));
  }

  getAlbumById(id: any): Observable<SpotifyApi.SingleAlbumResponse> {
    return this.spotifyToken.getBearerToken().pipe(mergeMap(token => {
      return this.http.get<SpotifyApi.SingleAlbumResponse>(`https://api.spotify.com/v1/albums/${id}`, { headers: { "Authorization": `Bearer ${token}` } });
    }));
  }

  searchArtists(searchString: any): Observable<SpotifyApi.ArtistSearchResponse> {
    return this.spotifyToken.getBearerToken().pipe(mergeMap(token => {
      return this.http.get<SpotifyApi.ArtistSearchResponse>(`https://api.spotify.com/v1/search?q=${searchString}&type=artist&limit=50`, { headers: { "Authorization": `Bearer ${token}` } });
    }));
  }

  addToFavourites(id): Observable<[String]> {
    // make a PUT request to environment.userAPIBase/favourites/:id to add id to favourites
    return this.http.put<[String]>(`${environment.userAPIBase}/favourites/${id}`, {});
  }

  removeFromFavourites(id): Observable<SpotifyApi.MultipleTracksResponse> {
    return this.http.delete<[String]>(`${environment.userAPIBase}/favourites/${id}`).pipe(mergeMap(favouritesArray => {

      if (favouritesArray.length > 0) {
        let favouritesListItems = favouritesArray.join();
  
        return this.spotifyToken.getBearerToken().pipe(mergeMap(token => {
          return this.http.get<SpotifyApi.MultipleTracksResponse>(`https://api.spotify.com/v1/tracks?ids=${favouritesListItems}`, { headers: { "Authorization": `Bearer ${token}` } });
        }));
      }
      
      // if the length of the favouritesList array property is less than or equal to 0
      return new Observable<SpotifyApi.MultipleTracksResponse>(o=>o.next({tracks: []}));

    }));
  }
  
  getFavourites(): Observable<SpotifyApi.MultipleTracksResponse> {
    return this.http.get<[String]>(`${environment.userAPIBase}/favourites/`).pipe(mergeMap(favouritesArray => {

      if (favouritesArray.length > 0) {
        let favouritesListItems = favouritesArray.join();
  
        return this.spotifyToken.getBearerToken().pipe(mergeMap(token => {
          return this.http.get<SpotifyApi.MultipleTracksResponse>(`https://api.spotify.com/v1/tracks?ids=${favouritesListItems}`, { headers: { "Authorization": `Bearer ${token}` } });
        }));
      }
      
      // if the length of the favouritesList array property is less than or equal to 0
      return new Observable<SpotifyApi.MultipleTracksResponse>(o=>o.next({tracks: []}));
      
    }));
  }

}