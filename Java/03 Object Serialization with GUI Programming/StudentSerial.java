// Name: Yongtak Jun
// Date: July/05/2021

import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

import java.awt.FlowLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JOptionPane;
import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JTextArea;
import javax.swing.JLabel;
import javax.swing.JButton;



public class StudentSerial extends JFrame {

	//declare ArrayList of Student type for assigning multiple Students
	ArrayList<Student> students = new ArrayList<Student>();

	private final JTextField stdIDT;
	private final JTextField firstNameT;
	private final JTextField lastNameT;
	private final JTextArea coursesT;

	private final JLabel stdIDL;
	private final JLabel firstNameL;
	private final JLabel lastNameL;
	private final JLabel coursesL;

	private final JButton saveButton;
	private final JButton exit;

	public StudentSerial() {

		super("Student's information");
		setLayout(new FlowLayout());




		//construct each textfield and label
		stdIDL = new JLabel("Student ID: ");
		add(stdIDL);
		stdIDT = new JTextField(15);
		add(stdIDT);


		firstNameL = new JLabel("First Name: ");
		add(firstNameL);
		firstNameT = new JTextField(15);
		add(firstNameT);

		lastNameL = new JLabel("Last Name: ");
		add(lastNameL);
		lastNameT = new JTextField(15);
		add(lastNameT);


		coursesL = new JLabel("Type all the courses seperated by comma: ");
		add(coursesL);
		coursesT = new JTextArea(5, 20);
		add(coursesT);


		//construct save and exit button
		saveButton = new JButton("Save");
		add(saveButton);
		exit = new JButton("Exit");
		add(exit);

		//anonymous inner class for save button event handling
		saveButton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent event) {

				//get the input values
				int stdID = Integer.parseInt(stdIDT.getText());
				String firstName = firstNameT.getText();
				String lastName = lastNameT.getText();
				String courses = coursesT.getText();

				// add the Student object to the ArrayList of Student
				students.add(new Student(stdID, firstName, lastName, courses));

				// display JOptionPane message dialog
				JOptionPane.showMessageDialog(StudentSerial.this, "Student Saved!", "Success", JOptionPane.PLAIN_MESSAGE);

				// clear the fields
				stdIDT.setText("");
				firstNameT.setText("");
				lastNameT.setText("");
				coursesT.setText("");


				//write all the Student object to the file
				try {

					FileOutputStream fos = new FileOutputStream("students.out");

					ObjectOutputStream oos = new ObjectOutputStream(fos);

					for(Student theStudent : students) {
						oos.writeObject(theStudent);
					}

					oos.flush();
					fos.close();

				} catch (Throwable e) {
					System.err.println(e);
				}

			}
		});

		//anonymous inner class for exit button event handling
		exit.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent event) {

				//close the JFrame
				dispose();
			}
		});

	}


	public static void main(String[] args) {

		StudentSerial studentSerial = new StudentSerial();
		studentSerial.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		studentSerial.setSize(280, 260);
		studentSerial.setVisible(true);

	}

}
