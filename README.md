# sfi-estudiantes-202410-TheWarrior710

## EJercicio 3

### Coloca el nombre del equipo, el nombre de los integrantes y el ID. Coloca en el archivo el resultado del cambio de 100 a 500. Describe lo que viste.
#### ___________________________,NOMBRES: Nicolas Sedano, Jesus Bonivento, ID: 522547,511106

#### Informe:

##### Al cambiar el 100 por un 500 en el codigo estando dentro de la aplicacion de arduino se puede apreciar que el led verde  ahora ya no parpadea seguido como se apreciaba anteriormente si no ahora titilea cada 2 segundos pausadamente.


## EJercicio 4: 

### Recuerda que cada ejercicio lo trabajas en la carpeta que lleva su nombre dentro de tu repositorio de trabajo, en el enlace que hay al principio de esta página. Solo debes adicionar un archivo README.md con el nombre del equipo, integrantes y ID y un enlace a un repositorio `PÚBLICO` donde harás lo siguiente:

### - Crea un proyecto para el raspberry pi.
### - En el código modifica el 500 por 1000.
### - Coloca el proyecto bajo control de versión.
### - Sincroniza tu repositorio local con un repositorio público en Github. El enlace a este repositorio será el que coloques en el archivo README.md de la evaluación.

#### Informe:

##### Al cambiar el 500 por un 1000 en el codigo estando dentro de la aplicacion de arduino se puede apreciar que el led verde  ahora ya no parpadea cada 2 segundos como se apreciaba anteriormente si no ahora titilea cada 3 segundos pausadamente.

## EJercicio 5: 

### Para programar el raspberry pi pico tienes mucha documentación con información. Algunos sitios que pueden serte de utilidad son:

### - [API de arduino](https://www.arduino.cc/).
### - [Port para raspberry pi pico del API de arduino](https://arduino-pico.readthedocs.io/en/latest/#).
### - [Sitio oficial del raspberry pi pico](https://www.raspberrypi.com/products/raspberry-pi-pico/).

### En el archivo README.md de este ejercicio realiza por favor con tus palabras, preferiblemente a mano, un resumen de los elementos más importantes que identificaste en esta documentación. No olvides enviarla al repositorio remoto.


#### Informe:

##### Documentación del API de Arduino: La API de Arduino está diseñada para ayudar a los desarrolladores a crear, desplegar y monitorear proyectos de IoT (Internet de las Cosas) utilizando el ecosistema Arduino. La documentación incluye cómo interactuar con las placas Arduino, gestionar recursos en la nube y controlar dispositivos a través de Arduino IoT Cloud. Ofrece métodos para la gestión de dispositivos, registro de datos y creación de integraciones personalizadas, lo que la convierte en una herramienta versátil tanto para principiantes como para desarrolladores experimentados​ (Arduino Docs)​ (Arduino Docs).

##### Port oficial de Arduino para Raspberry Pi Pico: Esta es la adaptación oficial del núcleo de Arduino para la Raspberry Pi Pico, permitiendo programar este microcontrolador utilizando el entorno de desarrollo Arduino IDE. La documentación proporciona información detallada sobre cómo configurar el entorno, cargar programas y utilizar las bibliotecas compatibles con el Pico, facilitando así el uso de este hardware con la amplia gama de herramientas y recursos de Arduino.

##### Sitio oficial del Raspberry Pi Pico: Esta página proporciona una visión general del Raspberry Pi Pico, un microcontrolador pequeño y potente basado en el chip RP2040 diseñado por Raspberry Pi. Incluye especificaciones técnicas, características clave, y guías de inicio para ayudar a los usuarios a comenzar a desarrollar proyectos con este dispositivo. Es un recurso esencial para quienes desean explorar el hardware de Raspberry Pi con aplicaciones en proyectos electrónicos y de IoT.

## EJercicio 6: 

### Programa la siguiente aplicación en el raspberry y analiza su funcionamiento. Para descubrir lo que hace debes dar click en el ícono que queda en la esquina superior derecha (Monitor Serie). Los números que vez allí son enviados desde el microcontrolador al computador por medio del puerto USB.

### ¿Cómo se ejecuta este programa?
### Pudiste ver este mensaje: Serial.print("Task1States::WAIT_TIMEOUT\n");. ¿Por qué crees que ocurre esto?
### ¿Cuántas veces se ejecuta el código en el case Task1States::INIT?


#### Informe:
##### el código inicializa la comunicación serial, luego imprime el tiempo en intervalos de 1000 ms en el bucle principal. La impresión ocurre cada vez que el tiempo actual supera el intervalo definido desde la última impresión.

