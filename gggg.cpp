const int bitPins[4] = {2, 3, 4, 5}; // Define digital pins 2, 3, 4, and 5 as bit pins

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(bitPins[i], OUTPUT); // Set bit pins as output
  }
}

void loop() {
  for (int number = 0; number < 16; number++) {
    // Display the binary representation on the 4 bit pins
    for (int bit = 0; bit < 4; bit++) {
      digitalWrite(bitPins[bit], (number >> bit) & 1);
    }
    delay(100); // Delay to display each pattern for 1 second
  }
  for (int number = 15; number >=0; number--) {
    // Display the binary representation on the 4 bit pins
    for (int bit = 0; bit < 4; bit++) {
      digitalWrite(bitPins[bit], (number >> bit) & 1);
    }
    delay(100); // Delay to display each pattern for 1 second
  }
}
