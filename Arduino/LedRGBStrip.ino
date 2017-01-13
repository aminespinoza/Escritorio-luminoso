#define redLightRight 13
#define greenLightRight 12
#define blueLightRight 11
#define redLightCenter 10
#define greenLightCenter 9
#define blueLightCenter 8
#define redLightLeft 7
#define greenLightLeft 6
#define blueLightLeft 5

String primeraCadena, segundaCadena, terceraCadena;
String dataReceived = "";
int redRight, redCenter, redLeft;
int greenRight, greenCenter, greenLeft;
int blueRight, blueCenter, blueLeft;

void setup() 
{
  Serial1.begin(9600);
  Serial1.println("Conexión lista");
  Serial.begin(19200);

  pinMode(redLightRight, OUTPUT);
  pinMode(greenLightRight, OUTPUT);
  pinMode(blueLightRight, OUTPUT);
  pinMode(redLightCenter, OUTPUT);
  pinMode(greenLightCenter, OUTPUT);
  pinMode(blueLightCenter, OUTPUT);
  pinMode(redLightLeft, OUTPUT);
  pinMode(greenLightLeft, OUTPUT);
  pinMode(blueLightLeft, OUTPUT);
}

void loop() 
{
  while (Serial1.available()>0)
    {
        char character = Serial1.read(); 
        dataReceived.concat(character);
        if (character == ':')
        {
            primeraCadena = getStringPartByNr(dataReceived, ';', 0);
            segundaCadena = getStringPartByNr(dataReceived, ';', 1);
            terceraCadena = getStringPartByNr(dataReceived, ';', 2);

            redRight = (getStringPartByNr(primeraCadena, ',', 0)).toInt();
            greenRight = (getStringPartByNr(primeraCadena, ',', 1)).toInt();
            blueRight = (getStringPartByNr(primeraCadena, ',', 2)).toInt();

            redCenter = (getStringPartByNr(segundaCadena, ',', 0)).toInt();
            greenCenter = (getStringPartByNr(segundaCadena, ',', 1)).toInt();
            blueCenter = (getStringPartByNr(segundaCadena, ',', 2)).toInt();

            redLeft = (getStringPartByNr(terceraCadena, ',', 0)).toInt();
            greenLeft = (getStringPartByNr(terceraCadena, ',', 1)).toInt();
            blueLeft = (getStringPartByNr(terceraCadena, ',', 2)).toInt();

            analogWrite(redLightRight, redRight);
            analogWrite(greenLightRight, greenRight);
            analogWrite(blueLightRight, blueRight);

            analogWrite(redLightCenter, redCenter);
            analogWrite(greenLightCenter, greenCenter);
            analogWrite(blueLightCenter, blueCenter);

            analogWrite(redLightLeft, redLeft);
            analogWrite(greenLightLeft, greenLeft);
            analogWrite(blueLightLeft, blueLeft);
            dataReceived = "";
        }
  }
}

String getStringPartByNr(String data, char separator, int index)
{
    int stringData = 0; 
    String dataPart = "";
    
    for(int i = 0; i<data.length(); i++) 
    {  
      if(data[i]==separator) 
      {
        stringData++;  
      }else if(stringData==index) 
      {
        dataPart.concat(data[i]); 
      }else if(stringData>index) 
      {
        return dataPart;
        break;
      }
    }
    return dataPart;
}

