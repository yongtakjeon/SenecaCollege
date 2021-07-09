// Name: Yongtak Jun
// Date: July/05/2021

import java.io.EOFException;
import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.util.ArrayList;

import java.awt.FlowLayout;
import java.awt.GridBagLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class StudentDeserial extends JFrame {

	JPanel container = new JPanel(new GridBagLayout());

	private final ArrayList<JTextArea> stuInfo = new ArrayList<JTextArea>();
	private final ArrayList<JLabel> stdPage = new ArrayList<JLabel>();
	private final JButton exit;

	public StudentDeserial() {

		super("Students' information");
		setLayout(new FlowLayout());

		ArrayList<Student> testStudents = new ArrayList<Student>();

		try {

			FileInputStream fis = new FileInputStream("students.out");

			ObjectInputStream ois = new ObjectInputStream(fis);

			try {
				// it reads the object from the file until it throws EOFException
				while(true) {
					testStudents.add((Student)ois.readObject());
				}

			} catch(EOFException e) {
				System.out.println("Students Deserialization complete!");
				System.out.println();
			}

			fis.close();


		} catch (Throwable e) {
			System.err.println(e);
		}

		//print all the test Student object
		int totalNumOfStu = testStudents.size();
		int StuNum = 0;
		for(Student testStu : testStudents) {
			StuNum++;
			stdPage.add(new JLabel("Student " + StuNum + " out of " + totalNumOfStu));
			add(stdPage.get(stdPage.size()-1));

			String info = "Student ID: " + testStu.getStudentID() + "\n" +
					"Student Name: " + testStu.getName() + "\n" +
					"Courses the student currently has:\n" +
					testStu.getCourses();

			stuInfo.add(new JTextArea(info, 5, 20));
			stuInfo.get(stuInfo.size()-1).setEditable(false); // disable editing
			add(stuInfo.get(stuInfo.size()-1));

		}

		//construct exit button
		exit = new JButton("exit");
		add(exit);

		//anonymous inner class for button event handling
		exit.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent event) {
				
				//close the JFrame
		        dispose();
			}
		});


	}

	public static void main(String[] args) {

		StudentDeserial studentDeserial = new StudentDeserial();
		studentDeserial.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		studentDeserial.setSize(270, 400);
		studentDeserial.setVisible(true);

	}


}
