using UnityEngine;
using System.IO.Ports;
using TMPro;

enum TaskState
{
    INIT,
    WAIT_COMMANDS
}

public class Serial : MonoBehaviour
{
    private static TaskState taskState = TaskState.INIT;
    private SerialPort _serialPort;
    private byte[] buffer;
    public TextMeshProUGUI myText;
    private int counter = 0;

    void Start()
    {
        _serialPort = new SerialPort();
        _serialPort.PortName = "COM5";
        _serialPort.BaudRate = 115200;
        _serialPort.DtrEnable = true;

        // CAMBIO: Definí '\n' como el carácter de fin de línea
        _serialPort.NewLine = "\n";
        _serialPort.Open();
        Debug.Log("Open Serial Port");
        buffer = new byte[128];
    }

    void Update()
    {
        myText.text = counter.ToString();
        counter++;

        switch (taskState)
        {
            case TaskState.INIT:
                taskState = TaskState.WAIT_COMMANDS;
                Debug.Log("WAIT COMMANDS");
                break;

            case TaskState.WAIT_COMMANDS:
                // Enviar comando para encender el LED
                if (Input.GetKeyDown(KeyCode.A))
                {
                    _serialPort.Write("ledON\n");  // CAMBIO: Agregué '\n' al comando enviado
                    Debug.Log("Send ledON");
                }

                // Enviar comando para apagar el LED
                if (Input.GetKeyDown(KeyCode.S))
                {
                    _serialPort.Write("ledOFF\n");  // CAMBIO: Agregué '\n' al comando enviado
                    Debug.Log("Send ledOFF");
                }

                // Enviar comando para leer los botones
                if (Input.GetKeyDown(KeyCode.R))
                {
                    _serialPort.Write("readBUTTONS\n");  // CAMBIO: Agregué '\n' al comando enviado
                    Debug.Log("Send readBUTTONS");
                }

                // Leer la respuesta del controlador
                if (_serialPort.BytesToRead > 0)
                {
                    // CAMBIO: Usar ReadLine para leer hasta que llegue el '\n'
                    string response = _serialPort.ReadLine();
                    Debug.Log(response);
                }
                break;

            default:
                Debug.Log("State Error");
                break;
        }
    }
}

