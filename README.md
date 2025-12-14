Project overview and problem statement:

The Student Registration System is a project developed using the C++ programming language to address common challenges in student registration and applicant management within higher education institutions. The system utilizes fundamental data structures such as arrays and stacks, along with sorting algorithms and file handling techniques, to efficiently store, organize, and manage student records.


						

The application enables users to register students, automatically generate unique student identification numbers based on the current date, sort student records by different criteria (Student ID, name, and result average), shortlist qualified applicants, undo the most recent registration, and store data persistently using CSV files. The system is designed with a fixed capacity of 100 students per day, reflecting realistic operational constraints in public universities.
This project aligns with the United Nations Sustainable Development Goal (SDG) 4: Quality Education, specifically:
SDG 4.3: Ensuring equal access for all to affordable and quality tertiary education.
SDG 4.a: Improving education systems through student-centered and inclusive administrative solutions.
By introducing a structured and automated registration process, the system supports educational institutions in improving efficiency, accuracy, and accessibility in student admissions.





State universities in the Philippines consistently face challenges in managing student registration and applicant screening due to limited manpower, budget constraints, and a high volume of applicants. According to reports from the Commission on Higher Education (CHED), state universities and colleges (SUCs) accommodate thousands of applicants each academic year, often with administrative offices operating using manual or semi-digital systems. These conditions place significant pressure on registration staff and existing infrastructure.
In many state universities, registration processes are conducted based on fixed schedules with limited daily capacity. This results in long queues, overcrowded registration areas, delayed processing of student records, and increased likelihood of data entry errors. During peak enrollment periods, it is common for applicants to spend several hours waiting for their registration to be processed, while administrators struggle to organize, sort, and validate student information efficiently.
Furthermore, the lack of automated sorting and filtering mechanisms makes it difficult for institutions to quickly identify qualified applicants based on academic performance. Manual record handling also increases the risk of misplaced data and inconsistent record keeping, which can negatively affect both students and administrators.
This capstone project addresses these documented challenges by developing a Student Registration Sorting System capable of accommodating up to 100 students per day, even within a limited scheduling framework. By automating student registration, sorting, shortlisting, and data storage, the system provides a practical solution that reduces administrative workload, minimizes errors, and improves the overall efficiency and reliability of the registration process in Philippine state universities.



INSTALLATION AND SET UP:

1.Open VS Code.
2.Select the Extensions view icon on the Activity Bar or use the keyboard shortcut (Ctrl+Shift+X).
3.Search for 'C++'.
4. Select Install.
5. Check if you have a compiler installed, to check Open a new VS Code terminal window using (Ctrl+Shift+`) Use the following command to check for the GCC compiler g++:  g++ --version then clang --version
if you dont have a compiler kindly install






HOW TO USE REGISTRATION SYSTEM
if you run the code you will see menu that has 8 choices
1 to register a student, you will input your name and result. it will automatically create you a id
2 is to undo last registered student
3,4,and 5is you can sort all the registered student by its id, name, results
6 is to display the list on your prefered list(alphabetically, by id, or by grades).
7 is to have a shortlist of student who pass the examination, here you will require a grade to remove all failing student.
8 to exit the program. Dont worry the list will not going to vanish because all the student registered is in the csv file.


This project is made by Mr. John Albert David.



