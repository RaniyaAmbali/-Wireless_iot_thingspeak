#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

String channelID = " 3351986";

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected");
}

void loop() {

  HTTPClient http;

  String url = "http://api.thingspeak.com/channels/" + channelID + "/fields/1/last.txt";

  http.begin(url);
  int httpCode = http.GET();

  if (httpCode > 0) {
    String data = http.getString();

    // Convert 0/1 into ON/OFF
    if (data == "1") {
      Serial.println("Received: ON");
    } else if (data == "0") {
      Serial.println("Received: OFF");
    } else {
      Serial.println("Received: " + data);
    }
  }

  http.end();

   delay(5000);
}
  delay(5000);
}
