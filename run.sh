echo "Updating apt... please enter your password:"
sudo apt update 2>&1 >/dev/null
echo "Updating g++..."
sudo apt install g++ 2>&1 >/dev/null
echo "Finished with apt."
echo "Compiling source..."
g++ -o sasmir main.cpp 2>&1 >/dev/null
echo "Finished"