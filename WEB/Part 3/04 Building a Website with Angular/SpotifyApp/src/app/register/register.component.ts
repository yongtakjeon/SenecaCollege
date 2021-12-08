import { Component, OnInit } from '@angular/core';
import { NgForm } from '@angular/forms';
import { AuthService } from '../auth.service'
import { RegisterUser } from '../RegisterUser';

@Component({
  selector: 'app-register',
  templateUrl: './register.component.html',
  styleUrls: ['./register.component.css']
})
export class RegisterComponent implements OnInit {

  registerUser: RegisterUser = { userName: "", password: "", password2: "" };
  warning: string = null;
  success: boolean = false;
  loading: boolean = false;


  constructor(private auth:AuthService) { }

  ngOnInit(): void {
  }

  onSubmit(f: NgForm): void {
    if (this.registerUser.userName != "" && this.registerUser.password != "" && this.registerUser.password2 != "") {

      this.loading = true;
      
      this.auth.register(this.registerUser).subscribe(
        (successful) => {
          this.success = true;
          this.warning = null;
          this.loading = false;
        },
        (err) => {
          this.success = false;
          this.loading = false;
          this.warning = err.error.message;
        }
      );

    }
  }

}
