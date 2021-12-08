import { Injectable } from '@angular/core';
import { HttpRequest, HttpHandler, HttpEvent, HttpInterceptor } from '@angular/common/http';
import { AuthService } from './auth.service';
import { Observable } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class InterceptTokenService implements HttpInterceptor {

  // Initialization
  constructor(private a: AuthService) { }

  // Methods
  intercept(request: HttpRequest<any>, next: HttpHandler): Observable<HttpEvent<any>> {

    // This will ensure that we only set the "JWT" authorization for requests going to our User API
    // and all requests going to spotify.com will continue to use the "Bearer" authorization.
    if (!request.url.includes("spotify.com")) {

      // Clone the existing request, and add the authorization header
      request = request.clone({
        setHeaders: {
          Authorization: `JWT ${this.a.getToken()}`
        }
      });

    }

    // Pass the request on to the next handler
    return next.handle(request);
  }

}
