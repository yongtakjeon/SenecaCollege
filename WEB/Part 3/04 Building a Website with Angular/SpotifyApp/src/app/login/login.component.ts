import { Component, OnInit } from '@angular/core';
import { NgForm } from '@angular/forms';
import { Router } from '@angular/router';
import { AuthService } from '../auth.service';
import { User } from '../User';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})
export class LoginComponent implements OnInit {

  user: User = { userName: "", password: "", _id: null };
  warning: string = null;
  loading: boolean = false;


  constructor(private auth: AuthService, private router: Router) { }

  ngOnInit(): void {
  }

  onSubmit(f: NgForm): void {
    if (this.user.userName != "" && this.user.password != "") {

      this.loading = true;

      this.auth.login(this.user).subscribe(
        (success) => {
          this.loading = false;

          // store the returned token in local storage as 'access_token'
          localStorage.setItem('access_token', success.token);
          // redirect to the "newReleases" route
          this.router.navigate(['/newReleases']);

        },
        (err) => {
          this.loading = false;
          this.warning = err.error.message;
        }
      );

    }
  }

}
