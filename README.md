══════════════════════════════════════════════════════════════════════╗
║                 STUDENT LOGIN SYSTEM – ARCHITECTURE OVERVIEW         ║
╠══════════════════════════════════════════════════════════════════════╣
║                                                                      ║
║  MODULE DESCRIPTIONS:                                                ║
║                                                                      ║
║  1. User Interaction Layer:                                          ║
║     - Entry point for Admin, Staff, and Guest users.                 ║
║     - Users provide credentials and select menu operations.          ║
║                                                                      ║
║  2. Login & Authentication:                                          ║
║     - Reads data from credentials.txt.                               ║
║     - Validates username and password.                               ║
║     - Assigns user role after verification.                          ║
║     - Uses secure masked password input.                             ║
║                                                                      ║
║  3. Role-Based Menu Dispatcher:                                      ║
║     - Displays menu options depending on user role.                  ║
║     - Admin: Full access (Add, View, Search, Update, Delete).        ║
║     - Staff: Limited access (No delete).                             ║
║     - Guest: Read-only access (View, Search).                        ║
║                                                                      ║
║  4. Student Management Module:                                       ║
║     - Handles all operations on student records:                     ║
║       Add, Display, Search, Update, Delete.                          ║
║     - Works closely with the file handling system.                   ║
║                                                                      ║
║  5. File Handling Engine:                                            ║
║     - Reads/writes data to students.txt.                             ║
║     - Uses temp file mechanism for safe update/delete.               ║
║     - Ensures data consistency across operations.                    ║
║                                                                      ║
║     D1: credentials.txt                                              ║
║       → Stores username, password, and role.                         ║
║                                                                      ║
║     D2: students.txt                                                 ║
║       → Stores roll, name, marks.                                    ║
║                                                                      ║
║  6. Output/Reports Module:                                           ║
║     - Displays results such as search output, student lists,         ║
║       update status, delete confirmation, and error messages.        ║
║                                                                      ║
║  END-TO-END WORKFLOW:                                                ║
║     1. User opens program and logs in.                               ║
║     2. Authentication validates their credentials.                    ║
║     3. Based on role, menu options are shown.                        ║
║     4. User selects an operation.                                    ║
║     5. Student Management executes the task.                         ║
║     6. File Handling reads/writes required data.                     ║     ║
║     7. Output is displayed to the user.                              ║
║     8. User continues operations or logs out.                        ║
║                                                                      ║
║  SUMMARY:                                                            ║
║     This architecture ensures secure access, clear role separation,  ║
║     safe file handling, and a smooth flow between authentication,    ║
║     menu dispatching, and student data operations.                   ║
╚══════════════════════════════════════════════════════════════════════╝
