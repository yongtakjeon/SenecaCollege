public class Student {
	private String firstName;
	private String lastName;
	private double grade;
	private String department;

	Student(String firstName, String lastName, double grade, String department){

		if(firstName != null) {
			this.firstName = firstName;
		}
		if(lastName != null) {
			this.lastName = lastName;
		}
		if(grade >= 0) {
			this.grade = grade;
		}
		if(department != null) {
			this.department = department;
		}
	}

	//setters
	void setFirstName(String firstName) {
		if(firstName != null) {
			this.firstName = firstName;
		}
	}

	void setLastName(String lastName) {
		if(lastName != null) {
			this.lastName = lastName;
		}
	}
	
	void setGrade(double grade) {
		if(grade >= 0) {
			this.grade = grade;
		}
	}
	
	void setDepartment(String department) {
		if(department != null) {
			this.department = department;
		}
	}
	
	//getters
	String getFirstName() {
		return firstName;
	}
	
	String getLastName() {
		return lastName;
	}
	
	String getName() {
		return firstName +' '+lastName;
	}
	
	double getGrade() {
		return grade;
	}
	
	String getDepartment() {
		return department;
	}

	@Override
	public String toString() {
		return String.format("%-8s %-15s %-7.2f %s", firstName, lastName, grade, department);
	}
	
	@Override
	public boolean equals(Object obj) {
		//if 'this' and 'obj' are pointing to same object.
		if(this == obj) {
			return true;
		}
		
		if(obj == null) {
			return false;
		}
		
		if(getClass() != obj.getClass()) {
			return false;
		}
		
		Student other = (Student) obj; //downcasting
		
		// comparing firstName
		if (firstName == null) {
			if(other.firstName != null) {
				return false;
			}
		}
		else if(!firstName.equals(other.firstName)) {
			return false;
		}
		
		// comparing lastName
		if (lastName == null) {
			if(other.lastName != null) {
				return false;
			}
		}
		else if(!lastName.equals(other.lastName)) {
			return false;
		}
		
		// comparing grade
		if(grade != other.grade) {
			return false;
		}
		
		// comparing department
		if (department == null) {
			if(other.department != null) {
				return false;
			}
		}
		else if(!department.equals(other.department)) {
			return false;
		}
		
		return true;
	}
	
}
