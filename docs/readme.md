# 1.Overview
The purpose of this project is to develop a program which recieves input from the user, and transmit the message through a simulated CAN network between modules. SocketCAN was installed and used to simulate the CAN environment

The minimum project requirements are:
- One executable receiving user input transmitting CAN messages
- One executable with at least 2x threads:
  - One reading CAN data
  - Emulating

<p>&nbsp;</p>

![Project_Deliverables](https://github.com/MatthewYung0/volvo-boot-camp-2022-smokey-lab/blob/master/docs/Project%20Requirements.png)

Each CAN message will have a 'frame' of 8 bits as shown below. The Input Handler and the Emulator will only accept specific Frame ID's (i.e. Emulator will accept only 0xAAA, while the Output Display will only accept 0xBBB). This is to ensure that the message is read by the right module.

![Project_Deliverables](https://github.com/MatthewYung0/volvo-boot-camp-2022-smokey-lab/blob/master/docs/Frame_Overview.png)

# 2. Input Handler
The functionality of the Input Handler is to recieve inputs from the user, and output it as a CAN message to the Message Handler module. In this project, the input is through the keyboard where the user presses a key, and the output is produced.

![Input_Handler](https://github.com/MatthewYung0/volvo-boot-camp-2022-smokey-lab/blob/master/docs/Output_Frame_Input_Handler.png)

# 3. Message Handler
As the name suggests, the purpose of the Message Handler is to read and write CAN messages between specific modules.
The Message Handler will read CAN messages from the Input Handler, and executes the instructions that changes the state of the emulator.
It will also output the state of the emaulator to the Message Output module (i.e. GUI interface)

# 4. Emulator
The emulator is a simulated object which represents the functionalities of a typical vehicle (e.g engine, gearbox). It's state is changed based on the instructions that is sent via the CAN message from the Input Handler to the Message Handler.

An example:
1) The user presses a valid key on the keyboard.
2) The Input Handler converts this into a CAN message with the specific ID of 0xAAA.
3) The CAN message is received by the Message Handler.
4) The Message Handler will read this message, and execute it's instruction to change the state of the emulator.
5) The current state of the Emulator will be read by the Message Handler (e.g. RPM, speed, gear).
6) The Message Handler will output this information in a CAN message with ID of 0xBBB to the Message Output.

## 4.1 State Diagram
![State_Diagram](https://github.com/MatthewYung0/volvo-boot-camp-2022-smokey-lab/blob/master/docs/State%20Diagram%20(Rev%202).png)

# 5. Message Output

![Project_Deliverables](https://github.com/MatthewYung0/volvo-boot-camp-2022-smokey-lab/blob/master/docs/Input_Frame_Output_Handler.png)
