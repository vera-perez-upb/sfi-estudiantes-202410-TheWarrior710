void setup() {
void mision() {
    enum class TaskStates {
        CONFIG,
        TIMER,
        CAMERA,
        REACTION_NUCLEAR,
        ACCESS,
        SAVE_THE_WORLD
    };

    static TaskStates states = TaskStates::CONFIG;
    static bool entrada = false;
    static uint32_t Time = 5 * 1000;
    static char Value;
    static uint32_t lastime = 0;
    static const String ACCESS_CODE = "1234";  // Código de acceso correcto

    switch(states) {
        case TaskStates::CONFIG: {
            Serial.begin(115200);
            Serial.println("CONFIG");  // Mostrar mensaje de configuración inicial
            Value = Serial.read();
            if (Value == 'S' || Value == 's' || Value == 'B' || Value == 'b') {
                states = TaskStates::TIMER;
            }
            break;
        }
        
        case TaskStates::TIMER: {
            if (Value == 'S' || Value == 's') {
                if (!entrada) {
                    Serial.print("Escriba un número mayor al actual y menor al 40, número actual: ");
                    Serial.println(Time / 1000);
                    entrada = true;
                }

                if (Serial.available() > 0) {
                    String dato = "";
                    while (Serial.available() > 0) {
                        dato += (char)Serial.read();
                        delay(5);
                    }

                    int value = dato.toInt();
                    if (value > Time / 1000 && value <= 40) {
                        Time = value * 1000;
                        Serial.print("El tiempo actualizado es de: ");
                        Serial.println(Time / 1000);
                        Serial.println(" segundos");
                        Serial.println("Para salir pulse L");
                    }
                }

                if (Serial.available() > 0) {
                    char Exit = Serial.read();
                    if (Exit == 'L' || Exit == 'l') {
                        states = TaskStates::CAMERA;
                    }
                }
            } else if (Value == 'B' || Value == 'b') {
                if (!entrada) {
                    Serial.print("Escriba un número menor al actual y mayor al 1, número actual: ");
                    Serial.println(Time / 1000);
                    entrada = true;
                }

                if (Serial.available() > 0) {
                    String dato = "";
                    while (Serial.available() > 0) {
                        dato += (char)Serial.read();
                        delay(5);
                    }

                    int value = dato.toInt();
                    if (value > 1 && value < Time / 1000) {
                        Time = value * 1000;
                        Serial.print("El tiempo actualizado es de: ");
                        Serial.println(Time / 1000);
                        Serial.println(" segundos");
                        Serial.println("Para salir pulse L");
                    }
                }

                if (Serial.available() > 0) {
                    char Exit = Serial.read();
                    if (Exit == 'L' || Exit == 'l') {
                        states = TaskStates::CAMERA;
                    }
                }
            }
            break;
        }

        case TaskStates::CAMERA: {
            uint32_t tiempo = millis();
            if ((tiempo - lastime) >= 1000) {
                lastime = tiempo;
                if (Time > 0) {
                    Time -= 1000;
                    Serial.print("Tiempo restante: ");
                    Serial.println(Time / 1000);
                } else {
                    states = TaskStates::REACTION_NUCLEAR;
                }
            }

            if (Serial.available() > 0) {
                char acces = Serial.read();
                if (acces == 'c' || acces == 'C') {
                    states = TaskStates::ACCESS;
                }
            }
            break;
        }

        case TaskStates::REACTION_NUCLEAR: {
            Serial.println("RADIACIÓN NUCLEAR ACTIVA");
            delay(2000);
            states = TaskStates::CONFIG;  // Volver al modo de configuración después de 2 segundos
            break;
        }

        case TaskStates::ACCESS: {
            if (Serial.available() > 0) {
                String codigo = "";
                while (Serial.available() > 0) {
                    codigo += (char)Serial.read();
                    delay(5);
                }

                codigo.remove(0, 1);  // Remover la primera letra 'C'
                if (codigo == ACCESS_CODE) {
                    Serial.println("SALVASTE AL MUNDO");
                    states = TaskStates::SAVE_THE_WORLD;
                } else {
                    Serial.println("Código incorrecto, la cuenta regresiva continúa...");
                    states = TaskStates::CAMERA;
                }
            }
            break;
        }

        case TaskStates::SAVE_THE_WORLD: {
            // Aquí puedes implementar cualquier lógica adicional después de salvar el mundo
            break;
        }
    }
}

void setup() {
    // Iniciar la misión
    mision();
}

void loop() {
    // Ejecutar la misión continuamente
    mision();
}
