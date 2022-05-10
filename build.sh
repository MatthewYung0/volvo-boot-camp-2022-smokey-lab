####################################
# Script to build all files
####################################
# Make the bash program executable
# by +x (adding execute permission to all)
# chmod +x *.sh
####################################
#!/bin/bash

mkdir build
echo "create directory"
cd build
echo "move into build"
cmake ..
echo "run cmake"
make
echo "run make"

# add terminal you use if you dont have
# mate-terminal
cd app/emulator/ && mate-terminal&
echo "open emulator terminal"
cd app/input_handler/ && mate-terminal&
echo "open input_handler terminal"
