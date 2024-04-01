/*  Programa para ESP32 antes da atualização OTA */
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <Update.h>
#include <HTTPClient.h>

// const char* loginPage();
// const char* updatePage();
void updateSetup();
void updateLoop();
void StartUpdateServer();
void StopUpdateServer();
 
/* Constantes - conexão wi-fi e webserver */
const char* host = "DUP";
const char* ssid = "CACHORRO"; /* coloque aqui o nome da rede wi-fi que o ESP32 deve se conectar */
const char* password = "hi12345678"; /* coloque aqui a senha da rede wi-fi que o ESP32 deve se conectar */
 
/* Variáveis globais */
int contador_ms = 0;
 

 
/* Códigos da página que será aberta no browser 
   (quando comunicar via browser com o ESP32) 
   Esta página exigirá um login e senha, de modo que somente 
   quem tenha estas informações consiga atualizar o firmware 
   do ESP32 de forma OTA */
// const char* loginIndex = loginPage(); 
// const char* serverIndex = updatePage();

 
void setup(void) 
{
    Serial.begin(115200);
 
    /* Conecta-se a rede wi-fi */
    WiFi.begin(ssid, password);
    Serial.println("");
 
    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(500);
        Serial.print(".");
    }
     
    Serial.println("");
    Serial.print("Conectado a rede wi-fi ");
    Serial.println(ssid);
    Serial.print("IP obtido: ");
    Serial.println(WiFi.localIP());
 
    /* Usa MDNS para resolver o DNS */
    if (!MDNS.begin(host)) 
    { 
        //http://esp32.local
        Serial.println("Erro ao configurar mDNS. O ESP32 vai reiniciar em 1s...");
        delay(1000);
        ESP.restart();        
    }
   
    Serial.println("mDNS configurado e inicializado;");
   
    updateSetup();

    StartUpdateServer();

}
 
void loop(){

    updateLoop();
 
    contador_ms++;
 
    if (contador_ms >= 1000)
    {    
        Serial.print("Servidor online, acesse pelo IP: ");
        Serial.println(WiFi.localIP());
        Serial.println("Atualizado via PC");
        contador_ms = 0;
       
    }
}
