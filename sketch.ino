//Pin definition
#define pino_D12 12
#define pino_D13 13
#define pino_D14 14

#define pin_ADC 15

int adc_value = 0;

void setup() {
  Serial.begin(115200); 
  Serial.println("Serial begin.");
  
  //Pin mode definition
  pinMode(pino_D12, OUTPUT);
  pinMode(pino_D13, OUTPUT);
  pinMode(pino_D14, OUTPUT);
  pinMode(pin_ADC, INPUT);
}

void set(int X, int Y) {
  // Function to set pin D12, D13 and D14 as 0 or 1


  // Y value defines if the value is 0 or 1
  // X defines which pin should be set

  if (Y == 1) {
    switch (X) {
      case 0:
        digitalWrite(pino_D12, HIGH);
        break;
      case 1:
        digitalWrite(pino_D13, HIGH);
        break;
      case 2:
        digitalWrite(pino_D14, HIGH);
        break;
      default:
        Serial.print("Invalid X.");
        break;
    }
  } else if (Y == 0) {
    switch (X) {
      case 0:
        digitalWrite(pino_D12, LOW);
        break;
      case 1:
        digitalWrite(pino_D13, LOW);
        break;
      case 2:
        digitalWrite(pino_D14, LOW);
        break;
      default:
        Serial.print("Invalid X.");
        break;
    }
  }
  else {
    Serial.println("Invalid Y");
  }

  //Concat values
  int D12 = digitalRead(pino_D12);
  int D13 = digitalRead(pino_D13);
  int D14 = digitalRead(pino_D14);

  int pin_dec = (D14 << 2) | (D13 << 1) | D12;


  // Print pin value
  Serial.println("Pin value: ");
  Serial.print("D12:");
  Serial.println(D12);
  Serial.print("D13:");
  Serial.println(D13);
  Serial.print("D14:");
  Serial.println(D14);

  // Print decimal value of concat pins
  Serial.println("Decimal value: ");
  Serial.println(pin_dec);
}

void read_ADC() {

  adc_value = analogRead(pin_ADC); // reads ADC pin
  //Prints analog input
  Serial.println("Analog input: ");
  Serial.println(adc_value);
}


void loop() {

  //string capture from serial
  if (Serial.available() > 0) {
    String mensage = Serial.readStringUntil('\n');

    //Check if valid command
    if (mensage.startsWith("set - ")) {
      // Divide string into X and Y
      // Message format: “set - X/Y”
      int X = mensage.substring(6, 7).toInt();
      int Y = mensage.substring(8).toInt();

      // Function call to set according to X and Y message
      set(X, Y);

    } else if (mensage.startsWith("Read ADC")) {
      // Function call to read ADC input
      read_ADC();
    }
  }
}
