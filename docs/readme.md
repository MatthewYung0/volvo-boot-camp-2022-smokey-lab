# Overview
The purpose of this project is to develop a program which recieves input from the user, and transmit the message through a simulated CAN network between modules.

The minimum project requirements are:
- One executable receiving user input transmitting CAN messages
- One executable with at least 2x threads:
  - One reading CAN data
  - Emulating

<p>&nbsp;</p>

![Project_Deliverables](https://github.com/MatthewYung0/volvo-boot-camp-2022-smokey-lab/blob/master/docs/Project%20Requirements.png)

![Project_Deliverables](https://github.com/MatthewYung0/volvo-boot-camp-2022-smokey-lab/blob/master/docs/frame_overview.png)

SocketCAN was installed and used to simulate the CAN environment

### Use Case Table



# Input Handler
The functionality of the Input Handler is to recieve inputs from the user, and output it as a CAN message to the Message Handler module. In this project, the input is through the keyboard where the user presses a key, and the output is produced.

![Project_Deliverables](https://github.com/MatthewYung0/volvo-boot-camp-2022-smokey-lab/blob/master/docs/Output_Frame_Input_Handler.png)

# Message Handler
As the name suggests, the purpose of the Message Handler is to read and write CAN messages between specific modules.
The Message Hanlder will read CAN messages from the Input Handler, and executes the instructions that changes the state of the emulator.
It will also output the state of the emaulator to the Message Output module (i.e. GUI interface)

# Emulator
The emulator is a simulated object which represents the functionalities of a typical vehicle (e.g engine, gearbox). It's state is changed based on the instructions that is sent via the CAN message from the Input Handler to the Message Handler.

An example:
1) The user presses 's' on the keyboard.
2) The Input Handler converts this into a specific CAN message.
3) The CAN message is received by the Message Handler.
4) The Message Handler will read this message, and execute it's instruction to change the state of the emulator if requested.
5) The current state of the Emulator will be read by the Message Handler (e.g. RPM, speed, gear).
6) The Message Handler will output this information in a CAN message to the Message Output.

# Message Output

![Project_Deliverables](https://github.com/MatthewYung0/volvo-boot-camp-2022-smokey-lab/blob/master/docs/Input_Frame_Output_Handler.png)
