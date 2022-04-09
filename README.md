# Comp3004_Team_Project

Team 12:
	Patrick Brennan
	Vincent Vogl
	Minh Nguyen
	Tom Mai

Work Done:

	Patrick Brennan:
		Back-end coding (mainwindow, battery, treatmentdata, session, sessiontypes)
		Minor UI tweaks

	Minh Nguyen:
		Back-end coding (device)
		Sequence Diagram_1-6.pdf

	Vincent Vogl:
		UI Design (Images in pngs folder + Main Interface)
		UML-Diagram.pdf

	Tom Mai:
		UI Design (Device Internal Simulator + Main Interface)
		Use_Cases.pdf, Use_Cases_Diagram.pdf, Traceability_Matrix.pdf

File organization of deliverables:

	 Project Readme File: Comp3004_Team_Project/README.md

	Project Source Files: Comp3004_Team_Project/MLGproject/

	   Project Use Cases: Comp3004_Team_Project/Documents/Use_Cases.pdf

	    Use Case Diagram: Comp3004_Team_Project/Documents/Use_Cases_Diagram.pdf

	   UML Class Diagram: Comp3004_Team_Project/Documents/UML-Diagram.pdf

	   Sequence Diagrams: Comp3004_Team_Project/Documents/Sequence Diagram_1-6.pdf

	 Traceability Matrix: Comp3004_Team_Project/Documents/Traceability_Matrix.pdf


Tested Scenarios: 
	       Power On/Off: Working
	       
	      Battery Level: Working
	      
	Selecting A Session: Working
	
	    Connection Test: Working
	    
	Adjusting Intensity: Working
	
	Treatment Recording: Working
	
How to use the device:
	To turn the device on, hit the power button, which will cause the inicator above the button to turn green.
	
	When the device is on, the battery will start to drain, and your current selected time and session type 
	will glow green. To select a different time, click one of the 3 circle icons on the top (20 minute, 
	45 minute, or custom). If custom time is selected, enter the time in minutes into the 'Set Time' box.
	To select a different session type, click one of the 4 icons below the time icons (Alpha, Beta 1, Delta,
	Theta).
	
	A treatment using the selected settings can be started by clicking the Start (Checkmark) button on the 
	bottom left of the device. The treatment will not start if the 'Attach Device To Skin' dropdown on the 
	right is set to false. If 'Attach Device To Skin' is set to false during a treatment, the treatment will
	be paused until it is set back to true.
	
	A countdown timer for the current treatment can be found in the top right of the device. The intensity of 
	the treatment can be increased/decreased using the 'INT' arrows. When the treatment is finished, the device
	will turn off. If the 'Add Treatment To History' checkbox is checked when the treatment ends, the treatment
	will be added to the Treatment History window the next time the device is powered on.
	
	To start a recorded treatment, click that treatment from the list within the Treatment History window, then
	hit the History (H) button to start that recorded treatment. Note that pushing the Start button will NOT 
	start your selected recorded treatment, as the Start button uses the currently selected Time, Session Type,
	and Intensity settings outside the Treatment History window. To reiterate, use the Start button to start
	normal treatments, and use the History button to start recorded treatments from the Treatment History window.
	
Note:
	If you are having trouble getting the code to build, try closing QT, deleting 'MLGproject.pro.user', opening
	QT and trying to run the project again.
	
	
