# Unidad 3



## EJercicio 1



##### Un protocolo binario es un conjunto de reglas que definen cómo se debe estructurar y transmitir la información entre dispositivos utilizando datos binarios (0s y 1s). En este tipo de comunicación, se transmiten directamente secuencias binarias que representan comandos, respuestas, y datos.

##### Al observar el datasheet del sensor mencionado, podemos identificar algunos aspectos clave del protocolo binario que utiliza. Aquí está un desglose con base en las preguntas planteadas:

### 1. ¿Cómo se ve un protocolo binario?
##### Un protocolo binario define un conjunto de mensajes que contienen secuencias específicas de bits. Cada mensaje suele tener un formato estructurado que incluye partes que indican:

##### Instrucciones que el sensor debe ejecutar.
##### Datos que se desean leer o escribir.
##### Respuestas del sensor.
##### Por ejemplo, en el protocolo de este sensor, los mensajes están compuestos de varios campos, cada uno con una cantidad específica de bits, que permiten transmitir información precisa de manera eficiente y compacta.

### 2. ¿Puedes describir las partes de un mensaje?
##### Un mensaje en un protocolo binario típico puede tener las siguientes partes:

##### Cabecera (Header): Generalmente, la primera parte del mensaje que contiene información sobre el tipo de mensaje o el inicio de la comunicación.

##### Comando (Command Code): Indica la acción que se debe realizar. Por ejemplo, leer datos, escribir datos o cambiar configuraciones en el sensor.

##### Datos (Data Fields): Estos son los valores binarios que representan la información que se transmite. Puede ser, por ejemplo, la lectura de una medición del sensor.

##### Checksum o CRC (Cyclic Redundancy Check): Esta es una secuencia de bits que se utiliza para verificar la integridad de los datos durante la transmisión. Se usa para detectar errores.

##### Terminator: A veces, se incluye un finalizador o delimitador que señala el final del mensaje.

### 3. ¿Para qué sirve cada parte del mensaje?
##### Cabecera: Identifica el inicio del mensaje y ayuda a sincronizar la comunicación entre el emisor y el receptor. También puede especificar el tipo de mensaje o la versión del protocolo.

##### Comando: Indica lo que el dispositivo debe hacer. Por ejemplo, en un sensor, un comando puede solicitar que envíe una medición o cambie a un modo de operación diferente.

##### Datos: Contiene la información que se está transmitiendo, como una medida obtenida por el sensor o un valor que se quiere enviar al sensor para modificar su comportamiento.

##### Checksum o CRC: Verifica que los datos recibidos no se hayan corrompido durante la transmisión. Es un mecanismo de control de errores.

##### Terminator: Marca el final del mensaje para que el receptor sepa que ha recibido todo el mensaje completo. 

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

