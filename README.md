

 Registration System is  a console application that  allows users to register students, store information, sort the list and undo the recent registration, which targets the UN Sustainable Development Goals (SGD) 4.



In many schools, especially smaller institutions and school provinces, student registration and record keeping are still done manually using paper lists or unorganized spreadsheets. This often results in errors, duplicated entries, slow data retrieval, and difficulty in sorting or updating information. There is also no easy way to undo mistakes during data entry.


The issue is being addressed  by providing a structured, efficient method to:
Enter and store information
Sort the Students information
Undo wrong information
Display Student formally.



1. Array for Storing Students (students[MAX])

Type: Student students[MAX];

Description:
The students array stores the student records. It is declared with a fixed size of MAX = 100, which limits the number of students the program can handle at any given time.

Justification:

Fixed Size: The use of an array is suitable here as the program assumes the number of students will not exceed MAX (100).

Efficiency: Arrays provide constant-time access (O(1)) to elements, making operations like adding, displaying, and sorting efficient.

Simplicity: Arrays are a straightforward choice for managing a collection of student records where the maximum size is known ahead of time.

2. Stack for Undo Operations (undo[MAX])

Type: Student undo[MAX];

Description:
The undo array functions as a stack, used to store students' data temporarily for undoing the last student registration.

Justification:

Last In, First Out (LIFO): The stack implements the LIFO principle, ideal for undo functionality. The most recently added student can be removed first to reverse the last registration.

Efficient Management of Undo: By storing each new student in the stack, the program can easily "rollback" the last action without altering the main list of students.

3. Integer Variable for Tracking Number of Students (pupils)

Type: int pupils;

Description:
The pupils variable keeps track of the current number of students in the students array. It is incremented as new students are added.

Justification:

Dynamic Counter: This variable ensures that the program doesn't exceed the bounds of the students array, and it enables correct indexing for adding and displaying student records.

Simple and Effective: It allows for the dynamic management of student records without needing to dynamically allocate memory, making the program straightforward to implement.

4. Integer for Managing Stack Top (top)

Type: int top;

Description:
The top variable tracks the top index of the stack (undo array), indicating the most recent operation that can be undone.

Justification:

Stack Management: The top variable ensures that the stack operations (push and pop) are handled correctly. It is initialized to -1, indicating an empty stack, and is incremented or decremented as students are added or removed.

Efficient Undo: The top variable makes stack operations efficient and enables quick rollback of the last student addition.

5. Dynamic Sorting Mechanism Using Arrays

Description:
The program uses a bubble sort algorithm to sort the student records by student ID, name, or GPA. The sorting is performed in-place (directly on the students array).

Justification:

Bubble Sort: Although bubble sort has O(n²) time complexity, it is appropriate for small datasets, such as the list of students in this program (limited to MAX = 100 students).

In-place Sorting: Sorting is performed directly on the students array, which saves memory compared to creating a separate sorted copy.

Simplicity: The bubble sort is simple to implement and is sufficient for the size of data handled by this program. For larger datasets, a more efficient sorting algorithm (like quicksort) could be considered.

6. File I/O with Arrays

Description:
The program saves and loads student data to/from a CSV file using file input/output (I/O) operations. The student data is read into the students array and written back after changes.

Justification:

Persistence: File I/O ensures that student records are preserved across program runs, making the data persistent.

Efficient Storage: The students array is already in memory, so using it to store and manipulate student records before saving them to a file is both memory-efficient and straightforward.

Ease of Parsing: The CSV format is simple to parse, and the array provides an easy way to map each CSV record to a corresponding Student object.

7. Sorting Using Standard Library sort Function

Description:
The program uses the C++ standard library's sort() function to sort the student records by student ID when saving them to a CSV file.

Justification:

Optimal Sorting: The sort() function in the C++ Standard Library uses efficient algorithms like quicksort or introsort, which provides better performance than bubble sort (O(n log n)).

Library Integration: The sort() function is simple to use and reduces the complexity of implementing sorting manually. It improves performance when handling larger datasets, especially when saving to a file.
