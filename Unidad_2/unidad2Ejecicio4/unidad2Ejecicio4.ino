String getState(int risk, int save, int consume) {
    return String(risk) + "," + String(save) + "," + String(consume) + "\n";
}

void setup() {
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    static int riesgo = 0, ahorro = 0, consumo = 0;
    static int speed = 1000;  
    static bool changeEnabled = false;
    static unsigned long previousMillis = 0;
    
    // Blink LED
    digitalWrite(LED_BUILTIN, millis() / 500 % 2);

    if (Serial.available() > 0) {
        String command = Serial.readStringUntil('\n');
        if (command.startsWith("GET_VARS")) {
            Serial.print(getState(riesgo, ahorro, consumo));
        }
        else if (command.startsWith("SET_SPEED")) {
            speed = command.substring(10).toInt();
        }
        else if (command == "START") {
            changeEnabled = true;
        }
        else if (command == "STOP") {
            changeEnabled = false;
        }
        else if (command.startsWith("SET_INIT_VAL")) {
            int initVal = command.substring(12).toInt();
            riesgo = ahorro = consumo = initVal;
        }
    }

    if (changeEnabled && millis() - previousMillis >= speed) {
        previousMillis = millis();
        riesgo++;
        ahorro++;
        consumo++;
    }
}

