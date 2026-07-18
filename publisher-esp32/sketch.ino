#include <WiFi.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

String apiKey = "REE5PNPI5X10TZ5X";
const char* server = "api.thingspeak.com";

WiFiClient client;

int state = 0;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi");
}

void loop() {

  if (client.connect(server, 80)) {

    String value;

    
    if (state == 0) {
      value = "1";   // ON
      state = 1;
    } else {
      value = "0";   // OFF
      state = 0;
    }

    String url = "/update?api_key=" + apiKey + "&field1=" + value;

    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + server + "\r\n" +
                 "Connection: close\r\n\r\n");

    Serial.println("Sent: " + value);
  }

  delay(15000);
}
