┌───────────────────────────────────────────────────────────────────────────────┐
│                         STUDENT LOGIN & MANAGEMENT SYSTEM                     │
│                               (Advanced README)                               │
├───────────────────────────────────────────────────────────────────────────────┤

📘 PROJECT OVERVIEW
A role-based authentication and student management system developed in C.
It supports Admin, Staff, and Guest functionalities with secure login,
file-based storage, and CRUD operations on student records.

─────────────────────────────────────────────────────────────────────────────────

🔐 FEATURES

1. Secure Login & Authentication
   • Password masking with '*'  
   • Reads credentials from credentials.txt  
   • Supports admin, staff, guest roles  

2. Role-Based Menu Dispatcher
   • Admin: Add, View, Search, Update, Delete  
   • Staff: Add, View, Search, Update  
   • Guest: View, Search only  

3. Student Management
   • Add new student  
   • Display all students  
   • Search student (case-insensitive)  
   • Update student using temp file  
   • Delete student safely via temp rewrite  

4. File Handling
   • credentials.txt → stores username/password/role  
   • students.txt → stores roll, name, marks  
   • Uses temp file mechanism to avoid data corruption  

─────────────────────────────────────────────────────────────────────────────────

🏗 SYSTEM ARCHITECTURE (DIAGRAM INCLUDED IN PROJECT)

User → Login & Authentication → Role-Based Menu → Student Management  
                     |                      |               |  
               credentials.txt         Output/Reports   students.txt  

─────────────────────────────────────────────────────────────────────────────────

📁 PROJECT STRUCTURE

Student-Login-System/
│── main.c
│── credentials.txt
│── students.txt
└── README.md

─────────────────────────────────────────────────────────────────────────────────

🖥 HOW TO RUN

Compile:
    gcc main.c -o student_system

Run:
    ./student_system

─────────────────────────────────────────────────────────────────────────────────

📝 SAMPLE credentials.txt

admin admin123 admin  
staff staff123 staff  
guest guest123 guest  

─────────────────────────────────────────────────────────────────────────────────

📝 SAMPLE students.txt

101 John 87.50  
102 Alice 91.00  
103 Bob 76.25  

─────────────────────────────────────────────────────────────────────────────────

⚙ INTERNAL WORKING

• Login:
  - User enters username & password  
  - Password hidden with '*'  
  - Credentials verified from file  

• CRUD Operations:
  - Add → append new record  
  - Display → read entire file  
  - Search → compare names ignoring case  
  - Update/Delete → rewrite file via temp.txt  

─────────────────────────────────────────────────────────────────────────────────

🛡 SECURITY NOTES

• Password masking  
• Role-based operation restrictions  
• Temporary file method prevents data corruption  
• No hardcoded credentials inside source code  

─────────────────────────────────────────────────────────────────────────────────

🌟 FUTURE ENHANCEMENTS

• Password encryption (SHA-256)  
• Replace text files with CSV/JSON/SQLite  
• Add sorting functionality  
• Implement GUI/Frontend  
• Create API service backend  

─────────────────────────────────────────────────────────────────────────────────

🙌 CONTRIBUTING
Pull requests and improvements are welcome. For major updates, create an issue.

─────────────────────────────────────────────────────────────────────────────────

📜 LICENSE
MIT License – Open-source, free to modify and distribute.

└───────────────────────────────────────────────────────────────────────────────┘
