uint8_t val =0;

void setup() {
  // Inicializa ambos puertos UART
  Serial.begin(115200);  // Inicializa el puerto UART principal
  Serial2.begin(115200); // Inicializa el segundo puerto UART

    pinMode(2, OUTPUT);
    digitalWrite(2,val);
}

void loop() {

  while (Serial.available() > 0) {      // Si hay datos disponibles en el puerto UART principal
    char c = Serial.read();             // Lee un carácter
    Serial2.write(c);                   // Escribe el carácter en el segundo puerto UART

    if(c=='r'){
      val = ~val;
      digitalWrite(2,val);
    }
  }

  while (Serial2.available() > 0) {     // Si hay datos disponibles en el segundo puerto UART
    char c = Serial2.read();            // Lee un carácter
    Serial.write(c);                    // Escribe el carácter en el puerto UART principal

    if(c=='r'){
      val = ~val;
      digitalWrite(2,val);
    }
  }
}