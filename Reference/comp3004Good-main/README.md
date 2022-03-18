# COMP3004 Team Project
### Team number: 21

### Members
- Zachary Hamel
- David Chen
- Minh Thang Cao

### Install
1. Clone the repo: `git clone https://github.com/Zachary-Hamel/comp3004Good.git`
2. Open `comp3004project.pro` (inside cloned repo) in Qt Creator
3. Click on "Configure project" to set up the Qt environment for the project

### Work Divided
**Did together**
  - Wrote Use-Cases
  - Bug fixes
  - Testing 
  
**Zachary Hamel**
  - Implementation of UC 3, 4, 6
  - Some of the UI Layout (Minh Thang Cao improved on it later)
  - Some of the UML (David Chen finalized it)

**David Chen**
  - Implementation: UC 1, UC 2, UC 7 
  - Modified Sequence Diagram 7
  - Use Case Diagram 
  - Traceability Matrix   

**Minh Thang Cao**
  - Implementation: UC 4, 8, 9, 10
  - Sequence diagrams


### Folder Organization
```
.
├── src                               # header files (*.h) and source files (*.cpp)         
│   ├── device.h             
│   ├── device.cpp            
│   ├── mainwindow.h           
│   ├── mainwindow.cpp 
│   ├── treatment.h
│   ├── treatment.cpp 
│   ├── main.cpp 
├── ui                                 # User Interface files (*.ui)
│   ├── MainWindow.ui                  # Main user interface layout
├── diagrams-Documentation             # Documentation files (alternatively `doc`)
│   ├── Final Project Traceability Matrix.pdf            
│   ├── UML.png                        # The project's UML
│   ├── Use Case                       # Folder with use case diagrams
│   │    ├──    CES Use Case.pdf                      
│   │    ├──    Final Project UC Diagram.pdf      
│   ├── sequence                       # Folder with sequence diagrams
│   │    ├── UC1.png  
│   │    ├── UC2.png  
│   │    ├── UC3.png   
│   │    ├── UC4.png   
│   │    ├── UC5.png   
│   │    ├── UC6.png   
│   │    ├── UC7.png   
│   │    ├── UC8.png   
│   │    ├── UC9.png     
│   │    ├── UC10.png   
├── .gitignore
├── comp3004project.pro
└── README.md
```

### Tested Scenarios: 
Per the traceability matrix every scenario works, as well as additional scenarios to help the TAs such as drain battery buttons, fast forward button and fix exceeded current limit.
